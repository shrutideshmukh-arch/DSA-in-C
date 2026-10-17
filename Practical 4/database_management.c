#include<stdio.h>
typedef struct student{
    char name[20];
    int roll_no;
    int age;
}stud;
void create(stud *S){
   
    printf("\nenter the students details:");
    printf("\nenter name of student:");
    scanf("%s",&S->name);
    printf("enter roll_no of student:");
    scanf("%d",&S->roll_no);
    printf("enter age of student:");
    scanf("%d",&S->age);
}
void display(stud S){
   
    printf("\nstudent details:");
    printf("\nname of student:%s",S.name);
    printf("\nroll_no:%d",S.roll_no);
    printf("\nage:%d",S.age);
    printf(" ");
}

int lsearch(stud *S,int n){
    int found=1,key,index;
    printf("\nEnter roll number to search: ");
    scanf("%d", &key);
   
        for(int i=0;i<n;i++){
            if(S[i].roll_no == key){
                index=i;
                printf("Found the key element.");
                printf("\nstudent details:");
                printf("\nname of student:%s",S[index].name);
                printf("\nroll_no:%d",S[index].roll_no);
                printf("\nage:%d",S[index].age);
                return i;
        }
        }
       
        printf("\nKey element not found.");
        return -1;
       
}

void bubble_sort(stud *S,int n){
   
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(S[j].roll_no>S[j+1].roll_no){
                stud temp=S[j];
                S[j]=S[j+1];
                S[j+1]=temp;
            }
        }
    }
            for(int i=0;i<n;i++){
            printf("\n\nStudent %d", i + 1);
            display(S[i]);
            }
}

void modify(stud *S,int n){
    int key,index;
    index= lsearch(S,key);
    if (index== -1){
        return;
    }
    printf("\nenter the new details of student:");
    printf("\nenter name of student:");
    scanf("%s",&S[index].name);
    printf("enter roll_no of student:");
    scanf("%d",&S[index].roll_no);
    printf("enter age of student:");
    scanf("%d",&S[index].age);
}


void main(){
    stud S[5];
    int choice,exit=0,i,key,n;
    printf("enter the value of no. of students:");
    scanf("%d",&n);
    do{ printf("\n<---------Menu-------->");
        printf("\n1.create");
        printf("\n2.display");
        printf("\n3.linear search");
        printf("\n4.bubble sort");
        printf("\n5.modify");
        printf("\n6.exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
       

        switch(choice){
            case 1:
            for(i=0;i<n;i++){
            printf("\nStudent %d", i + 1);
            create(&S[i]);
            }
            break;

            case 2:
            for(i=0;i<n;i++){
            printf("\nStudent %d", i + 1);
            display(S[i]);
            }
            break;
           
            case 3:
            lsearch(S,n);
            break;
           
            case 4:
            bubble_sort(S,n);
            break;

            case 5:
            modify(S,n);
            break;

            case 6:
            exit=1;
            break;

            default:
            printf("invalid choice.");
            break;
        }

    }while(exit==0);
}
