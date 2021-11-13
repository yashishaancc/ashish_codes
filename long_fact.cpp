#include<stdio.h>
void extraLongFactorials(int n) {
    int i=0,j=0,f=0,a[200],b[200],c[200],m=n,p=n,carry=0,sum=0;
    for(i=0;i<200;i++)a[i]=0;
    for(i=0;i<200;i++)b[i]=0;
    for(i=0;i<200;i++)c[i]=0;
    for(j=1;j<=2;j++){
        i=0;
        while(m>0){
            if(j==1)a[200-1-i]=m%10;
            if(j==2)b[200-1-i]=m%10;
            m/=10;
            i++;
        }
        m=n-j;
    }
    while(m>=1){
        carry=0;
        for(i=200-1;i>=0;i--){
            sum=0;
            for(j=0;j<200-i;j++){
                sum+=a[200-1-j]*b[i+j];
            }
            c[i]=(sum+carry)%10;
            carry=(sum+carry)/10;
        }
        for(i=0;i<200;i++)a[i]=c[i];
        for(i=0;i<200;i++)b[i]=0;
        i=0;
        p=m;
        while(p>0){
            b[200-1-i]=p%10;
            p/=10;
            i++;
        }
        for(i=0;i<200;i++)c[i]=0;
        m--;
    }
    for(i=0;i<200;i++){
        if(a[i]!=0)f=1;
        if(f==1)printf("%d",a[i]);
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%3d ",i);
        extraLongFactorials(i);
        printf("\n");
    }
    return 0;
}