#include<stdio.h>
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Quick_Sort(int* arr,int p,int q){
    int piv=arr[q],i=p,j=p-1,temp;
    for(i=p;i<=q;i++){
        if(arr[i]<=piv){
            temp=arr[i];
            arr[i]=arr[j+1];
            arr[j+1]=temp;
            j++;
        }
    }
    if(j-p>0)Quick_Sort(arr,p,j-1);
    if(q-j>0)Quick_Sort(arr,j+1,q);
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
    Quick_Sort(arr,0,n-1);
    print(arr,n);
    return 0;
}