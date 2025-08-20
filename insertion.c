#include <stdio.h>

void t(int arr[] , int n) {
    for (int i = 0; i < n; i++ ){
        printf("%d\n", arr[i]);
    }
};

//void insert(int arr) {




int main() { 
    int arr[100] = {1,2,6,88};
    printf("%d\n",arr[2]);   
    t(arr , 4);
    int s = sizeof(arr) / sizeof(arr[0]);
    printf("Size of array: %d\n", s);
//    insertion(arr);

  
    return 0;
}