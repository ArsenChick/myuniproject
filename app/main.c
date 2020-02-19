#include <stdio.h>
#include <math.h>

#include "myfunc.h"
#include "square.h"

int main()
{
    printf("Hello World!\n");

    double a, b, c, x1, x2;
    a = 1;
    b = 2;
    c = 1;
    square(a, b, c, &x1, &x2);

    return myfunc(2);
}
