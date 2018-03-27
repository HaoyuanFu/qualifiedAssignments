#include "catch.h"

#include "PathADT.h"
#include "Exceptions.h"

TEST_CASE( "PathT()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    PathT pth2(PointT(-3, -4), W, 7);
}

TEST_CASE( "PathT.append()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    pth.append(W, 5);
    REQUIRE_THROWS_AS( pth.append(E, 2), invalid_argument );
    pth.append(S, 2);
    pth.append(E, 4);
    REQUIRE_THROWS_AS( pth.append(E, 1), invalid_argument );
}

TEST_CASE( "PathT.strt()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    PointT p = pth.strt();
    REQUIRE( p.x() == 1 );
    REQUIRE( p.y() == 2 );
    pth = {PointT(-3, -4), W, 7};
    p = pth.strt();
    REQUIRE( p.x() == -3 );
    REQUIRE( p.y() == -4 );
}

TEST_CASE( "PathT.end()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    PointT p = pth.end();
    REQUIRE( p.x() == 1 );
    REQUIRE( p.y() == 4 );
    pth.append(E, 2);
    p = pth.end();
    REQUIRE( p.x() == 3 );
    REQUIRE( p.y() == 4 );
    pth.append(S, 3);
    p = pth.end();
    REQUIRE( p.x() == 3 );
    REQUIRE( p.y() == 1 );
    pth.append(W, 1);
    p = pth.end();
    REQUIRE( p.x() == 2 );
    REQUIRE( p.y() == 1 );
}

TEST_CASE( "PathT.line()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    pth.append(E, 1);
    pth.append(S, 3);
    pth.append(W, 4);

    REQUIRE_THROWS_AS(pth.line(4), outside_bounds);

    LineT l = pth.line(0);
    PointT p = l.strt();
    REQUIRE( p.x() == 1 );
    REQUIRE( p.y() == 2 );
    REQUIRE( l.orient() == N );
    REQUIRE( l.len() == 3 );
    l = pth.line(1);
    p = l.strt();
    REQUIRE( p.x() == 2 );
    REQUIRE( p.y() == 4 );
    REQUIRE( l.orient() == E );
    REQUIRE( l.len() == 1 );
    l = pth.line(2);
    p = l.strt();
    REQUIRE( p.x() == 2 );
    REQUIRE( p.y() == 3 );
    REQUIRE( l.orient() == S );
    REQUIRE( l.len() == 3 );
    l = pth.line(3);
    p = l.strt();
    REQUIRE( p.x() == 1 );
    REQUIRE( p.y() == 1 );
    REQUIRE( l.orient() == W );
    REQUIRE( l.len() == 4 );
}

TEST_CASE( "PathT.size()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    REQUIRE( pth.size() == 1 );
    pth.append(E, 1);
    REQUIRE( pth.size() == 2 );
    pth.append(S, 3);
    REQUIRE( pth.size() == 3 );
    pth.append(W, 4);
    REQUIRE( pth.size() == 4 );
}

TEST_CASE( "PathT.len()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    REQUIRE( pth.len() == 3 );
    pth.append(E, 1);
    REQUIRE( pth.len() == 4 );
    pth.append(S, 3);
    REQUIRE( pth.len() == 7 );
    pth.append(W, 4);
    REQUIRE( pth.len() == 11 );
}

TEST_CASE( "PathT.translate()", "[PathT]" ) {
    PathT pth(PointT(1, 2), N, 3);
    pth.append(E, 1);
    pth.append(S, 3);
    pth.append(W, 4);

    pth = pth.translate(-5, 1);

    LineT l = pth.line(0);
    PointT p = l.strt();
    REQUIRE( p.x() == -4 );
    REQUIRE( p.y() == 3 );
    REQUIRE( l.orient() == N );
    REQUIRE( l.len() == 3 );
    l = pth.line(1);
    p = l.strt();
    REQUIRE( p.x() == -3 );
    REQUIRE( p.y() == 5 );
    REQUIRE( l.orient() == E );
    REQUIRE( l.len() == 1 );
    l = pth.line(2);
    p = l.strt();
    REQUIRE( p.x() == -3 );
    REQUIRE( p.y() == 4 );
    REQUIRE( l.orient() == S );
    REQUIRE( l.len() == 3 );
    l = pth.line(3);
    p = l.strt();
    REQUIRE( p.x() == -4 );
    REQUIRE( p.y() == 2 );
    REQUIRE( l.orient() == W );
    REQUIRE( l.len() == 4 );
}
