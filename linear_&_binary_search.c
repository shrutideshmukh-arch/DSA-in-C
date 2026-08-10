#include<stdio.h>

void insert(int m,int arr[]){
    printf("enter array elements:");
    for(int i=0;i<m;i++){
    scanf("%d",&arr[i]);
    }
}


void display( int m,int arr[]){
    printf("the entered elements are:");
    for(int i=0;i<m;i++){
    printf("\t%d",arr[i]);
    }
}


void lsearch(int m,int arr[],int Key){
    int found=1;
    for(int i=0;i<m;i++){
        if(arr[i]==Key){
          found=0;
        }
    }
    if(found==0){
        printf("\nfound the key element.");
    }
        else{
           printf("\nnot found the key element .");
        }
   }


void bisearch(int m,int arr[],int Low,int High,int Key){
    if (Low>High){
    printf("Key element not found.");
    }
    int Mid=(High+Low)/2;
    int index;
   
    if(Key==arr[Mid]){
    index=Mid;
    printf("\nfound the key element at index %d",index);
    }
    else if(Key<arr[Mid]){
     bisearch(m,arr,Low,Mid-1,Key);
    }
    else{
     bisearch(m,arr,Mid+1,High,Key);
    }
}

void displaymenu(){
    printf("\n<--------Menu-------->");
    printf("\n1.display");
    printf("\n2.linear search");
    printf("\n3.binary search");
}

int main() {
    int m,arr[100],n,choice;
    int Low,High,Key;
    int exit=0;
   
    printf("\nenter size of array:");
    scanf("%d",&m);
    insert(m,arr);
    displaymenu();
    Low=0,High=m-1;
    do{
        printf("\n\nenter choice:");
        scanf("%d",&choice);
       
        switch(choice){
            case 1:
                 display(m,arr);
                 break;
                 
            case 2:
                 printf("enter key element:");
                 scanf("%d",&Key);
                 lsearch(m,arr,Key);
                 break;
                 
            case 3:
                 printf("enter key element:");
                 scanf("%d",&Key);
                 bisearch(m,arr,Low,High,Key);
                 break;
                 
            default:
                 printf("\nInvalid Choice\n");
           
        }
    }while(exit==0);
     return 0;
   }
