#ifndef SQUARE_TEST_H
#define SQUARE_TEST_H

#include <gtest/gtest.h>
#include <unistd.h>
#include <stdio.h>

extern "C" {
#include "square.h"
}

TEST(squareTest, positive) {
    int stdout_bk;

    stdout_bk = dup(fileno(stdout));

    int pipefd[2];
    pipe2(pipefd, 0);

    dup2(pipefd[1], fileno(stdout));

    ASSERT_EQ(square(1, 5, 6), 2);
    ASSERT_EQ(square(1, 2, 1), 1);
    ASSERT_EQ(square(1, 4, 5), 0);
    fflush(stdout);
    close(pipefd[1]);

    dup2(stdout_bk, fileno(stdout));

    char buf[512]; double x1, x2, x3;
    read(pipefd[0], buf, 512);
    sscanf(buf, "%lf %lf %lf", &x1, &x2, &x3);

    ASSERT_DOUBLE_EQ(x1, -2.0);
    ASSERT_DOUBLE_EQ(x2, -3.0);

    ASSERT_DOUBLE_EQ(x3, -1.0);
}

#endif // SQUARE_TEST_H
