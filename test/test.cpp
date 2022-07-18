#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <uparse/uparse.hpp>


TEST_SUITE("uparse") {
    
    SCENARIO("Parsing valid int32_t") {
        auto const target = uparse::parse<std::int32_t>("-1");
        REQUIRE(!!target);
        REQUIRE_EQ(*target, -1);
    }
    
    
    SCENARIO("Parsing invalid int32_t") {
        auto const target = uparse::parse<std::int32_t>("X");
        REQUIRE(!target);
    }
    
    
    SCENARIO("Parsing valid double") {
        auto const target = uparse::parse<double>("-1.e+1");
        REQUIRE(!!target);
        REQUIRE_EQ(*target, -10.0);
    }
    
    
    SCENARIO("Parsing invalid double") {
        auto const target = uparse::parse<double>("X");
        REQUIRE(!target);
    }
}
