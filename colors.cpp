#include<stdio.h>
int main(){
    int n,i;
    for(i=0;i<=56;i++){
        printf("\x1b[%dmcolor%2d   \x1b[0m",i,i);
        if(i%7==0)printf("\n");
    }
    return 0;
}