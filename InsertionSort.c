#include <stdio.h>

void insertion_sort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;                    
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main(void) {
    int a[] = {5,1,9,3,7,2,8,6,0,4};
    int n = (int)(sizeof(a)/sizeof(a[0]));
    insertion_sort(a, n);
    for (int i = 0; i < n; i++) {
    if (i == n - 1)
        printf("%d", a[i]);   
    else
        printf("%d ", a[i]);  
}
printf("\n");

    return 0;
}
