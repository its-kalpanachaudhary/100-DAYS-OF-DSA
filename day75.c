#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    // Hash map (prefix sum → first index)
    int map[20001];   // to handle negative sums
    for (int i = 0; i < 20001; i++) map[i] = -2;

    int offset = 10000; // shift to handle negative indices
    map[offset] = -1;   // prefix sum 0 at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (map[prefixSum + offset] != -2) {
            int prevIndex = map[prefixSum + offset];
            int length = i - prevIndex;
            if (length > maxLen)
                maxLen = length;
        } else {
            map[prefixSum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}