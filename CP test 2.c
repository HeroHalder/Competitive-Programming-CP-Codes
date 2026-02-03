#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long N;
        int even_count = 0, odd_count = 0;
        int even_digits[10], odd_digits[10];
        int even_index = 0, odd_index = 0;
        scanf("%lld", &N);
        while (N > 0) {
            int digit = N % 10;
            if (digit % 2 == 0) {
                even_digits[even_index++] = digit;
                even_count++;
            } else {
                odd_digits[odd_index++] = digit;
                odd_count++;
            }
            N /= 10;
        }

        printf("%d even (", even_count);
        for (int i = even_count - 1; i >= 0; i--) {
            printf("%d", even_digits[i]);
            if (i > 0) printf(", ");
        }
        printf(") and %d odd (", odd_count);
        for (int i = odd_count - 1; i >= 0; i--) {
            printf("%d", odd_digits[i]);
            if (i > 0) printf(", ");
        }
        printf(")\n");
    }

    return 0;
}
