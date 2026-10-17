 #include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*head;
void push(int value){
   
struct node *newNode=malloc(sizeof(struct node));
newNode->data=value;
newNode->next=head;
head=newNode;
}
void pop(){
    if (head==NULL){
        printf("\n Stack is empty.");
    }
    else{
        struct node*temp=head;
        printf("\n%d is popped element.",head->data);
        head=head->next;
        free(temp);
    }
}
void printlist(){
    struct node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
}
int main(){
    push(10);
    push(38);
    push(69);
    printf("linked list:");
    printlist();
    pop();
    return 0;
}
