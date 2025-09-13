#include <stdio.h>

void countingsort(int A[], int n, int k) {
    int B[50];     // output array
    int C[100];    // count array (assuming max element ≤ 99)
    int i, j;

    // Step 1: Initialize count array c[]
    for (i = 0; i <= k; i++) {
        C[i] = 0;
    }

    // Step 2: Count frequencies
    for (j = 0; j < n; j++) {
        C[A[j]]++;
    }

    // Step 3: Cumulative counts
    for (i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Step 4: Build output array b[]
    for (j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    // Step 5: Print sorted output
    printf("\nAfter sorting array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
}

int main() {
    int a[] = {2,5,3,0,2,3,0,3};
    int n = sizeof(a) / sizeof(a[0]);
     int k = 99; // max value in array (assumed ≤ 99)
    countingsort(a, n, k);

    return 0;
}
