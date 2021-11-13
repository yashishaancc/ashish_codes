#include<stdio.h>
int main(){
    int n1,n2,a1[100000],a2[100000],add[100000],i=0,j=0,sum,carry=0,flag=0,big;
    char c=0;
    printf("Enter first number:");
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a1[i]=c-'0';
        i++;
        c=getchar();
    }
    printf("Enter second number:");
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a2[j]=c-'0';
        j++;
        c=getchar();
    }
    n1=i;
    n2=j;
    if(n1>n2)big=n1;
    else big=n2;
    // printf("n1=%d and n2=%d\n",n1,n2);
    for(i=0;i<big+1;i++){
        if(i<=n1-1&&i<=n2-1)sum=a1[n1-1-i]+a2[n2-1-i];
        else if(i<=n1-1)sum=a1[n1-1-i];
        else if(i<=n2-1)sum=a2[n2-1-i];
        else sum=0;
        // for(j=0;j<=i;j++){
        //     if(j<n1&&i-j<n2)sum+=a1[n1-1-j]*a2[n2-1-i+j];
        // }
        // printf("sum=%d,carry=%d\n",sum,carry);
        add[i]=(sum+carry)%10;
        carry=(sum+carry)/10;
    }
    for(i=0;i<n1;i++){
        printf("%d",a1[i]);
    }
    printf("+");
    for(i=0;i<n2;i++){
        printf("%d",a2[i]);
    }
    printf("=\n");
    for(i=0;i<big+1;i++){
        if(add[big+1-1-i]!=0)flag=1;
        if(flag==1)printf("%d",add[big+1-1-i]);
    }
    printf("\n");
    return 0;
}