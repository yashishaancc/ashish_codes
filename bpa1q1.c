#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void DFT(int*a,int*b,int n){
    int i,j;
    for(i=0;i<n;i++){
        float re=0,im=0,angle;
        for(j=0;j<n;j++){
            angle=2*M_PI*i*j/n;
            re+=a[j]*cos(angle)-b[j]*sin(angle);
            im+=a[j]*sin(angle)+b[j]*cos(angle);
        }
        if(fabs(re)<0.0001)re=+0.000;
        if(fabs(im)<0.0001)im=+0.000;
        printf("(%.3f,%.3f)\n",re,im);
    }
}
int main() {
    int t,n,i,j,N;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<=10;j++){
            if(pow(2,j)>=n){
                N=pow(2,j);
                break;
            }
        }
        int a[N],b[N];
        for(j=0;j<N;j++){
            if(j<n)scanf("%d%d",&a[j],&b[j]);
            else{
                a[j]=0;
                b[j]=0;
            }
        }
        DFT(a,b,N);
    }
    return 0;
}