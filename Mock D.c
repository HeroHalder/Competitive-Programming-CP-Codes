#include <stdio.h>

int main()
{
    int n, s, d, i;

    scanf("%d %d %d", &n, &s, &d);

    int price;

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &price);

        if (s >= price)
        {
            printf("%d\n", i);
            return 0;
        }

        s += d;
    }

    printf("-1\n");

    return 0;
}

