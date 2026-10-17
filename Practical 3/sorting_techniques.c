#include<stdio.h>

int bubble_sort(int m,int arr[]);
int insertion_sort(int m,int arr[]);
int selection_sort(int m,int arr[]);
void quick_sort(int arr[],int low,int high);
void merge_sort(int m,int arr[],int left,int right);

void display_menu(){
    printf("\n\n<--------Menu-------->");
    printf("\n1. bubble_sort");
    printf("\n2.insertion_sort");
    printf("\n3.selection_sort");
    printf("\n4.quick_sort");
    printf("\n5.merge_sort");
}

int main(){
    int i,m,arr[100];
    int choice;
    int exit=0;

    printf("\nenter size of array:");
    scanf("%d",&m);
    printf("enter array elements:");
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    printf("the array is :");
     for(int i=0;i<m;i++){
        printf("\t%d",arr[i]);
    }
    display_menu();
    do{
       
     printf("\n\nenter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            bubble_sort(m,arr);
            break;

        case 2:
            insertion_sort(m,arr);
            break;

        case 3:
            selection_sort(m, arr);
            break;

        case 4:
            int low=0,high=m-1;
            quick_sort(arr,low,high);
            printf("the sorted array is:");
            for(int i=0;i<m;i++){
            printf("\t%d",arr[i]);
            }
            break;

        case 5:
            int left=0,right=m-1;
            merge_sort(m,arr,left,right);
            printf("the sorted array is:");
            for(int i=0;i<m;i++){
            printf("\t%d",arr[i]);
            }
            break;
        default:
        printf("\n invalid choice.");
       }

    }while(exit==0);
    return 0;
}


int bubble_sort(int m,int arr[]){
    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("the sorted array is:");
    for(int i=0;i<m;i++){
    printf("\t%d",arr[i]);
    }
}
 
int insertion_sort(int m,int arr[]){
    int i,prev,temp;
    for (i=1;i<m;i++){
        temp=arr[i];
        prev=i-1;
        while(prev>=0 && arr[prev]>temp){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=temp;
    }
    printf("the sorted array is:");
    for(int i=0;i<m;i++){
    printf("\t%d",arr[i]);
    }
}

int selection_sort(int n, int arr[]){
    int i,j,temp,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
            min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
     printf("the sorted array is:");
    for(int i=0;i<n;i++){
    printf("\t%d",arr[i]);
    }

}
void merge(int arr[],int left,int mid ,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;

    int leftArr[n1],rightArr[n2];

    for(i=0;i<n1;i++){
    leftArr[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        rightArr[j]=arr[mid+1+j];
    }

    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k]=leftArr[i];
            i++;
        }
        else{
            arr[k]=rightArr[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rightArr[j];
        j++;
        k++;
    }
}

void merge_sort(int m,int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(m,arr,left,mid);
        merge_sort(m,arr,mid+1,right);

        merge(arr,left,mid,right);
    }
   
}
void swap(int* a, int* b);
// partition function
int partition(int arr[], int low, int high) {
    // Choose the pivot
    int pivot = arr[high];
   
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
   
    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
       
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
