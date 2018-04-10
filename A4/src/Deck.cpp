/**
 * @file Deck.cpp
 * @author Harry Fu
 * @brief Provides the Deck class definition
 * @date 4/6/2018
 */

#include "Deck.h"
#include <algorithm>
#include <random>
#include "Exceptions.h"

using namespace std;

Deck::Deck() {
    for (int i = 0; i < NUM_C; ++i) {
        cs.push_back({});
    }
    for (int i = 0; i < NUM_F; ++i) {
        fs.push_back({});
    }
    for (int i = 0; i < NUM_P; ++i) {
        ps.push_back({});
    }
    dealCards();
}

Deck::Deck(const vector<Cell>& cs, const vector<Foundation>& fs,
           const vector<Pile>& ps)
    : cs(cs), fs(fs), ps(ps) {
    //
}

bool Deck::isPlayerWon() {
    for (int i = 0; i < NUM_P; ++i) {
        if (!ps[i].empty()) return false;
    }
    for (int i = 0; i < NUM_C; ++i) {
        if (!cs[i].empty()) return false;
    }
    return true;
}

bool Deck::hasValidMoves() {
    for (int si = 0; si < NUM_P; ++si) {
        for (int di = 0; di < NUM_P; ++di) {
            if (si != di && chkPileToPile(si, di)) {
                return true;
            }
        }
        for (int di = 0; di < NUM_C; ++di) {
            if (chkPileToCell(si, di)) {
                return true;
            }
        }
        for (int di = 0; di < NUM_F; ++di) {
            if (chkPileToFoundation(si, di)) {
                return true;
            }
        }
    }
    for (int si = 0; si < NUM_C; ++si) {
        for (int di = 0; di < NUM_P; ++di) {
            if (chkCellToPile(si, di)) {
                return true;
            }
        }
        for (int di = 0; di < NUM_F; ++di) {
            if (chkCellToFoundation(si, di)) {
                return true;
            }
        }
    }

    return false;
}

bool Deck::isCellEmpty(int i) {
    if (i < 0 || i > NUM_C - 1) {
        throw invalid_index();
    }
    return cs[i].empty();
}

bool Deck::isPileEmpty(int i) {
    if (i < 0 || i > NUM_P - 1) {
        throw invalid_index();
    }
    return ps[i].empty();
}

bool Deck::isFoundationEmpty(int i) {
    if (i < 0 || i > NUM_F - 1) {
        throw invalid_index();
    }
    return fs[i].empty();
}

unsigned Deck::getPileSize(int i) {
    if (i < 0 || i > NUM_P - 1) {
        throw invalid_index();
    }
    return ps[i].size();
}

unsigned Deck::getFoundationSize(int i) {
    if (i < 0 || i > NUM_F - 1) {
        throw invalid_index();
    }
    return fs[i].size();
}

Card Deck::getCardFromCell(int i) {
    if (i < 0 || i > NUM_C - 1) {
        throw invalid_index();
    }
    Cell& c = cs[i];
    return c.getCard();
}

Card Deck::getCardFromPile(int i, int j) {
    if (i < 0 || i > NUM_P - 1) {
        throw invalid_index();
    }
    Pile& p = ps[i];
    return p.getCard(j);
}

Card Deck::getCardFromFoundation(int i, int j) {
    if (i < 0 || i > NUM_F - 1) {
        throw invalid_index();
    }
    Foundation& f = fs[i];
    return f.getCard(j);
}

bool Deck::chkPileToPile(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_P - 1 || si == di) {
        throw invalid_index();
    }

    return m.chkPileToPile(ps[si], ps[di]);
}

bool Deck::pileToPile(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_P - 1 || si == di) {
        throw invalid_index();
    }

    return m.pileToPile(ps[si], ps[di]);
}

bool Deck::chkPileToCell(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_C - 1) {
        throw invalid_index();
    }

    return m.chkPileToCell(ps[si], cs[di]);
}

bool Deck::pileToCell(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_C - 1) {
        throw invalid_index();
    }

    return m.pileToCell(ps[si], cs[di]);
}

bool Deck::chkCellToPile(int si, int di) {
    if (si < 0 || si > NUM_C - 1 || di < 0 || di > NUM_P - 1) {
        throw invalid_index();
    }

    return m.chkCellToPile(cs[si], ps[di]);
}

bool Deck::cellToPile(int si, int di) {
    if (si < 0 || si > NUM_C - 1 || di < 0 || di > NUM_P - 1) {
        throw invalid_index();
    }

    return m.cellToPile(cs[si], ps[di]);
}

bool Deck::chkPileToFoundation(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_F - 1) {
        throw invalid_index();
    }

    return m.chkPileToFoundation(ps[si], fs[di]);
}

bool Deck::pileToFoundation(int si, int di) {
    if (si < 0 || si > NUM_P - 1 || di < 0 || di > NUM_F - 1) {
        throw invalid_index();
    }

    return m.pileToFoundation(ps[si], fs[di]);
}

bool Deck::chkCellToFoundation(int si, int di) {
    if (si < 0 || si > NUM_C - 1 || di < 0 || di > NUM_F - 1) {
        throw invalid_index();
    }

    return m.chkCellToFoundation(cs[si], fs[di]);
}

bool Deck::cellToFoundation(int si, int di) {
    if (si < 0 || si > NUM_C - 1 || di < 0 || di > NUM_F - 1) {
        throw invalid_index();
    }

    return m.cellToFoundation(cs[si], fs[di]);
}

void Deck::dealCards() {
    const vector<Card::Suits> ss = {Card::SC, Card::SD, Card::SH, Card::SS};
    const vector<Card::Ranks> rs = {
        Card::RA, Card::R2, Card::R3,  Card::R4, Card::R5, Card::R6, Card::R7,
        Card::R8, Card::R9, Card::R10, Card::RJ, Card::RQ, Card::RK};

    vector<Card> cards;

    for (auto it1 = ss.begin(); it1 != ss.end(); ++it1) {
        for (auto it2 = rs.begin(); it2 != rs.end(); ++it2) {
            cards.push_back(Card(*it1, *it2));
        }
    }

    auto rng = default_random_engine();
    shuffle(cards.begin(), cards.end(), rng);

    unsigned i = 0;
    for (auto it = cards.begin(); it != cards.end(); ++it) {
        Pile& p = ps[i++];
        p.assignCard(*it);
        if (i == NUM_P) {
            i = 0;
        }
    }
}