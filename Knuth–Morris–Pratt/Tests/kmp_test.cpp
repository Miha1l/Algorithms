#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include "../Sources/KMP.h"

TEST_CASE("Test prefixFunction"){
    std::string str1 = "a";
    std::vector<int> pi1 = {0};
    REQUIRE(prefixFunction(str1) == pi1);

    std::string str2 = "abcdefg";
    std::vector<int> pi2 = {0, 0, 0, 0, 0, 0, 0};
    REQUIRE(prefixFunction(str2) == pi2);

    std::string str3 = "aaaaa";
    std::vector<int> pi3 = {0, 1, 2, 3, 4};
    REQUIRE(prefixFunction(str3) == pi3);

    std::string str4 = "abccba";
    std::vector<int> pi4 = {0, 0, 0, 0, 0, 1};
    REQUIRE(prefixFunction(str4) == pi4);

    std::string str5 = "abcdabcdabcd";
    std::vector<int> pi5 = {0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8};
    REQUIRE(prefixFunction(str5) == pi5);
}

TEST_CASE("Test KMP"){
    std::string P1 = "aa";
    std::string T1 = "aaaaa";
    std::vector<int> res1 = {0, 1, 2, 3};
    REQUIRE(kmp(P1, T1) == res1);

    std::string P2 = "abc";
    std::string T2 = "dfga";
    std::vector<int> res2 = {-1};
    REQUIRE(kmp(P2, T2) == res2);

    std::string P3 = "abcdf";
    std::string T3 = "abc";
    std::vector<int> res3 = {-1};
    REQUIRE(kmp(P3, T3) == res3);

    std::string P4 = "b";
    std::string T4 = "b";
    std::vector<int> res4 = {0};
    REQUIRE(kmp(P4, T4) == res4);
}