#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        printf("%c", input[i]);
    }

    printf("\n");

    return 0;
}
