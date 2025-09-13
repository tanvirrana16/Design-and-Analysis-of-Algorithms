#include <stdio.h>

void bucketsort(int A[], int n) {
    int max = A[0];

    // Step 1: Find the maximum element in A[]
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    // Step 2: Create bucket array B[] of size max+1
    int B[max + 1];

    // Initialize all buckets with 0
    for (int i = 0; i <= max; i++) {
        B[i] = 0;
    }

    // Step 3: Count the frequency of each element from A[]
    for (int i = 0; i < n; i++) {
        B[A[i]]++;
    }

    // Step 4: Write sorted values back into A[]
    // For each index in B, put that number back into A as many times as it appeared
    int j = 0;
    for (int i = 0; i <= max; i++) {
        while (B[i] > 0) {
            A[j++] = i;   // place value i in A
            B[i]--;       // decrease frequency
        }
    }
}

int main() {
    int A[] = {12, 45, 33, 87, 56, 9, 11, 7, 67};
    int n = sizeof(A) / sizeof(A[0]);  // find size of array
    // Call bucket sort
    bucketsort(A, n);
    // Print after sorting
    printf("\nAfter sorting:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
