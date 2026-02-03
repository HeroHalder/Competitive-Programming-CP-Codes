#include <stdio.h>

int main() {
    int arr[] = {10, 20, 20, 10, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int visited[1000] = {0};

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1)
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d-%d\n", arr[i], count);
    }

    return 0;
}
