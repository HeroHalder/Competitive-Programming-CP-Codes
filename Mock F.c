#include <stdio.h>

int main()
{
    int T, A, B;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d %d", &A, &B);

        if (A > B)
        {
            printf("A is larger\n");
        }
        else if (B > A)
        {
            printf("B is larger\n");
        }
        else
        {
            printf("Both are equal\n");
        }
    }

    return 0;
}

