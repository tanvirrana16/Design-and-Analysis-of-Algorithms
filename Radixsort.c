#include <stdio.h>

void countsort(int A[], int n, int pos) {
    int B[n];       // local output array
    int C[10] = {0}; // count array (for digits 0-9)

    // Count frequency of each digit
    for (int i = 0; i < n; i++) {
        int digit = (A[i] / pos) % 10;
        C[digit]++;
    }

    // Cumulative count
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Build output array B[] (stable sort: traverse from right)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / pos) % 10;
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    // Copy B[] back to A[]
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void radixsort(int A[], int n) {
    int max = A[0];

    // Find maximum value
    for (int i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
    }

    // Apply counting sort for every digit
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countsort(A, n, pos);
    }
}

int main() {
    int A[] = {432,8,530,90,88,231,11,45,677,199};
    int n = sizeof(A) / sizeof(A[0]);
    radixsort(A, n);
    printf("\nAfter sorting:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
