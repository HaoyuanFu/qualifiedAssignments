#include "catch.h"

#include "LineADT.h"
#include "Exceptions.h"

TEST_CASE( "LineT()", "[LineT]" ) {
    LineT l(PointT(1, 2), N, 3);
    REQUIRE_THROWS_AS(LineT(PointT(1, 2), N, 0), invalid_argument);
}

TEST_CASE( "LineT.strt()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    PointT p = l.strt();
    REQUIRE( p.x() == -3 );
    REQUIRE( p.y() == -2 );
}

TEST_CASE( "LineT.end()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    PointT p = l.end();
    REQUIRE( p.x() == -7 );
    REQUIRE( p.y() == -2 );
    l = {PointT(8, 3), N, 2};
    p = l.end();
    REQUIRE( p.x() == 8 );
    REQUIRE( p.y() == 4 );
    l = {PointT(1, -4), E, 7};
    p = l.end();
    REQUIRE( p.x() == 7 );
    REQUIRE( p.y() == -4 );
    l = {PointT(-9, 6), S, 3};
    p = l.end();
    REQUIRE( p.x() == -9 );
    REQUIRE( p.y() == 4 );
}

TEST_CASE( "LineT.orient()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    REQUIRE( l.orient() == W );
    l = {PointT(8, 3), N, 2};
    REQUIRE( l.orient() == N );
    l = {PointT(1, -4), E, 7};
    REQUIRE( l.orient() == E );
    l = {PointT(-9, 6), S, 3};
    REQUIRE( l.orient() == S );
}

TEST_CASE( "LineT.len()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    REQUIRE( l.len() == 5 );
    l = {PointT(8, 3), N, 2};
    REQUIRE( l.len() == 2 );
    l = {PointT(1, -4), E, 7};
    REQUIRE( l.len() == 7 );
    l = {PointT(-9, 6), S, 3};
    REQUIRE( l.len() == 3 );
}

TEST_CASE( "LineT.flip()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    LineT l2 = l.flip();
    REQUIRE( l2.orient() == E );
    l = {PointT(8, 3), N, 2};
    l2 = l.flip();
    REQUIRE( l2.orient() == S );
    l = {PointT(1, -4), E, 7};
    l2 = l.flip();
    REQUIRE( l2.orient() == W );
    l = {PointT(-9, 6), S, 3};
    l2 = l.flip();
    REQUIRE( l2.orient() == N );
}

TEST_CASE( "LineT.rotate()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    l = l.rotate(CW);
    REQUIRE( l.orient() == N );
    l = l.rotate(CW);
    REQUIRE( l.orient() == E );
    l = l.rotate(CW);
    REQUIRE( l.orient() == S );
    l = l.rotate(CW);
    REQUIRE( l.orient() == W );
    l = l.rotate(CCW);
    REQUIRE( l.orient() == S );
    l = l.rotate(CCW);
    REQUIRE( l.orient() == E );
    l = l.rotate(CCW);
    REQUIRE( l.orient() == N );
    l = l.rotate(CCW);
    REQUIRE( l.orient() == W );
}

TEST_CASE( "LineT.translate()", "[LineT]" ) {
    LineT l(PointT(-3, -2), W, 5);
    l = l.translate(2, 5);
    PointT p = l.strt();
    REQUIRE( p.x() == -1 );
    REQUIRE( p.y() == 3 );
}
