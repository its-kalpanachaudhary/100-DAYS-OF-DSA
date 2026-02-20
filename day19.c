#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = abs(arr[left] + arr[right]);
    int num1 = arr[left], num2 = arr[right];

    // Step 2: Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            num1 = arr[left];
            num2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", num1, num2);
    return 0;
}