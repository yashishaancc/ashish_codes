#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct stack{
    char str[2000];
    int top;
    int size;
}stack;
void push(stack* stk,char c){
    if(stk->top==stk->size)return;
    stk->str[stk->top]=c;
    stk->top=stk->top+1;
}
char pop(stack* stk){
    if(stk->top==0)return -1;
    stk->top--;
    return stk->str[stk->top];
}
int is_operator(char c){
    if(c=='^')return 5;
    if(c=='/'||c=='*')return 4;
    if(c=='+'||c=='-')return 3;
    return 0;
}
int main() {
    char str[2000],post[2000];
    int i=0,j=0;
    stack Stack;
    stack* stk=&Stack;
    stk->top=0;
    stk->size=2000;
    str[i]=getchar();
    while(str[i]!='\n'&&str[i]!='\0'){
        if(str[i]!='('&&str[i]!=')'&&!is_operator(str[i]))post[j++]=str[i];
        else if(is_operator(str[i])){
            if(stk->top==0)push(stk,str[i]);
            else if(is_operator(stk->str[stk->top-1])>=is_operator(str[i])){
                post[j++]=pop(stk);
                while(stk->top!=0&&is_operator(stk->str[stk->top-1])>=is_operator(str[i]))post[j++]=pop(stk);
                push(stk,str[i]);
            }
            else push(stk,str[i]);
        }
        else{
            if(str[i]=='(')push(stk,str[i]);
            else{
                while(stk->str[stk->top-1]!='(')post[j++]=pop(stk);
                pop(stk);
            }
        }
        scanf("%c",&str[++i]);
    }
    while(stk->top!=0)post[j++]=pop(stk);
    for(i=0;i<j;i++)printf("%c",post[i]);
    return 0;
}