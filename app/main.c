#include <stdio.h>
#include <math.h>

#include "myfunc.h"
#include "square.h"

int main()
{
    printf("Hello World!\n");

    double x1 = 0.0;
    double x2 = 0.0;
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    printf("%d\n", square(a, b, c, &x1, &x2));
    printf("%.4lf %.4lf", x1, x2);

    return myfunc(2);
}
