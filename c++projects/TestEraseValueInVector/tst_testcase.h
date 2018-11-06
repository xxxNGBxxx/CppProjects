#pragma once
#include "erase.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(case_wo_2, SetTest1){
    VErase h8;
    std::vector<int> init = {1,5,3,9};
    std::vector<int> expec = {};
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}

TEST(case_with_2, SetTest2){
    VErase h8;
    std::vector<int> init = {1,2,3,8,9};
    std::vector<int> expec = {2,8};
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}
TEST(case_null_vector, SetTest3){
    VErase h8;
    std::vector<int> init;
    std::vector<int> expec;
    EXPECT_EQ(h8(init), h8(expec));
    ASSERT_THAT(0, Eq(0));
}
