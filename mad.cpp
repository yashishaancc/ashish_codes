#include<stdio.h>
int main(){
    int i;
    for(i=0;i<1000;i++){
        printf("\x1b[%dmYou are mad.\x1b[0m",31+i%5);
    }
    return 0;
}