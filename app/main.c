#include <stdio.h>
#include <math.h>

#include "myfunc.h"
#include "square.h"

int main()
{
    printf("Hello World!\n");

    double x1, x2;
    printf("%d\n", square(1, 2, 1, &x1, &x2));
    printf("%lf %lf\n", x1, x2);

    return myfunc(2);
}
