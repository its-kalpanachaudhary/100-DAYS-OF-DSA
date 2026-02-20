#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefix = 0;

    // Using simple frequency array (range assumption)
    // For general case, we use hash map logic manually
    int freq[20001] = {0};  
    int offset = 10000;  // to handle negative prefix sums

    freq[offset] = 1; // prefix sum 0 already exists

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        count += freq[prefix + offset];
        freq[prefix + offset]++;
    }

    printf("%d\n", count);
    return 0;
}