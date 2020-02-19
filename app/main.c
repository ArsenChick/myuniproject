#include <stdio.h>
#include <math.h>

#include "myfunc.h"
#include "square.h"

int main()
{
    printf("Hello World!\n");

    double a, b, c, x1, x2;
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("%d\n", square(a, b, c, &x1, &x2));
    printf("%lf %lf\n", x1, x2);

    return myfunc(2);
}
