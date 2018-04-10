#include "catch.h"

#include "Mover.h"
#include "Exceptions.h"

static Mover m;

TEST_CASE( "Mover()", "[Mover]" ) {
    Mover();
}

TEST_CASE( "Mover.chkPileToPile()", "[Mover]" ) {
    Pile s;
    Pile d;
    REQUIRE_FALSE( m.chkPileToPile(s, d) );
    s.assignCard({Card::SC, Card::R8});
    REQUIRE( m.chkPileToPile(s, d) );
    m.pileToPile(s, d);
    s.assignCard({Card::SC, Card::R7});
    REQUIRE_FALSE( m.chkPileToPile(s, d) );
}

TEST_CASE( "Mover.pileToPile()", "[Mover]" ) {
    Pile s;
    Pile d;
    REQUIRE_FALSE( m.pileToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.assignCard({Card::SC, Card::R8});
    REQUIRE( m.pileToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.size() == 1 );

    s.assignCard({Card::SC, Card::R7});
    REQUIRE_FALSE( m.pileToPile(s, d) );
    REQUIRE( s.size() == 1 );
    REQUIRE( d.size() == 1 );

    s.assignCard({Card::SD, Card::R8});
    REQUIRE_FALSE( m.pileToPile(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 1 );

    s.assignCard({Card::SD, Card::R7});
    REQUIRE( m.pileToPile(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 2 );
}

TEST_CASE( "Mover.chkPileToCell()", "[Mover]" ) {
    Pile s;
    Cell d;
    REQUIRE_FALSE( m.chkPileToCell(s, d) );
    s.acceptCard({Card::SD, Card::R7});
    REQUIRE( m.chkPileToCell(s, d) );
    m.pileToCell(s, d);
    s.acceptCard({Card::SS, Card::R3});
    REQUIRE_FALSE( m.chkPileToCell(s, d) );
}

TEST_CASE( "Mover.pileToCell()", "[Mover]" ) {
    Pile s;
    Cell d;
    REQUIRE_FALSE( m.pileToCell(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.acceptCard({Card::SD, Card::R7});
    REQUIRE( m.pileToCell(s, d) );
    REQUIRE( s.empty() );
    REQUIRE_FALSE( d.empty() );

    s.acceptCard({Card::SS, Card::R3});
    REQUIRE_FALSE( m.pileToCell(s, d) );
    REQUIRE( s.size() == 1 );
    REQUIRE_FALSE( d.empty() );
}

TEST_CASE( "Mover.chkCellToPile()", "[Mover]" ) {
    Cell s;
    Pile d;
    REQUIRE_FALSE( m.chkCellToPile(s, d) );
    s.acceptCard({Card::SC, Card::R8});
    REQUIRE( m.chkCellToPile(s, d) );
    m.cellToPile(s, d);
    s.acceptCard({Card::SC, Card::R7});
    REQUIRE_FALSE( m.chkCellToPile(s, d) );
}

TEST_CASE( "Mover.cellToPile()", "[Mover]" ) {
    Cell s;
    Pile d;
    REQUIRE_FALSE( m.cellToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.acceptCard({Card::SC, Card::R8});
    REQUIRE( m.cellToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.size() == 1 );

    s.acceptCard({Card::SC, Card::R7});
    REQUIRE_FALSE( m.cellToPile(s, d) );
    REQUIRE_FALSE( s.empty() );
    REQUIRE( d.size() == 1 );
    s.popCard();

    s.acceptCard({Card::SD, Card::R8});
    REQUIRE_FALSE( m.cellToPile(s, d) );
    REQUIRE_FALSE( s.empty() );
    REQUIRE( d.size() == 1 );
    s.popCard();

    s.acceptCard({Card::SD, Card::R7});
    REQUIRE( m.cellToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.size() == 2 );
}

TEST_CASE( "Mover.chkPileToFoundation()", "[Mover]" ) {
    Pile s;
    Foundation d;
    REQUIRE_FALSE( m.chkPileToFoundation(s, d) );
    s.assignCard({Card::SC, Card::R8});
    REQUIRE_FALSE( m.chkPileToFoundation(s, d) );
    s.assignCard({Card::SS, Card::RA});
    REQUIRE( m.chkPileToFoundation(s, d) );
    m.pileToFoundation(s, d);
    s.assignCard({Card::SC, Card::R2});
    REQUIRE_FALSE( m.chkPileToFoundation(s, d) );
}

TEST_CASE( "Mover.pileToFoundation()", "[Mover]" ) {
    Pile s;
    Foundation d;
    REQUIRE_FALSE( m.pileToFoundation(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.assignCard({Card::SC, Card::R8});
    REQUIRE_FALSE( m.pileToFoundation(s, d) );
    REQUIRE( s.size() == 1 );
    REQUIRE( d.empty() );

    s.assignCard({Card::SS, Card::RA});
    REQUIRE( m.pileToFoundation(s, d) );
    REQUIRE( s.size() == 1 );
    REQUIRE( d.size() == 1 );

    s.assignCard({Card::SC, Card::R2});
    REQUIRE_FALSE( m.pileToFoundation(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 1 );

    s.assignCard({Card::SS, Card::R2});
    REQUIRE( m.pileToFoundation(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 2 );
}

TEST_CASE( "Mover.chkFoundationToPile()", "[Mover]" ) {
    Foundation s;
    Foundation s2;
    Pile d;
    Pile d2;
    REQUIRE_FALSE( m.chkFoundationToPile(s, d) );
    s.acceptCard({Card::SS, Card::RA});
    s.acceptCard({Card::SS, Card::R2});
    s.acceptCard({Card::SS, Card::R3});
    s2.acceptCard({Card::SD, Card::RA});
    s2.acceptCard({Card::SD, Card::R2});
    s2.acceptCard({Card::SD, Card::R3});
    REQUIRE( m.chkFoundationToPile(s, d) );
    m.foundationToPile(s, d);
    REQUIRE_FALSE( m.chkFoundationToPile(s, d) );
}

TEST_CASE( "Mover.foundationToPile()", "[Mover]" ) {
    Foundation s;
    Foundation s2;
    Pile d;
    Pile d2;
    REQUIRE_FALSE( m.foundationToPile(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( s2.empty() );
    REQUIRE( d.empty() );
    REQUIRE( d2.empty() );

    s.acceptCard({Card::SS, Card::RA});
    s.acceptCard({Card::SS, Card::R2});
    s.acceptCard({Card::SS, Card::R3});
    s2.acceptCard({Card::SD, Card::RA});
    s2.acceptCard({Card::SD, Card::R2});
    s2.acceptCard({Card::SD, Card::R3});

    REQUIRE( m.foundationToPile(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 1 );

    REQUIRE_FALSE( m.foundationToPile(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE( d.size() == 1 );

    REQUIRE( m.foundationToPile(s2, d2) );
    REQUIRE( s2.size() == 2 );
    REQUIRE( d2.size() == 1 );

    REQUIRE_FALSE( m.foundationToPile(s2, d2) );
    REQUIRE( s2.size() == 2 );
    REQUIRE( d2.size() == 1 );

    REQUIRE( m.foundationToPile(s, d2) );
    REQUIRE( s.size() == 1 );
    REQUIRE( d2.size() == 2 );

    REQUIRE( m.foundationToPile(s2, d) );
    REQUIRE( s2.size() == 1 );
    REQUIRE( d.size() == 2 );
}

TEST_CASE( "Mover.chkCellToFoundation()", "[Mover]" ) {
    Cell s;
    Foundation d;
    REQUIRE_FALSE( m.chkCellToFoundation(s, d) );
    s.acceptCard({Card::SS, Card::R5});
    REQUIRE_FALSE( m.chkCellToFoundation(s, d) );
    s.popCard();
    s.acceptCard({Card::SS, Card::RA});
    REQUIRE( m.chkCellToFoundation(s, d) );
}

TEST_CASE( "Mover.cellToFoundation()", "[Mover]" ) {
    Cell s;
    Foundation d;
    REQUIRE_FALSE( m.cellToFoundation(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.acceptCard({Card::SS, Card::R5});
    REQUIRE_FALSE( m.cellToFoundation(s, d) );
    REQUIRE_FALSE( s.empty() );
    REQUIRE( d.empty() );
    s.popCard();

    s.acceptCard({Card::SS, Card::RA});
    REQUIRE( m.cellToFoundation(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.size() == 1 );
}

TEST_CASE( "Mover.chkFoundationToCell()", "[Mover]" ) {
    Foundation s;
    Cell d;
    REQUIRE_FALSE( m.chkFoundationToCell(s, d) );
    s.acceptCard({Card::SS, Card::RA});
    s.acceptCard({Card::SS, Card::R2});
    s.acceptCard({Card::SS, Card::R3});
    REQUIRE( m.chkFoundationToCell(s, d) );
    m.foundationToCell(s, d);
    REQUIRE_FALSE( m.chkFoundationToCell(s, d) );
}

TEST_CASE( "Mover.foundationToCell()", "[Mover]" ) {
    Foundation s;
    Cell d;
    REQUIRE_FALSE( m.foundationToCell(s, d) );
    REQUIRE( s.empty() );
    REQUIRE( d.empty() );

    s.acceptCard({Card::SS, Card::RA});
    s.acceptCard({Card::SS, Card::R2});
    s.acceptCard({Card::SS, Card::R3});

    REQUIRE( m.foundationToCell(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE_FALSE( d.empty() );

    REQUIRE_FALSE( m.foundationToCell(s, d) );
    REQUIRE( s.size() == 2 );
    REQUIRE_FALSE( d.empty() );
}
