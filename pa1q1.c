#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int debug=1;
int search(long long* arr,int p,int q){
    if(p==q)return p;
    int m=(p+q)/2;
    if(arr[m]>arr[m+1])return m+1;
    if(arr[m]>arr[q])return search(arr,m+1,q);
    return search(arr,p,m);
}
int target_id(long long*arr,int s,int e,int p,int n,long long a){
    int m=(s+e)/2;
    if(arr[(m+p)%n]==a)return (m+p)%n;
    if(s>=e)return -1;
    if(arr[(m+p)%n]<a)return target_id(arr,m+1,e,p,n,a);
    return target_id(arr,s,m-1,p,n,a);
}
int main() {
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        long long arr[n],a;
        for(j=0;j<n;j++){
            scanf("%lld",&arr[j]);
        }
        scanf("%lld",&a);
        int p=search(arr,0,n-1);
        int index=target_id(arr,0,n-1,p,n,a);
        if(debug==1){
            printf("p = %d\n",p);
            printf("index = %d\n",index);
        }
        printf("%d\n",index);
    }
    return 0;
}