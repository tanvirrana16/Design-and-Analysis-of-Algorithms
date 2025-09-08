#include<stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }if(start<end){
        swap(&a[start],&a[end]);
    }
}
    swap(&a[lb],&a[end]);
    return end;
}
void Quicksort(int a[],int lb,int ub){
     if(lb<ub){
      int loc=partition(a,lb,ub);
      Quicksort(a,lb,loc-1);
      Quicksort(a,loc+1,ub);
     }
}
int main(){
int arr[] = {7,6,10,5,9,2,1,15,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Quicksort(arr, 0, n - 1);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}