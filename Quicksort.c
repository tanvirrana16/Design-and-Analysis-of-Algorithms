#include<stdio.h>
void swap(int* a,int* b){// swapping the two variable
    int temp=*a; //take a temp variable which store the Address of a
    *a=*b;// copy the address of b at a
    *b=temp; // then declare temp as a b which was before declared the address of a
}
int partition(int a[],int lb,int ub){ //partition function
    int pivot=a[lb]; //take a pivot value at lower bound
    int start=lb; //initialize variable start as lower bound
    int end=ub;//initialize variable end as upper bound
    while(start<end){ //check  start less than end in while loop
        while(a[start]<=pivot){// check value of a[start] less than or equal to pivot 
            start++;// then increment start
        }
        while(a[end]>pivot){//check value of a[end] greater than pivot 
            end--; //then decrement end =end-1
        }
        if(start<end){  // check if start is less than end
        swap(&a[start],&a[end]);  //then exchange  a[start] with a[end]
    }
}
    swap(&a[lb],&a[end]);//if not then exchange a[lb] with a[end]
    return end;//at last return the index of end
}
void Quicksort(int a[],int lb,int ub){  //
     if(lb<ub){//check if lower bound less than upper bound
      int loc=partition(a,lb,ub); //declare a location varibale in the return value from the partition function 
      Quicksort(a,lb,loc-1);//then again call recursively from the lower bound to location-1 
      Quicksort(a,loc+1,ub);//then again call recursively from the location+1 to ubber bound
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