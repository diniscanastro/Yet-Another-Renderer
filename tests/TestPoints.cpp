#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/point.cpp"

TEST_CASE("Point2DEquality"){
    Point2D point1(1,1);
    Point2D point2(1,1);

    CHECK(point1 == point2);
}

TEST_CASE("Point2DInequality"){
    Point2D point1(1,1);
    Point2D point2(2,1);

    CHECK(point1 != point2);
}

TEST_CASE("Point2DSum"){
    Point2D point1(1,1);
    Point2D point2(2,1);

    Point2D point3(3,2);

    CHECK((point1 + point2) == point3);
}

