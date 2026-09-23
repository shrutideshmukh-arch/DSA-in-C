#include<stdio.h>
#define max 5
int stack[max];
int top=-1;
void push(int value){
    if(top==max-1){
        printf("\nstack is full.");
    }
    else{
        stack[++top]=value;
        printf("\n%d pushed to stack",value);
    }
}
void pop(){
    if(top==-1){
        printf("\nstack is underflow");
    }
    else{
        printf("\n%d is popped",stack[top--]);
    }
}
void peak(){
    printf("\n%d is the peak element.",stack[top]);
}
void display(){
    if(top==-1){
        printf("\nstack is underflow");}
    else{
    for(int i=max-1;i>=0;i--){
        printf("\n%d",stack[i]);
    }
}
}
int main(){
    int value,choice,exit=0;
    do{
        printf("\n<--------main menu--------->");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.peak");
        printf("\n4.Display");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
switch(choice){
    case 1:
    printf("enter item to be pushed:");
    scanf("%d",&value);
    push(value);
    break;

    case 2:
    pop();
    break;

    case 3:
    peak();
    break;

    case 4:
    display();
    break;

    default:
    printf("invalid choice");
}
 }while(exit==0);
}
