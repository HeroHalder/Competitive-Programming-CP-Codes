#include <stdio.h>

int main()
{
    int T;
    double S, area;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%lf", &S);

        area = (S * S) / 8;

        printf("%.2lf\n", area);
    }

    return 0;
}

