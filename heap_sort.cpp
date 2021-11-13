#include<stdio.h>
void print(int *arr,int n,int c){
    int i;
    for(i=0;i<n;i++){
        printf("\x1b[%dm%d \x1b[0m",c,arr[i]);
    }
    printf("\n");
}
void swap(int* p1,int* p2){
    int t=*p1;
    *p1=*p2;
    *p2=t;
}
void heapify(int* arr,int i,int f,int flag){
    int max;
    if(flag==0){
        if((f-1)/2>=0&&arr[(f-1)/2]<arr[f]){
            swap(&arr[(f-1)/2],&arr[f]);
            f=(f-1)/2;
            heapify(arr,0,f,0);
        }
    }
    if(flag==1){
        if(2*f+1<i&&2*f+2<i){
            max=(arr[2*f+1]>arr[2*f+2])?2*f+1:2*f+2;
            if(arr[max]>arr[f]){
                swap(&arr[f],&arr[max]);
            }
            f=max;
            heapify(arr,i,f,1);
        }
        else if(2*f+1<i){
            max=2*f+1;
            if(arr[max]>arr[f]){
                swap(&arr[f],&arr[max]);
            }
        }
    }
}
void Heap_Sort(int* arr,int p,int q){
    printf("Initial array:");
    print(arr,q+1,1);
    int i,f;
    for(i=p;i<=q;i++){
        heapify(arr,0,i,0);
    }
    printf("Maxheap array:");
    print(arr,q+1,31);
    for(i=q;i>0;i--){
        swap(&arr[0],&arr[i]);
        f=0;
        heapify(arr,i,f,1);
        printf("%5dth place is right,rest is maxheap array:",i+1);
        print(arr,q+1,33);
    }
    printf("%5dth place is right,rest is maxheap array:",i+1);
    print(arr,q+1,33);
    printf("\x1b[36mFinal array:\x1b[0m");
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
    Heap_Sort(arr,0,n-1);
    print(arr,n,32);
    return 0;
}