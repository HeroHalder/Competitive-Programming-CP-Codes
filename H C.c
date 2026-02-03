#include <stdio.h>

int main() {
    int n, i, max = 0;
    int factorial = 1;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (i = 1; i <= max; i++) {
        factorial *= i;
    }

    printf("The highest number in the array is: %d\n", max);
    printf("The factorial of %d is: %llu\n", max, factorial);

    return 0;
}
