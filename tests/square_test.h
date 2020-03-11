#ifndef SQUARE_TEST_H
#define SQUARE_TEST_H

#include <gtest/gtest.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>

extern "C" {
#include "square.h"
}

TEST(squareTest, positive) {

    /* Настройка чтения выходного потока */
    int outFd = open("temp/test1", O_WRONLY | O_CREAT);
    int oldOutput = dup(1);
    dup2(outFd, 1);

    /* Запуск функции */
    ASSERT_EQ(square(1, 5, 6), 2);

    /* Закрытие файла */
    close(outFd);
    dup2(oldOutput, 1);

    /* Считывание корней */
    double x1, x2;
    FILE *f;
    if ((f = fopen("temp/test1", "r")) == NULL)
        FAIL();
    fscanf(f, "%lf %lf", &x1, &x2);
    fclose(f);

    /* Проверка корней */
    ASSERT_DOUBLE_EQ(x1, -2.0);
    ASSERT_DOUBLE_EQ(x2, -3.0);
}

#endif // SQUARE_TEST_H
