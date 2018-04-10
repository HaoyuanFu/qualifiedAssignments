#include "catch.h"

#include "Pile.h"
#include "Exceptions.h"

TEST_CASE( "Pile()", "[Pile]" ) {
    Pile();
}

TEST_CASE( "Pile.empty()", "[Pile]" ) {
    Pile p;
    REQUIRE( p.empty() );
    p.assignCard({Card::SH, Card::R2});
    REQUIRE_FALSE( p.empty() );
}

TEST_CASE( "Pile.size()", "[Pile]" ) {
    Pile p;
    REQUIRE( p.size() == 0 );
    p.assignCard({Card::SH, Card::R2});
    REQUIRE( p.size() == 1 );
    p.assignCard({Card::SD, Card::R9});
    REQUIRE( p.size() == 2 );
}

TEST_CASE( "Pile.getCard()", "[Pile]" ) {
    Pile p;
    REQUIRE_THROWS_AS( p.getCard(0), emtpy_source );
    REQUIRE_THROWS_AS( p.getCard(1), emtpy_source );
    REQUIRE_THROWS_AS( p.getCard(-1), emtpy_source );
    p.assignCard({Card::SH, Card::R2});
    Card c = p.getCard(0);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R2 );
    REQUIRE_THROWS_AS( p.getCard(1), invalid_index );
    REQUIRE_THROWS_AS( p.getCard(-1), invalid_index );
    p.assignCard({Card::SD, Card::R8});
    c = p.getCard(1);
    REQUIRE( c.getSuit() == Card::SD );
    REQUIRE( c.getRank() == Card::R8 );
    REQUIRE_THROWS_AS( p.getCard(2), invalid_index );
    REQUIRE_THROWS_AS( p.getCard(-1), invalid_index );
}

TEST_CASE( "Pile.assignCard()", "[Pile]" ) {
    Pile p;
    p.assignCard({Card::SH, Card::R6});
    REQUIRE( p.size() == 1 );
    Card c = p.getCard(0);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R6 );
    p.assignCard({Card::SS, Card::R7});
    REQUIRE( p.size() == 2 );
    c = p.getCard(1);
    REQUIRE( c.getSuit() == Card::SS );
    REQUIRE( c.getRank() == Card::R7 );
    p.assignCard({Card::SD, Card::R7});
    REQUIRE( p.size() == 3 );
    c = p.getCard(2);
    REQUIRE( c.getSuit() == Card::SD );
    REQUIRE( c.getRank() == Card::R7 );
}

TEST_CASE( "Pile.chkAcceptCard()", "[Pile]" ) {
    Pile p;
    REQUIRE( p.chkAcceptCard({Card::SH, Card::R6}) );
    REQUIRE( p.chkAcceptCard({Card::SH, Card::R5}) );
    REQUIRE( p.chkAcceptCard({Card::SD, Card::R5}) );
    REQUIRE( p.chkAcceptCard({Card::SS, Card::R6}) );

    p.acceptCard({Card::SH, Card::R4});

    REQUIRE_FALSE( p.chkAcceptCard({Card::SH, Card::R3}) );
    REQUIRE_FALSE( p.chkAcceptCard({Card::SD, Card::R3}) );
    REQUIRE_FALSE( p.chkAcceptCard({Card::SS, Card::R4}) );
    REQUIRE_FALSE( p.chkAcceptCard({Card::SC, Card::R4}) );
    REQUIRE( p.chkAcceptCard({Card::SC, Card::R3}) );
}

TEST_CASE( "Pile.acceptCard()", "[Pile]" ) {
    Pile p;
    REQUIRE( p.acceptCard({Card::SH, Card::R6}) );
    REQUIRE( p.size() == 1 );

    REQUIRE_FALSE( p.acceptCard({Card::SH, Card::R5}) );
    REQUIRE_FALSE( p.acceptCard({Card::SD, Card::R5}) );
    REQUIRE_FALSE( p.acceptCard({Card::SS, Card::R6}) );
    REQUIRE_FALSE( p.acceptCard({Card::SC, Card::R6}) );
    REQUIRE( p.acceptCard({Card::SS, Card::R5}) );
    REQUIRE( p.size() == 2 );

    REQUIRE_FALSE( p.acceptCard({Card::SS, Card::R4}) );
    REQUIRE_FALSE( p.acceptCard({Card::SC, Card::R4}) );
    REQUIRE_FALSE( p.acceptCard({Card::SH, Card::R5}) );
    REQUIRE_FALSE( p.acceptCard({Card::SD, Card::R5}) );
    REQUIRE( p.acceptCard({Card::SH, Card::R4}) );
    REQUIRE( p.size() == 3 );

    REQUIRE_FALSE( p.acceptCard({Card::SH, Card::R3}) );
    REQUIRE_FALSE( p.acceptCard({Card::SD, Card::R3}) );
    REQUIRE_FALSE( p.acceptCard({Card::SS, Card::R4}) );
    REQUIRE_FALSE( p.acceptCard({Card::SC, Card::R4}) );
    REQUIRE( p.acceptCard({Card::SC, Card::R3}) );
    REQUIRE( p.size() == 4 );

    REQUIRE_FALSE( p.acceptCard({Card::SS, Card::R2}) );
    REQUIRE_FALSE( p.acceptCard({Card::SC, Card::R2}) );
    REQUIRE_FALSE( p.acceptCard({Card::SH, Card::R3}) );
    REQUIRE_FALSE( p.acceptCard({Card::SD, Card::R3}) );
    REQUIRE( p.acceptCard({Card::SD, Card::R2}) );
    REQUIRE( p.size() == 5 );
}

TEST_CASE( "Pile.popCard()", "[Pile]" ) {
    Pile p;
    p.assignCard({Card::SH, Card::R6});
    p.assignCard({Card::SS, Card::R7});
    p.assignCard({Card::SD, Card::R7});
    p.popCard();
    REQUIRE( p.size() == 2 );
    Card c = p.getCard(1);
    REQUIRE( c.getSuit() == Card::SS );
    REQUIRE( c.getRank() == Card::R7 );
    p.popCard();
    REQUIRE( p.size() == 1 );
    c = p.getCard(0);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R6 );
    p.popCard();
    REQUIRE( p.size() == 0 );
    REQUIRE_THROWS_AS( p.popCard(), emtpy_source );
}
