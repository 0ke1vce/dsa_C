#include<stdio.h>


void display(int arr[],int n){
//    Array Traversal
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); 
    }
    printf("\n");
}

int indInsertion(int arr[],int size,int capacity,int element,int index){
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1;i>=index;i--){ //last index se start kiya h loop
        arr[i+1]=arr[i]; //or har element to aage bhej diya .
        // 
    }
    arr[index]=element; //jo element index m dalna tha vo dal gya h
    return 1;
}


int main(){
    int arr[100]={7,8,12,27,88};
    int capacity=100; //total capacity of my array
    int size=5;
    display(arr,5);
    int elementToInsert=45; //element to be inserted
    int indexToInsert=3; //element to insert at that index.
   int insert= indInsertion(arr,size,capacity,elementToInsert,indexToInsert);
    if(insert==-1){
        printf("Insertion not done\n");
    }
    else{
        printf("INsertion complete\n");
        size+=1;
        display(arr,size);
    }


}
