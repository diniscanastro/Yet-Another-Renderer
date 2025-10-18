#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "../src/point.cpp"

TEST_SUITE("Point2D") {
    TEST_CASE("Equality"){
        Point2D point1(1,1);
        SUBCASE("Points are equal") {
            CHECK(point1 == Point2D(1,1));
        }

        SUBCASE("Points are not equal") {
            CHECK(point1 != Point2D(2,1));
        }
    }

    TEST_CASE("Sum"){
        Point2D point1(1,1);
        Point2D point2(2,1);

        CHECK((point1 + point2) == Point2D(3,2));
    }

    TEST_CASE("Subtract"){
        Point2D point1(1,1);
        Point2D point2(2,1);

        CHECK((point1 - point2) == Point2D(-1,0));
    }

    TEST_CASE("Division"){
        Point2D point1(10,5);

        CHECK((point1 / 2) == Point2D(5,2.5));
    }

    TEST_CASE("Multiplication"){
        Point2D point1(2,3);
        SUBCASE("With scalar") {
            CHECK((point1 * 2) == Point2D(4,6));
        }

        SUBCASE("Dot product") {
            Point2D point2(2,-3);
            CHECK((point1 * point2) == -5.f);

            Point2D point3(3,4);
            CHECK((point1 * point3) == 18.f);
        }
    }

    TEST_CASE("Magnitude"){
        Point2D point1(1,0);
        CHECK(point1.magnitude() == 1.0f);

        Point2D point2(1,1);
        CHECK(point2.magnitude() == sqrt(2));
    }

    TEST_CASE("Angle"){
        Point2D point1(2,2);
        Point2D point2(2,0);

        CHECK(point1.angle(point2) == doctest::Approx(M_PI/4).epsilon(pow(10,-15)));

        Point2D point3(3,3);
        CHECK(point1.angle(point3) == doctest::Approx(0).epsilon(pow(10,-15)));

        Point2D point4(2,-2);
        CHECK(point1.angle(point4) == doctest::Approx(M_PI/2).epsilon(pow(10,-15)));
    }

    TEST_CASE("Normalize"){
        Point2D point1(1,0);
        CHECK(point1.normalize() == Point2D(1,0));

        Point2D point2(1,1);
        CHECK(point2.normalize() == Point2D(1/sqrt(2),1/sqrt(2)));

        Point2D point3(2,1);
        CHECK(point3.normalize() == Point2D(2/sqrt(5),1/sqrt(5)));
    }
}

TEST_SUITE("Point3D") {
    TEST_CASE("Equality"){
        Point3D point1(1,1, 2);
        SUBCASE("Points are equal") {
            CHECK(point1 == Point3D(1,1,2));
        }

        SUBCASE("Points are not equal") {
            CHECK(point1 != Point3D(2,1,3));
        }
    }

    TEST_CASE("Sum"){
        Point3D point1(1,1,2);
        Point3D point2(2,1,2);

        CHECK((point1 + point2) == Point3D(3,2,4));
    }

    TEST_CASE("Subtract"){
        Point3D point1(1,1,3);
        Point3D point2(2,1,2);

        CHECK((point1 - point2) == Point3D(-1,0,1));
    }

    TEST_CASE("Division"){
        Point3D point1(10,5,2);

        CHECK((point1 / 2) == Point3D(5,2.5,1));
    }

    TEST_CASE("Multiplication"){
        Point3D point1(2,3,1);
        SUBCASE("With scalar") {
            CHECK((point1 * 2) == Point3D(4,6,2));
        }

        SUBCASE("Dot product") {
            Point3D point2(2,-3,4);
            CHECK((point1 * point2) == -1.0);

            Point3D point3(3,4,1);
            CHECK((point1 * point3) == 19.0);
        }
    }

    TEST_CASE("Magnitude"){
        Point3D point1(1,0,0);
        CHECK(point1.magnitude() == 1.0f);

        Point3D point2(1,1,1);
        CHECK(point2.magnitude() == sqrt(3));
    }

    TEST_CASE("Angle"){
        Point3D point1(2,2, 1);
        Point3D point2(2,0, 1);

        CHECK(point1.angle(point2) == doctest::Approx(0.729).epsilon(pow(10,-2)));

        Point3D point3(4,4,2);
        CHECK(point1.angle(point3) == doctest::Approx(0).epsilon(pow(10,-15)));

        Point3D point4(-2,-2, -1);
        CHECK(point1.angle(point4) == doctest::Approx(M_PI).epsilon(pow(10,-15)));
    }

    TEST_CASE("Normalize"){
        Point3D point1(1,0,0);
        CHECK(point1.normalize() == Point3D(1,0,0));

        Point3D point2(1,1,1);
        CHECK(point2.normalize() == Point3D(1/sqrt(3),1/sqrt(3),1/sqrt(3)));

        Point3D point3(2,1,1);
        CHECK(point3.normalize() == Point3D(2/sqrt(6),1/sqrt(6),1/sqrt(6)));
    }
}




