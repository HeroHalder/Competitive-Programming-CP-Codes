#include <stdio.h>

int main()
{
    int N, i, sum = 0, score;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &score);
        sum += score;
    }

    printf("%d\n", sum);
    printf("%d\n", (sum + N / 2) / N);

    return 0;
}

