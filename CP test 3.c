#include <stdio.h>
#include <string.h>

int main()
{
    char T[1001], P[1001];
    scanf("%s", T);
    scanf("%s", P);

    if (strstr(T, P) != NULL)
    {
        printf("Love Found\n");
    }
    else
    {
        printf("Love Missing\n");
    }

    return 0;
}
