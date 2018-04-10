#include "catch.h"

#include "Foundation.h"
#include "Exceptions.h"

TEST_CASE( "Foundation()", "[Foundation]" ) {
    Foundation();
}

TEST_CASE( "Foundation.empty()", "[Foundation]" ) {
    Foundation f;
    REQUIRE( f.empty() );
    f.acceptCard({Card::SH, Card::RA});
    REQUIRE_FALSE( f.empty() );
}

TEST_CASE( "Foundation.size()", "[Foundation]" ) {
    Foundation f;
    REQUIRE( f.size() == 0 );
    f.acceptCard({Card::SH, Card::RA});
    REQUIRE( f.size() == 1 );
    f.acceptCard({Card::SH, Card::R2});
    REQUIRE( f.size() == 2 );
}

TEST_CASE( "Foundation.getCard()", "[Foundation]" ) {
    Foundation f;
    REQUIRE_THROWS_AS( f.getCard(0), emtpy_source );
    REQUIRE_THROWS_AS( f.getCard(1), emtpy_source );
    REQUIRE_THROWS_AS( f.getCard(-1), emtpy_source );
    f.acceptCard({Card::SH, Card::RA});
    Card c = f.getCard(0);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::RA );
    REQUIRE_THROWS_AS( f.getCard(1), invalid_index );
    REQUIRE_THROWS_AS( f.getCard(-1), invalid_index );
    f.acceptCard({Card::SH, Card::R2});
    c = f.getCard(1);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R2 );
    REQUIRE_THROWS_AS( f.getCard(2), invalid_index );
    REQUIRE_THROWS_AS( f.getCard(-1), invalid_index );
}

TEST_CASE( "Foundation.chkAcceptCard()", "[Foundation]" ) {
    Foundation f;
    REQUIRE_FALSE( f.chkAcceptCard({Card::SH, Card::R2}) );
    REQUIRE_FALSE( f.chkAcceptCard({Card::SH, Card::R3}) );
    REQUIRE( f.chkAcceptCard({Card::SH, Card::RA}) );

    f.acceptCard({Card::SH, Card::RA});

    REQUIRE_FALSE( f.chkAcceptCard({Card::SH, Card::RA}) );
    REQUIRE_FALSE( f.chkAcceptCard({Card::SD, Card::R2}) );
    REQUIRE_FALSE( f.chkAcceptCard({Card::SS, Card::R2}) );
    REQUIRE_FALSE( f.chkAcceptCard({Card::SC, Card::R2}) );
    REQUIRE( f.chkAcceptCard({Card::SH, Card::R2}) );
}

TEST_CASE( "Foundation.acceptCard()", "[Foundation]" ) {
    Foundation f;
    REQUIRE_FALSE( f.acceptCard({Card::SH, Card::R2}) );
    REQUIRE_FALSE( f.acceptCard({Card::SH, Card::R3}) );
    REQUIRE( f.acceptCard({Card::SH, Card::RA}) );
    REQUIRE( f.size() == 1 );

    REQUIRE_FALSE( f.acceptCard({Card::SH, Card::RA}) );
    REQUIRE_FALSE( f.acceptCard({Card::SD, Card::R2}) );
    REQUIRE_FALSE( f.acceptCard({Card::SS, Card::R2}) );
    REQUIRE_FALSE( f.acceptCard({Card::SC, Card::R2}) );
    REQUIRE( f.acceptCard({Card::SH, Card::R2}) );
    REQUIRE( f.size() == 2 );

    REQUIRE_FALSE( f.acceptCard({Card::SH, Card::R2}) );
    REQUIRE_FALSE( f.acceptCard({Card::SD, Card::R3}) );
    REQUIRE_FALSE( f.acceptCard({Card::SS, Card::R3}) );
    REQUIRE_FALSE( f.acceptCard({Card::SC, Card::R3}) );
    REQUIRE( f.acceptCard({Card::SH, Card::R3}) );
    REQUIRE( f.size() == 3 );
}

TEST_CASE( "Foundation.popCard()", "[Foundation]" ) {
    Foundation f;
    f.acceptCard({Card::SH, Card::RA});
    f.acceptCard({Card::SH, Card::R2});
    f.acceptCard({Card::SH, Card::R3});
    f.popCard();
    REQUIRE( f.size() == 2 );
    Card c = f.getCard(1);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::R2 );
    f.popCard();
    REQUIRE( f.size() == 1 );
    c = f.getCard(0);
    REQUIRE( c.getSuit() == Card::SH );
    REQUIRE( c.getRank() == Card::RA );
    f.popCard();
    REQUIRE( f.size() == 0 );
    REQUIRE_THROWS_AS( f.popCard(), emtpy_source );
}
