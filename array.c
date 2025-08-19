#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int totalsize;
    int usedsize;
    int *ptr;

};

void create(struct myArray * b, int t , int u){
    (*b).totalsize = t;
    (*b).usedsize = u;
    (*b).ptr = ((int *) malloc(t* sizeof(int)) ) ;
};



int main() { 
    struct myArray marks;
    create(&marks, 10,0);
    printf("total %d", marks.totalsize);

    return 0;
} 