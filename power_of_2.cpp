#include<stdio.h>
void mul(int*a1,int*a2,int*m,int n1,int n2){
    int i,j,sum,carry=0,flag=0,mul_digits;
    for(i=0;i<n1+n2;i++){
        sum=0;
        for(j=0;j<=i;j++){
            if(j<n1&&i-j<n2)sum+=a1[n1-1-j]*a2[n2-1-i+j];
        }
        // printf("sum=%d,carry=%d\n",sum,carry);
        m[n1+n2-1-i]=(sum+carry)%10;
        carry=(sum+carry)/10;
    }
    // for(i=0;i<n1+n2;i++){
    //     if(m[i]!=0){
    //         flag=1;
    //         mul_digits=n1+n2-1-i;
    //     }
    //     // if(flag==1)printf("%d",m[n1+n2-1-i]);
    // }
    // return mul_digits;
}
int main(){
    int n1,n2,a1[100000],a2[100000],m[100000],i=0,j=0,sum,carry=0,flag=0,power;
    char c=0;
    a1[0]=2;
    a2[0]=1;
    n1=1;
    n2=1;
    printf("Upto what power of 2:");
    scanf("%d",&power);
    // printf("Enter first number:");
    // while(c<'0'||c>'9'){
    //     c=getchar();
    // }
    // while(c>='0'&&c<='9'){
    //     a1[i]=c-'0';
    //     i++;
    //     c=getchar();
    // }
    // printf("Enter second number:");
    // while(c<'0'||c>'9'){
    //     c=getchar();
    // }
    // while(c>='0'&&c<='9'){
    //     a2[j]=c-'0';
    //     j++;
    //     c=getchar();
    // }
    // n1=i;
    // n2=j;
    // printf("n1=%d and n2=%d\n",n1,n2);
    for(j=1;j<=power;j++){
        mul(a1,a2,m,n1,n2);
        flag=0;
        for(i=0;i<n1+n2;i++){
            if(i==0)printf("%5d->",j);
            if(m[i]!=0)flag=1;
            if(flag==1)printf("%d",m[i]);
            a2[i]=m[i];
        }
        printf("\n");
        n2+=n1;
        // a2=&m;
    }
    // for(i=0;i<n1;i++){
    //     printf("%d",a1[i]);
    // }
    // printf("*");
    // for(i=0;i<n2;i++){
    //     printf("%d",a2[i]);
    // }
    // printf("=\n");
    // for(i=0;i<n1+n2;i++){
    //     if(m[n1+n2-1-i]!=0)flag=1;
    //     if(flag==1)printf("%d",m[n1+n2-1-i]);
    // }
    // printf("\n");
    return 0;
}