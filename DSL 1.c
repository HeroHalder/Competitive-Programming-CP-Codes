#include <stdio.h>

int main() {
    char arr[] = {'a', 'd', 'c', 'a', 'e', 'd'};
    int n = sizeof(arr) / sizeof(arr[0]);
    char unique[256] = {0};

    for (int i = 0; i < n; i++) {
        unique[(int)arr[i]] = 1;
    }

    for (int i = 255; i >= 0; i--) {
        if (unique[i]) {
            printf("%c", (char)i);
        }
    }

    return 0;
}
