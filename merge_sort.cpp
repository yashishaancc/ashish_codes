#include<iostream>
#include<vector>
using namespace std;
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Merge(int* arr,int p,int r,int q){
    int s1=r-p+1,s2=q-r,i;
    int arr1[s1],arr2[s2],p1=0,p2=0;
    for(i=0;i<s1;i++)arr1[i]=arr[p+i];
    for(i=0;i<s2;i++)arr2[i]=arr[r+1+i];
    for(i=p;i<=q;i++){
        if(p2>=s2||p1<s1&&arr1[p1]<arr2[p2]){
            arr[i]=arr1[p1];
            p1++;
        }
        else{
            arr[i]=arr2[p2];
            p2++;
        }
    }
}
void Merge_Sort(int* arr,int p,int q){
    int r=(p+q)/2;
    if(r-p>0)Merge_Sort(arr,p,r);
    if(q-r-1>0)Merge_Sort(arr,r+1,q);
    Merge(arr,p,r,q);
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
    Merge_Sort(arr,0,n-1);
    print(arr,n);
    return 0;
}