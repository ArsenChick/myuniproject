#ifndef SQUARE_TEST_H
#define SQUARE_TEST_H

#include <gtest/gtest.h>
#include <io.h>
#include <cstdio>

extern "C" {
#include "square.h"
}

TEST(squareTest, positive) {
    /* Настройка чтения выходного потока */
    int outFd = open(testOutputFile, O_RDWR | O_CREAT );
    int oldOutput = dup(stdout);
    dup2(outFd, stdout);

    /* Запуск функции */
    ASSERT_EQ(square(1, 5, 6), 2);
    /* Проверка корней */
    double x1, x2;
    fscanf(testOutputFile, "%lf %lf", &x1, &x2);
    ASSERT_EQ(x1, -2.0);
    ASSERT_EQ(x2, -3.0);

    /* Закрытие файла */

}

TEST(squareTest, eqzero) {

}

TEST(squareTest, negative) {

}

#endif // SQUARE_TEST_H
