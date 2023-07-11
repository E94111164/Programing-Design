#include <stdio.h>
#include <stdlib.h>

//swap two number
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort
void selsection_sort(int arr[], int n){
    //max_arr is the location of maximum in the array;
    int i, j, max_arr;
    for(i = 0; i < (n-1); i++){
        //let i be the location of maximum in the array;
        max_arr = i;
        for(j = i + 1; j < n; j++){
            //if arr[j] > arr[max_arr], j is the location of maximum in the array
            if(arr[j] > arr[max_arr])
                max_arr = j;
        }
        //put arr[max_arr] to the location i;
        swap(&arr[i], &arr[max_arr]);
    }
    printf("Result:");
    for(i = 0; i < n; i++){
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[] = {16, 25, 39, 27, 12, 8, 45, 63};
    //get length of array;
    int ans = sizeof(arr)/sizeof(arr[0]), i;
    printf("Origin:");
    for(i = 0; i < ans; i++){
        printf("%2d ", arr[i]);
    }
    printf("\n");
    selsection_sort(arr, ans);
    return 0;
}
