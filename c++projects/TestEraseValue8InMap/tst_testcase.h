#pragma once
#include <functorerasevalue8inmap.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(TestCaseWithout8, SetTestMapFunct){
    H8 h8;
    std::map<int,int> base {{1,2},{2,3},{1,9}};
    std::map<int,int> expec {{1,2},{2,3},{1,9}};
    EXPECT_EQ(h8(base), h8(expec));
    ASSERT_THAT(0, Eq(0));
}

TEST(TestCaseWith8, SetTestMapFunct){
    H8 h8;
    std::map<int,int> base {{1,2},{2,8},{4,8},{1,9}};
    std::map<int,int> expec {{1,2},{1,9}};
    EXPECT_EQ(h8(base), h8(expec));
    ASSERT_THAT(0, Eq(0));
}

TEST(TestCaseNullMap, SetTestMapFunct){
    H8 h8;
    std::map<int,int> base;
    std::map<int,int> expec;
    EXPECT_EQ(h8(base), h8(expec));
    ASSERT_THAT(0, Eq(0));
}

