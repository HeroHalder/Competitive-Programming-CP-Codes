#include <stdio.h>

int main() {
    int registration_fee = 130;
    int bkash_fee = 5;
    int total_fee = registration_fee + bkash_fee;

    printf("%d\n", total_fee);

    char answer[5];
    scanf("%s", &answer);

    printf("%s\n", answer);

    return 0;
}
