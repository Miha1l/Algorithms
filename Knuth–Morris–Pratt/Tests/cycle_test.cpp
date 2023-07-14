#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "../Sources/CycleShift.h"

TEST_CASE("Test cyclicShift"){
    std::string A1= "abcd";
    std::string B1 = "abcda";
    REQUIRE(cycleShift(A1, B1) == -1);

    std::string A2 = "aaaa";
    std::string B2 = "aaaa";
    REQUIRE(cycleShift(A2, B2) == 0);

    std::string A3 = "qwerty";
    std::string B3 = "zxcvbn";
    REQUIRE(cycleShift(A3, B3) == -1);

    std::string A4 = "ababa";
    std::string B4 = "baaba";
    REQUIRE(cycleShift(A4, B4) == 3);
}