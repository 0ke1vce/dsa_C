#include<stdio.h>
#include<stdlib.h>

struct MyArray{
    int total_size;  // reserved size.
    int used_size; // used size in my array.
    // Let total size=6, used size=3 arr->{1,2,3,_,_,_} we can use this reserved space when we wanted
    int *ptr;   //point to first element/Memory block of my array.

};

void createArray(struct MyArray *a,int tSize,int uSize){
  
    // a->total_size=tSize; you can do like this also.
    
    (*a).total_size=tSize;
    (*a).used_size=uSize;
    
    (*a).ptr=(int *) malloc(tSize*4); //to create a memory reserve of tSize now ptr points to first element of this memory.

// StructureVariableAdress.ptr=(int *)malloc(Size*sizeof(int);

}

void setVal(struct MyArray *a){
     for(int i=0;i<(a->used_size);i++){
        printf("Enter element\n");
        scanf("%d",((a->ptr)+i));
     }
}

void show(struct MyArray *a){
    for(int i=0;i<(a->used_size);i++){
        printf("%d\n",*((a->ptr)+i));
    }
}


int main(){
    struct MyArray marks;
    
    int tSize,uSize;
    
    printf("Enter total Size\n");
    scanf("%d",&tSize);  // kitna size reserve karna h memory block m.

    printf("Enter Used Size\n");
    scanf("%d",&uSize); //kitna size use karna h.

    createArray(&marks,tSize,uSize);

    printf("Setting value\n");
    setVal(&marks);

    printf("Showing vvalues...");
    show(&marks);

    return 0;


}