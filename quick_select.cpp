#include<stdio.h>
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int Quick_Select(int* arr,int p,int q,int k,int n){
    int piv=arr[q],i=p,j=p-1,temp;
    for(i=p;i<=q;i++){
        if(arr[i]<=piv){
            temp=arr[i];
            arr[i]=arr[j+1];
            arr[j+1]=temp;
            j++;
        }
    }
    print(arrayr,n);
    if(j==k)return j;
    if(j>k)Quick_Select(arr,p,j-1,k,n);
    if(j<k)Quick_Select(arr,j+1,q,k,n);
}
int main(){
    int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Quick_Select(arr,0,n-1,n/2,n);
    print(arr,n);
    return 0;
}