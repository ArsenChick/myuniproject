#include "square.h"
#include <math.h>
#include <stdio.h>

int square(double a, double b, double c, double *x1, double *x2) {

    if (a == 0) {
        fprintf(stderr, "Passed arguments don't make a square equation!\n");
        return -1;
    }

    double d = b * b - 4 * a * c;

    if (d > 0) {
        *x1 = (-b + sqrt(d))/(2 * a);
        *x2 = (-b - sqrt(d))/(2 * a);
        return 2;
    }

    if (d == 0.0) {
        *x1 = (-b)/(2 * a);
        *x2 = *x1;
        return 1;
    }

    if (d < 0) {
        return 0;
    }

    return -2;

}
