#include<stdio.h>
int Find_max_cross_sum(int* arr,int p,int q,int r){
    int left_max=arr[q],right_max=arr[q+1],sum=0,i;
    for(i=q;i>=p;i--){
        sum+=arr[i];
        if(sum>left_max)left_max=sum;
    }
    sum=0;
    for(i=q+1;i<=r;i++){
        sum+=arr[i];
        if(sum>right_max)right_max=sum;
    }
    return left_max+right_max;
}
int Find_max_sum(int* arr,int p,int q){
    int m=(p+q)/2,l,r,b;
    if(p==q)return arr[p];
    l=Find_max_sum(arr,p,m);
    r=Find_max_sum(arr,m+1,q);
    b=Find_max_cross_sum(arr,p,m,q);
    if(b>l&&b>r)return b;
    if(l>r)return l;
    else return r;
}
int main(){
    int n,i,max_sum;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    max_sum=Find_max_sum(arr,0,n-1);
    printf("max_sum=%d\n",max_sum);
    return 0;
}