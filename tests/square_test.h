#ifndef SQUARE_TEST_H
#define SQUARE_TEST_H

#include <gtest/gtest.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

extern "C" {
#include "square.h"
}

TEST(squareTest, correctPos) {
    double x1 = 0.0;
    double x2 = 0.0;

    ASSERT_EQ(square(1, 5, 6, &x1, &x2), 2);
    ASSERT_DOUBLE_EQ(x1, -2.0);
    ASSERT_DOUBLE_EQ(x2, -3.0);
}

TEST(squareTest, correctZero) {
    double x1 = 0.0;
    double x2 = 0.0;

    ASSERT_EQ(square(1, 2, 1, &x1, &x2), 1);
    ASSERT_DOUBLE_EQ(x1, x2);
    ASSERT_DOUBLE_EQ(x1, -1.0);
}

TEST(squareTest, correctNeg) {
    double x1 = 0.0;
    double x2 = 0.0;

    ASSERT_EQ(square(1, 4, 5, &x1, &x2), 0);
    ASSERT_DOUBLE_EQ(x1, 0.0);
    ASSERT_DOUBLE_EQ(x2, 0.0);
}

TEST(squareTest, correctPosN) {
    double x1 = 0.0;
    double x2 = 0.0;

    ASSERT_EQ(square(-2, 5, 7, &x1, &x2), 2);
    ASSERT_DOUBLE_EQ(x1, -1.0);
    ASSERT_DOUBLE_EQ(x2, 3.5);
}

#endif // SQUARE_TEST_H
