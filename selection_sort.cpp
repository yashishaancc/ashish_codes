#include<stdio.h>
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Selection_Sort(int* arr,int p,int q){
    int i,temp,index=p,min=arr[p];
    for(i=p;i<=q;i++){
        if(arr[i]<min){
            min=arr[i];
            index=i;
        }
    }
    temp=arr[index];
    arr[index]=arr[p];
    arr[p]=temp;
    if(q>p+1)Selection_Sort(arr,p+1,q);
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
    Selection_Sort(arr,0,n-1);
    print(arr,n);
    return 0;
}