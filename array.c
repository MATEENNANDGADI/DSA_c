#include <stdio.h>

struct myArray
{
    int totalsize;
    int usedsize;
    int *ptr;

};

void create(struct myArray * b, int t , int u,){
    (*b).totalsize = t;
    (*b).usedsize = u;
    int * ptr = ((int *) malloc(t* sizeof(int)) ) 
}



int main() { 
    struct myArray marks;
    
    return 0;
} 