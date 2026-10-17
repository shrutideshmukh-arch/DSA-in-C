#include<stdio.h>
#include<string.h>
#include<math.h>
#define size 80
struct stack{
    double S[size];
    int top;    
}st;
void main(){
    char exp[size];
    int len;
    double result;
    double post(char[]);
    printf("enter postfix exp:");
    scanf("%s",exp);

    len= strlen(exp);
    exp[len]='$';
    exp[len+1] = '\0';
    result=post(exp);
    printf("\n the value of expression is %f",result);
    getchar();
   
}

double post(char exp[]){
    char ch,*type;
    double result ,val,op1,op2;
    void push(double);
    double pop();
    int i;
    st.top=-1;
    i=0;
    ch=exp[i];
    while(ch!='$'){
        if(ch>='0'&&ch<='9')
            type="operand";
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
            type="operator";
if(strcmp(type,"operand")==0){
            val=ch-48;
            push(val);
        }
else if(strcmp(type,"operator")==0){
    op2=pop();
    op1=pop();

    switch(ch){
        case '+':result=op1+op2;break;
        case '-':result=op1-op2;break;
        case '*':result=op1*op2;break;
        case '/':result=op1/op2;break;
        case '^':result=pow(op1,op2);break;
    }
    push(result);
}
        i++;
        ch=exp[i];
    }
    result=pop();
    return result;
}
void push(double val){
    if(st.top>=size-1)
        printf("\n stack full.");
    st.top++;
    st.S[st.top]=val;
}

double pop(){
    double val;
    if (st.top==-1)
        printf("\n stack is empty.");
    val=st.S[st.top];
    st.top--;
    return val;
}
