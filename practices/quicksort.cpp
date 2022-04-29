#include <stdio.h>

void quickSort(int arr[], int n){
    int p = arr[0];
    int l=0, r=n-1;
    //printf("%d \n", n);
    if (n<=1)
        return;

    while(l!=r){
        while(r>l){
            if(arr[r] < p){
                arr[l] = arr[r];
                l++;
                break;
            } else {
                r--;
            } 
        }
        while(l<r){
            if(arr[l] > p){
                arr[r] = arr[l];
                r--;
                break;
            } else{
                l++; 
            }
        }
    
    }
    arr[l]=p;
    quickSort(arr, l);
    quickSort(arr+l+1, n-l-1);
}

int main(){
    int a[] = {4,2,1,9,0,8,5,6,7,3};
    quickSort(a, 10);
    for(int i=0; i<10;i++){
        printf("%d, ", a[i]);
    }
    printf("\n");

}
