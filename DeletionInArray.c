#include<stdio.h>

void display(int arr[],int n){
for(int i=0;i<n;i++){
        printf("%d ",arr[i]); 
    }
    printf("\n");
}

int Deletion(int arr[],int size,int capacity,int index){
   if(size<=0){
    return -1;
   }
    for(int i=index;i<size;i++){ 
        arr[i]=arr[i+1]; // har element to peeche bhej diya .
    }  
    return 1;
}



int main(){
      int arr[100]={7,8,12,27,88};
    int capacity=100;
    int size=5;
    display(arr,5);
    int indexToDelete=3; //element to delete at that index.
   int delete= Deletion(arr,size,capacity,indexToDelete);
    if(delete==1){
        printf("Element deleted successfully\n");
        size--;
        display(arr,size);
    }
    else{
        printf("Element not deleted\n");
    }

    return 0;
}
