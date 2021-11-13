#include<stdio.h>
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Bubble_Sort(int* arr,int p,int q){
    int i=q,temp;
    while(i>p){
        if(arr[i-1]>arr[i]){
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
        }
        i--;
    }
    if(q>p+1)Bubble_Sort(arr,p+1,q);
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
    Bubble_Sort(arr,0,n-1);
    print(arr,n);
    return 0;
}