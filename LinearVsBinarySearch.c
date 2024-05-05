/*
#include<stdio.h>
int main(){
    int arr[]={5,10,12,15,17,19,20};   
    int size=7;
     int low, mid, high;
    low = 0;
    high = size-1;
    int element ;   
    printf("Enter element to search\n");
    scanf("%d",&element);   
  while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            printf("element found at index %d\n",mid);
            break;
        }
       else  if(arr[mid]<element){
            low = mid+1;  //kyuki mid m nhi h element abhi tabhi +1 kiya
        }
        else{
            high = mid -1;  //kyuki mid m nhi h element abhi to -1 kiya h
        }
    } 
    return 0;
}
*/

#include<stdio.h>
 
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
       else if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    // If element is not found
    return -1;
    
}
 
int main(){
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
 
    // Sorted array for binary search
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(arr)/sizeof(int);
    int element = 444;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}

