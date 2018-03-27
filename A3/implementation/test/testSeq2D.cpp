#include "catch.h"

#include "Exceptions.h"
#include "Seq2D.h"
#include "DEM.h"

TEST_CASE("Seq2D()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {
        {1, 2, 3},
    };
    DEMT seq(s, 1.);
    REQUIRE_THROWS_AS(DEMT(s, .0), invalid_argument);
    REQUIRE_THROWS_AS(DEMT(s, -.1), invalid_argument);
    s = {};
    REQUIRE_THROWS_AS(DEMT(s, 1.), invalid_argument);
    s = {{}};
    REQUIRE_THROWS_AS(DEMT(s, 1.), invalid_argument);
    s = {{1, 2}, {3, 4, 5}};
    REQUIRE_THROWS_AS(DEMT(s, 1.), invalid_argument);
    s = {{3, 4, 5}, {1, 2}};
    REQUIRE_THROWS_AS(DEMT(s, 1.), invalid_argument);
}

TEST_CASE("Seq2D.set()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    seq.set(PointT(0, 0), 99);
    seq.set(PointT(2, 1), -99);
    REQUIRE_THROWS_AS(seq.set(PointT(-1, 0), 88), outside_bounds);
    REQUIRE_THROWS_AS(seq.set(PointT(0, -1), 88), outside_bounds);
    REQUIRE_THROWS_AS(seq.set(PointT(3, 0), 88), outside_bounds);
    REQUIRE_THROWS_AS(seq.set(PointT(0, 2), 88), outside_bounds);
}

TEST_CASE("Seq2D.get()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    REQUIRE(seq.get(PointT(0, 0)) == 1);
    REQUIRE(seq.get(PointT(1, 0)) == 2);
    REQUIRE(seq.get(PointT(2, 0)) == 3);
    REQUIRE(seq.get(PointT(0, 1)) == 4);
    REQUIRE(seq.get(PointT(1, 1)) == 5);
    REQUIRE(seq.get(PointT(2, 1)) == 6);
    REQUIRE_THROWS_AS(seq.get(PointT(-1, 0)), outside_bounds);
    REQUIRE_THROWS_AS(seq.get(PointT(0, -1)), outside_bounds);
    REQUIRE_THROWS_AS(seq.get(PointT(3, 0)), outside_bounds);
    REQUIRE_THROWS_AS(seq.get(PointT(0, 2)), outside_bounds);
}

TEST_CASE("Seq2D.getNumRow()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    REQUIRE(seq.getNumRow() == 2);
    s = {{1, 2}, {3, 4}, {5, 6}};
    seq = {s, 2.};
    REQUIRE(seq.getNumRow() == 3);
}

TEST_CASE("Seq2D.getNumCol()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    REQUIRE(seq.getNumCol() == 3);
    s = {{1, 2}, {3, 4}, {5, 6}};
    seq = {s, 2.};
    REQUIRE(seq.getNumCol() == 2);
}

TEST_CASE("Seq2D.getScale()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    REQUIRE(seq.getScale() == 1.);
    s = {{1, 2}, {3, 4}, {5, 6}};
    seq = {s, 2.};
    REQUIRE(seq.getScale() == 2.);
}

TEST_CASE("Seq2D.count(t)", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    REQUIRE(seq.count(0) == 0);
    REQUIRE(seq.count(1) == 1);
    REQUIRE(seq.count(2) == 1);
    REQUIRE(seq.count(3) == 1);
    REQUIRE(seq.count(4) == 1);
    REQUIRE(seq.count(5) == 1);
    REQUIRE(seq.count(6) == 1);
    REQUIRE(seq.count(7) == 0);
    s = {{1, 2, 1}, {2, 1, 2}};
    seq = {s, 1.};
    REQUIRE(seq.count(1) == 3);
    REQUIRE(seq.count(2) == 3);
}

TEST_CASE("Seq2D.count(l,t)", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    LineT l(PointT(0, 0), E, 3);
    REQUIRE(seq.count(l, 0) == 0);
    REQUIRE(seq.count(l, 1) == 1);
    REQUIRE(seq.count(l, 2) == 1);
    REQUIRE(seq.count(l, 3) == 1);
    REQUIRE(seq.count(l, 4) == 0);
    REQUIRE(seq.count(l, 5) == 0);
    REQUIRE(seq.count(l, 6) == 0);
    REQUIRE(seq.count(l, 7) == 0);
    l = {PointT(0, 0), E, 2};
    REQUIRE(seq.count(l, 3) == 0);
    l = {PointT(1, 1), S, 10};
    REQUIRE(seq.count(l, 1) == 0);
    REQUIRE(seq.count(l, 2) == 1);
    REQUIRE(seq.count(l, 3) == 0);
    REQUIRE(seq.count(l, 4) == 0);
    REQUIRE(seq.count(l, 5) == 1);
    REQUIRE(seq.count(l, 6) == 0);
}

TEST_CASE("Seq2D.count(pth,t)", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.);
    PathT pth(PointT(0, 0), E, 1);
    REQUIRE(seq.count(pth, 0) == 0);
    REQUIRE(seq.count(pth, 1) == 1);
    REQUIRE(seq.count(pth, 2) == 0);
    REQUIRE(seq.count(pth, 3) == 0);
    REQUIRE(seq.count(pth, 4) == 0);
    REQUIRE(seq.count(pth, 5) == 0);
    REQUIRE(seq.count(pth, 6) == 0);
    REQUIRE(seq.count(pth, 7) == 0);
    pth.append(E, 1);
    REQUIRE(seq.count(pth, 2) == 1);
    pth.append(N, 10);
    REQUIRE(seq.count(pth, 5) == 1);
    pth.append(W, 1);
    pth.append(S, 9);
    REQUIRE(seq.count(pth, 4) == 1);
}

TEST_CASE("Seq2D.length()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {{1, 2, 3}, {4, 5, 6}};
    DEMT seq(s, 1.25);
    PathT pth(PointT(-1, 0), E, 1);
    REQUIRE_THROWS_AS(seq.length(pth), invalid_argument);
    pth = {PointT(0, 0), E, 1};
    REQUIRE(seq.length(pth) == 1.25);
    pth.append(E, 1);
    REQUIRE(seq.length(pth) == 2.5);
    pth.append(N, 1);
    REQUIRE(seq.length(pth) == 3.75);
    pth.append(W, 1);
    REQUIRE(seq.length(pth) == 5.);
    pth.append(N, 1);
    REQUIRE_THROWS_AS(seq.length(pth), invalid_argument);
}

TEST_CASE("Seq2D.connected()", "[Seq2D]") {
    std::vector<std::vector<int>> s = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    DEMT seq(s, 1.25);
    REQUIRE_THROWS_AS( seq.connected(PointT(-1, 0), PointT(0, 0)), invalid_argument );
    REQUIRE_THROWS_AS( seq.connected(PointT(0, 0), PointT(4, 0)), invalid_argument );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(1, 1)) );
    REQUIRE_FALSE( seq.connected(PointT(1, 1), PointT(2, 2)) );
    REQUIRE_FALSE( seq.connected(PointT(2, 2), PointT(3, 3)) );
    s = {
        {1, 1, 3, 4},
        {5, 1, 7, 8},
        {8, 1, 10, 1},
        {12, 1, 1, 1}
    };
    seq = {s, 3.75};
    REQUIRE( seq.connected(PointT(0, 0), PointT(3, 2)) );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(3, 0)) );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(0, 1)) );
    s = {
        {1, 1, 1, 1},
        {5, 6, 1, 1},
        {1, 1, 10, 1},
        {1, 13, 1, 1}
    };
    seq = {s, 7.25};
    REQUIRE( seq.connected(PointT(0, 0), PointT(2, 3)) );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(1, 2)) );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(0, 2)) );
    REQUIRE_FALSE( seq.connected(PointT(0, 0), PointT(0, 3)) );
}
