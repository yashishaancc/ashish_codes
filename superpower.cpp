#include<stdio.h>
#include<math.h>
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
}
int main(){
    int n1,n2,a1[100000],a2[100000],m[100000],i=0,j=0,sum,carry=0,flag=0,power;
    char c=0;
    a1[0]=2;
    a2[0]=1;
    n1=1;
    n2=1;
    for(j=0;j<11;j++){
        mul(a1,a2,m,n1,n2);
        flag=0;
        for(i=0;i<n1+n2;i++){
            if(i==0)printf("%3d->%5d->",j,(int)pow(2,j));
            if(m[i]!=0)flag=1;
            if(flag==1)printf("%d",m[i]);
            a1[i]=m[i];
            a2[i]=m[i];
        }
        printf("\n");
        n1+=n1;
        n2+=n2;
    }
    return 0;
}