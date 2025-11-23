// GoogleTest-based unit tests for math_operations::add
#include <gtest/gtest.h>
#include "math_operations.h"

TEST(AdditionTests, PositiveNumbers) {
	EXPECT_EQ(3, add(1, 2));
}

TEST(AdditionTests, Zero) {
	EXPECT_EQ(0, add(0, 0));
}

TEST(AdditionTests, NegativeAndPositive) {
	EXPECT_EQ(-1, add(-3, 2));
}

TEST(AdditionTests, AnotherPositive) {
	EXPECT_EQ(5, add(2, 3));
}

TEST(AdditionTests, LargeValues) {
	EXPECT_EQ(2000000000, add(1000000000, 1000000000));
}

// Note: no main() here — the test executable is linked with GTest's
// main (GTest::gtest_main) in CMake so ctest/ctest discovery works.


