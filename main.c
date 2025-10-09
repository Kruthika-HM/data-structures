#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define size 10

struct stack {
    int top;
    float data[size];
};
typedef struct stack STACK;
void push(STACK *s,float item){
    s->data[++(s->top)]=item;
}
float pop(STACK *s){
    return s->data[(s->top)--];
}
float compute(float opr1,char symbol,float opr2){
    switch(symbol){
        case '+': return opr1+opr2;
        case '-': return opr1-opr2;
        case '*': return opr1*opr2;
        case '/': return opr1/opr2;
        case '^': return pow(opr1,opr2);
        }
}
float evaluate_postfix(STACK *s,char postfix[20]){
    int i;
    float opr1,opr2,result;
    char symbol;

    for(i=0;postfix[i]!='\0';i++){
            symbol=postfix[i];
            if(isdigit(symbol))
                push(s,symbol-'0');
            else{

                    opr2=pop(s);
                    opr1=pop(s);
                    result=compute(opr1,symbol,opr2);
                    push(s,result);
                }

}return pop(s);
}
int main(){
    char postfix[20];
    STACK s;
    s.top=-1;
    float result;
    printf("\n read postfix expression:\n");
    scanf("%s",postfix);
    result=evaluate_postfix(&s,postfix);
    printf("\n the final result is %f",result);

    return 0;

}




