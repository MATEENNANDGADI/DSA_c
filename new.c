#include <stdio.h>

void t(int arr[] , int n) {
    for (int i = 0; i < n; i++ ){
        printf("%d\n", arr[i]);
    }
};

void indInsertion(int arr[], int usize, int element, int s, int index) {
    if (usize >= s) {
        printf("full!");
        return;  
    }
    for (int i = usize; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}




int main() { 
    int arr[100] = {1,2,6,88};
    printf("%d\n",arr[2]);   
    t(arr , 4);
    int s = sizeof(arr) / sizeof(arr[0]);
    printf("Size of array: %d\n", s);
    int usize = 4; // current size of the array
    int element = 5; // element to be inserted
    int index = 5;
    indInsertion(arr , usize , element , s , index);

  
    return 0;
}