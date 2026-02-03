#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("Invalid input! N must be between 1 and 100.\n");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            printf("First Prize\n");
        } else if (i == 2) {
            printf("Second Prize\n");
        } else if (i == 3) {
            printf("Third Prize\n");
        } else if (i >= 4 && i <= 10) {
            printf("Might Get Prize, Surprize!\n");
        } else {
            printf("Participation Prize\n");
        }
    }

    return 0;
}

