#include "catch.h"

#include "Deck.h"
#include "Exceptions.h"

TEST_CASE( "Valid/Invalid move b/w columns", "[Deck]" ) {
    std::vector<Pile> ps = {{}, {}, {}, {}, {}, {}, {}, {}};
    
    Deck d({{}, {}, {}, {}}, {{}, {}, {}, {}}, ps);

    REQUIRE_FALSE(d.pileToPile(0, 1));
    REQUIRE_FALSE(d.pileToPile(3, 2));
    REQUIRE_FALSE(d.pileToPile(6, 5));

    ps[0].assignCard({Card::SH, Card::R2});
    ps[3].assignCard({Card::SC, Card::R10});
    ps[6].assignCard({Card::SS, Card::RQ});

    Deck d2({{}, {}, {}, {}}, {{}, {}, {}, {}}, ps);

    REQUIRE_FALSE(d2.pileToPile(1, 0));
    REQUIRE_FALSE(d2.pileToPile(2, 3));
    REQUIRE_FALSE(d2.pileToPile(5, 6));
    REQUIRE(d2.pileToPile(0, 1));
    REQUIRE(d2.pileToPile(3, 2));
    REQUIRE(d2.pileToPile(6, 5));

    ps[1].assignCard({Card::SH, Card::RA});
    ps[2].assignCard({Card::SC, Card::R6});
    ps[4].assignCard({Card::SD, Card::R10});
    ps[5].assignCard({Card::SH, Card::R3});
    ps[7].assignCard({Card::SS, Card::R8});

    Deck d3({{}, {}, {}, {}}, {{}, {}, {}, {}}, ps);

    REQUIRE_FALSE(d3.pileToPile(0, 1));
    REQUIRE_FALSE(d3.pileToPile(3, 2));
    REQUIRE_FALSE(d3.pileToPile(6, 5));

    ps[1].assignCard({Card::SC, Card::R3});
    ps[2].assignCard({Card::SD, Card::RJ});
    ps[5].assignCard({Card::SH, Card::RK});

    Deck d4({{}, {}, {}, {}}, {{}, {}, {}, {}}, ps);

    REQUIRE(d4.pileToPile(0, 1));
    REQUIRE(d4.pileToPile(3, 2));
    REQUIRE(d4.pileToPile(6, 5));
}

TEST_CASE( "Moving to free cell", "[Deck]" ) {
    std::vector<Cell> cs = {{}, {}, {}, {}};
    std::vector<Pile> ps = {{}, {}, {}, {}, {}, {}, {}, {}};
    
    Deck d(cs, {{}, {}, {}, {}}, ps);

    REQUIRE_FALSE(d.pileToCell(0, 0));
    REQUIRE_FALSE(d.pileToCell(3, 1));
    REQUIRE_FALSE(d.pileToCell(5, 2));
    REQUIRE_FALSE(d.pileToCell(6, 3));

    ps[0].assignCard({Card::SH, Card::R2});
    ps[3].assignCard({Card::SC, Card::R10});
    ps[5].assignCard({Card::SD, Card::R4});
    ps[6].assignCard({Card::SS, Card::RQ});

    Deck d2(cs, {{}, {}, {}, {}}, ps);

    REQUIRE(d2.pileToCell(0, 0));
    REQUIRE(d2.pileToCell(3, 1));
    REQUIRE(d2.pileToCell(5, 2));
    REQUIRE(d2.pileToCell(6, 3));

    ps[0].assignCard({Card::SD, Card::R3});
    ps[3].assignCard({Card::SC, Card::RJ});
    ps[5].assignCard({Card::SS, Card::R7});
    ps[6].assignCard({Card::SH, Card::R8});

    REQUIRE_FALSE(d.pileToCell(0, 0));
    REQUIRE_FALSE(d.pileToCell(3, 1));
    REQUIRE_FALSE(d.pileToCell(5, 2));
    REQUIRE_FALSE(d.pileToCell(6, 3));
}

TEST_CASE( "Detecting winning game board", "[Deck]" ) {
    std::vector<Cell> cs = {{}, {}, {}, {}};
    std::vector<Pile> ps = {{}, {}, {}, {}, {}, {}, {}, {}};

    ps[0].assignCard({Card::SD, Card::R2});
    ps[0].assignCard({Card::SD, Card::RA});
    ps[3].assignCard({Card::SC, Card::R3});
    ps[3].assignCard({Card::SC, Card::R2});
    ps[3].assignCard({Card::SC, Card::RA});

    Deck d(cs, {{}, {}, {}, {}}, ps);

    REQUIRE_FALSE(d.isPlayerWon());

    d.pileToCell(0, 0);
    d.pileToCell(3, 3);

    REQUIRE_FALSE(d.isPlayerWon());

    d.cellToFoundation(0, 0);
    d.cellToFoundation(3, 3);

    REQUIRE_FALSE(d.isPlayerWon());

    d.pileToFoundation(0, 0);
    d.pileToFoundation(3, 3);

    REQUIRE_FALSE(d.isPlayerWon());

    d.pileToFoundation(3, 3);

    REQUIRE(d.isPlayerWon());
}

TEST_CASE( "Detecting no valid moves", "[Deck]" ) {
    std::vector<Cell> cs = {{}, {}, {}, {}};
    std::vector<Foundation> fs = {{}, {}, {}, {}};
    std::vector<Pile> ps = {{}, {}, {}, {}, {}, {}, {}, {}};

    cs[0].acceptCard({Card::SH, Card::R9});
    cs[1].acceptCard({Card::SC, Card::R8});
    cs[2].acceptCard({Card::SD, Card::R10});
    cs[3].acceptCard({Card::SS, Card::R3});

    fs[0].acceptCard({Card::SD, Card::RA});
    fs[0].acceptCard({Card::SD, Card::R2});
    fs[1].acceptCard({Card::SH, Card::RA});
    fs[2].acceptCard({Card::SC, Card::RA});

    ps[0].assignCard({Card::SH, Card::R6});
    ps[1].assignCard({Card::SD, Card::RK});
    ps[2].assignCard({Card::SH, Card::R10});
    ps[2].assignCard({Card::SC, Card::R4});
    ps[2].assignCard({Card::SH, Card::R2});
    ps[3].assignCard({Card::SD, Card::R5});
    ps[4].assignCard({Card::SH, Card::RJ});
    ps[5].assignCard({Card::SD, Card::R6});
    ps[6].assignCard({Card::SD, Card::RQ});
    ps[7].assignCard({Card::SS, Card::R2});

    Deck d(cs, fs, ps);

    REQUIRE(d.hasValidMoves());

    d.pileToFoundation(2, 1);

    REQUIRE(d.hasValidMoves());

    d.pileToPile(2, 3);

    REQUIRE_FALSE(d.hasValidMoves());

    std::vector<Cell> cs2 = {{}, {}, {}, {}};
    std::vector<Foundation> fs2 = {{}, {}, {}, {}};
    std::vector<Pile> ps2 = {{}, {}, {}, {}, {}, {}, {}, {}};

    cs2[0].acceptCard({Card::SC, Card::R4});
    cs2[2].acceptCard({Card::SC, Card::R2});

    fs2[2].acceptCard({Card::SD, Card::RA});
    fs2[2].acceptCard({Card::SD, Card::R2});
    fs2[3].acceptCard({Card::SH, Card::RA});

    ps2[0].assignCard({Card::SH, Card::R7});
    ps2[1].assignCard({Card::SH, Card::R9});
    ps2[2].assignCard({Card::SC, Card::R9});
    ps2[2].assignCard({Card::SD, Card::R5});
    ps2[2].assignCard({Card::SD, Card::R10});
    ps2[3].assignCard({Card::SD, Card::RK});
    ps2[4].assignCard({Card::SD, Card::R7});
    ps2[5].assignCard({Card::SC, Card::R7});
    ps2[6].assignCard({Card::SH, Card::RJ});
    ps2[7].assignCard({Card::SD, Card::R9});

    Deck d2(cs2, fs2, ps2);

    REQUIRE(d2.hasValidMoves());

    REQUIRE(d2.pileToCell(2, 1));

    REQUIRE(d2.hasValidMoves());

    REQUIRE(d2.pileToCell(2, 3));

    REQUIRE_FALSE(d2.hasValidMoves());
}
