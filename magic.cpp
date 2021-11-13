#include<stdio.h>
int main(){
    int dd,m,y;
    printf("Enter your date of birth in format dd mm yyyy:");
    scanf("%d%d%d",&dd,&m,&y);
    int a=dd,b=m,c=y/100,d=y%100;
    printf("Your magic square with magic sum %3.2d is:\n",a+b+c+d);
    printf("%3.2d  %3.2d  %3.2d  %3.2d\n",a,b,c,d);
    printf("%3.2d  %3.2d  %3.2d  %3.2d\n",d+1,c-1,b-3,a+3);
    printf("%3.2d  %3.2d  %3.2d  %3.2d\n",b-2,a+2,d+2,c-2);
    printf("%3.2d  %3.2d  %3.2d  %3.2d\n",c+1,d-1,a+1,b-1);
}