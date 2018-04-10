#include "catch.h"

#include "Card.h"
#include "Exceptions.h"

TEST_CASE( "Card()", "[Card]" ) {
    Card(Card::SH, Card::R2);
}

TEST_CASE( "Card.getSuit()", "[Card]" ) {
    Card c(Card::SH, Card::R2);
    REQUIRE( c.getSuit() == Card::SH );
    c = {Card::SS, Card::RK};
    REQUIRE( c.getSuit() == Card::SS );
}

TEST_CASE( "Card.getRank()", "[Card]" ) {
    Card c(Card::SH, Card::R2);
    REQUIRE( c.getRank() == Card::R2 );
    c = {Card::SS, Card::RK};
    REQUIRE( c.getRank() == Card::RK );
}

TEST_CASE( "Card.sameColor()", "[Card]" ) {
    Card c1(Card::SH, Card::R2);
    Card c2(Card::SS, Card::RK);
    REQUIRE_FALSE( c1.sameColor(c2) );
    REQUIRE_FALSE( c2.sameColor(c1) );
    c2 = {Card::SH, Card::RJ};
    REQUIRE( c1.sameColor(c2) );
    REQUIRE( c2.sameColor(c1) );
    c2 = {Card::SD, Card::R7};
    REQUIRE( c1.sameColor(c2) );
    REQUIRE( c2.sameColor(c1) );
    c1 = {Card::SC, Card::R5};
    REQUIRE_FALSE( c1.sameColor(c2) );
    REQUIRE_FALSE( c2.sameColor(c1) );
    c2 = {Card::SC, Card::R10};
    REQUIRE( c1.sameColor(c2) );
    REQUIRE( c2.sameColor(c1) );
    c2 = {Card::SS, Card::R5};
    REQUIRE( c1.sameColor(c2) );
    REQUIRE( c2.sameColor(c1) );
}

TEST_CASE( "Card.smallerByOne()", "[Card]" ) {
    Card c1(Card::SH, Card::R2);
    Card c2(Card::SS, Card::R3);
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
    c1 = {Card::SD, Card::R4};
    REQUIRE( c2.smallerByOne(c1) );
    REQUIRE_FALSE( c1.smallerByOne(c2) );
    c2 = {Card::SC, Card::R5};
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
    c1 = {Card::SD, Card::R6};
    REQUIRE( c2.smallerByOne(c1) );
    REQUIRE_FALSE( c1.smallerByOne(c2) );
    c2 = {Card::SC, Card::R7};
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
    c1 = {Card::SD, Card::R8};
    REQUIRE( c2.smallerByOne(c1) );
    REQUIRE_FALSE( c1.smallerByOne(c2) );
    c2 = {Card::SC, Card::R9};
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
    c1 = {Card::SD, Card::R10};
    REQUIRE( c2.smallerByOne(c1) );
    REQUIRE_FALSE( c1.smallerByOne(c2) );
    c2 = {Card::SC, Card::RJ};
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
    c1 = {Card::SD, Card::RQ};
    REQUIRE( c2.smallerByOne(c1) );
    REQUIRE_FALSE( c1.smallerByOne(c2) );
    c2 = {Card::SC, Card::RK};
    REQUIRE( c1.smallerByOne(c2) );
    REQUIRE_FALSE( c2.smallerByOne(c1) );
}
