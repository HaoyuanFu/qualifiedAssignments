/**
 * @file Mover.cpp
 * @author Harry Fu
 * @brief Provides the Mover class definition
 * @date 4/6/2018
 */

#include "Mover.h"

bool Mover::chkPileToPile(Pile& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);
    return d.chkAcceptCard(c);
}

bool Mover::pileToPile(Pile& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkPileToCell(Pile& s, Cell& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);
    return d.chkAcceptCard(c);
}

bool Mover::pileToCell(Pile& s, Cell& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkCellToPile(Cell& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard();
    return d.chkAcceptCard(c);
}

bool Mover::cellToPile(Cell& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard();

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkPileToFoundation(Pile& s, Foundation& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);
    return d.chkAcceptCard(c);
}

bool Mover::pileToFoundation(Pile& s, Foundation& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkFoundationToPile(Foundation& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);
    return d.chkAcceptCard(c);
}

bool Mover::foundationToPile(Foundation& s, Pile& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkCellToFoundation(Cell& s, Foundation& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard();
    return d.chkAcceptCard(c);
}

bool Mover::cellToFoundation(Cell& s, Foundation& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard();

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}

bool Mover::chkFoundationToCell(Foundation& s, Cell& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);
    return d.chkAcceptCard(c);
}

bool Mover::foundationToCell(Foundation& s, Cell& d) {
    if (s.empty()) {
        return false;
    }

    Card c = s.getCard(s.size() - 1);

    if (d.acceptCard(c)) {
        s.popCard();
        return true;
    }

    return false;
}