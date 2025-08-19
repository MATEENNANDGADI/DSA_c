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

void show (struct myArray * b)
{
    for (int i = 0; i < ((*b).usedsize); i++ )
    {
         printf("the element is %d \n", (*b).ptr[i]);
    }

};

void setValue(struct myArray * b){
    int n;
    for (int i = 0; i< (*b).usedsize; i++){
        printf("enter the value");
        scanf("%d",&n);
        (*b).ptr[i]=n; 
       }
}

int main() { 
    struct myArray marks;
    create(&marks, 10,4);
    setValue(&marks);
    printf("total %d\n", marks.totalsize);
    show(&marks);


    return 0;
} 