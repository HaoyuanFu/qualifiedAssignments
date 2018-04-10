#include "catch.h"

#include "Cell.h"
#include "Exceptions.h"

TEST_CASE( "Cell()", "[Cell]" ) {
    Cell();
}

TEST_CASE( "Cell.empty()", "[Cell]" ) {
    Cell c;
    REQUIRE( c.empty() );
    c.acceptCard({Card::SH, Card::R2});
    REQUIRE_FALSE( c.empty() );
}

TEST_CASE( "Cell.getCard()", "[Cell]" ) {
    Cell cell;
    REQUIRE_THROWS_AS( cell.getCard(), emtpy_source );
    cell.acceptCard({Card::SH, Card::R2});
    Card c = cell.getCard();
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R2 );
}

TEST_CASE( "Card.chkAcceptCard()", "[Cell]" ) {
    Cell cell;
    REQUIRE( cell.chkAcceptCard({Card::SH, Card::R2}) );
    cell.acceptCard({Card::SH, Card::R2});
    REQUIRE_FALSE( cell.chkAcceptCard({Card::SS, Card::RJ}) );
}

TEST_CASE( "Card.acceptCard()", "[Cell]" ) {
    Cell cell;
    REQUIRE( cell.acceptCard({Card::SH, Card::R2}) );
    REQUIRE_FALSE( cell.acceptCard({Card::SS, Card::RJ}) );
    Card c = cell.getCard();
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R2 );
}

TEST_CASE( "Card.popCard()", "[Card]" ) {
    Cell cell;
    cell.acceptCard({Card::SH, Card::R2});
    REQUIRE_FALSE( cell.empty() );
    cell.popCard();
    REQUIRE( cell.empty() );
    cell.acceptCard({Card::SS, Card::RQ});
    REQUIRE_FALSE( cell.empty() );
    cell.popCard();
    REQUIRE( cell.empty() );
    REQUIRE_THROWS_AS( cell.popCard(), emtpy_source );
}
