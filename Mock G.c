#include <stdio.h>

int main()
{
    double a, b, c, missing;

    scanf("%lf %lf %lf", &a, &b, &c);

    missing = 4 * ((a + b + c) / 3) - (a + b + c);

    printf("%.4lf\n", missing);

    return 0;
}

