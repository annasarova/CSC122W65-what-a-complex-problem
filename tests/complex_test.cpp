#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/complex.hpp"

#include "catch2/catch_approx.hpp"

TEST_CASE("Constructor and getters work") {
    ComplexNumber num(5.0, 7.0);

    REQUIRE(num.real() == 5.0f);
    REQUIRE(num.imaginary() == 7.0f);
}

TEST_CASE("Addition works") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.add(b);

    REQUIRE(result.real() == 7.5f);
    REQUIRE(result.imaginary() == 10.1f);
}

TEST_CASE("Subtraction works") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.subtract(b);

    REQUIRE(result.real() == 2.5f);
    REQUIRE(result.imaginary() == 3.9f);
}

TEST_CASE("Negation works") {
    ComplexNumber a(5.0, 7.0);

    ComplexNumber result = a.negate();

    REQUIRE(result.real() == -5.0f);
    REQUIRE(result.imaginary() == -7.0f);
}

TEST_CASE("Conjugate works") {
    ComplexNumber a(5.0, 7.0);

    ComplexNumber result = a.conjugate();

    REQUIRE(result.real() == 5.0f);
    REQUIRE(result.imaginary() == -7.0f);
}

TEST_CASE("Multiplication works") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.multiply(b);

    REQUIRE(result.real() == Catch::Approx(-9.2f).epsilon(0.00001f));
    REQUIRE(result.imaginary() == Catch::Approx(33.0f).epsilon(0.00001f));

}

TEST_CASE("Division works") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.divide(b);

    REQUIRE(result.real() == Catch::Approx(2.15637f).epsilon(0.00001f));
    REQUIRE(result.imaginary() == Catch::Approx(0.126103f).epsilon(0.00001f));
}

TEST_CASE("Magnitude works") {
    ComplexNumber a(5.0, 7.0);

    float result = a.magnitude();

    REQUIRE(result == Catch::Approx(8.60233f).epsilon(0.00001f));
}

TEST_CASE("Phase works") {
    ComplexNumber a(5.0, 7.0);

    float result = a.phase();

    REQUIRE(result == Catch::Approx(0.62025f).epsilon(0.00001f));
}
TEST_CASE("Operations do not modify originals") {
    ComplexNumber a(5.0, 7.0);
    ComplexNumber b(2.5, 3.1);

    ComplexNumber result = a.add(b);

    REQUIRE(a.real() == 5.0f);
    REQUIRE(a.imaginary() == 7.0f);

    REQUIRE(b.real() == 2.5f);
    REQUIRE(b.imaginary() == 3.1f);
}
