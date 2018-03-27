#include "catch.h"

#include "PointADT.h"

TEST_CASE( "PointT()", "[PointT]" ) {
    PointT p(1, 2);
    PointT p2(-4, -1);
}

TEST_CASE( "PointT.x()", "[PointT]" ) {
    PointT p(1, 2);
    REQUIRE( p.x() == 1 );
    p = {-4, -1};
    REQUIRE( p.x() == -4 );
}

TEST_CASE( "PointT.y()", "[PointT]" ) {
    PointT p(1, 2);
    REQUIRE( p.y() == 2 );
    p = {-4, -1};
    REQUIRE( p.y() == -1 );
}

TEST_CASE( "PointT.translate()", "[PointT]" ) {
    PointT p(1, 2);
    p = p.translate(3, 4);
    REQUIRE( p.x() == 4 );
    REQUIRE( p.y() == 6 );
}
