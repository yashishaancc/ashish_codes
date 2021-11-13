#include<stdio.h>
#include<iostream>
#include<algorithm> 
#include<chrono>
#include<vector>
using namespace std; 
using namespace std::chrono;
void print(int *arr,int n,int c){
    int i;
    for(i=0;i<n;i++)printf("\x1b[%dm%d \x1b[0m",c,arr[i]);
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
            if(arr[max]>arr[f])swap(&arr[f],&arr[max]);
            f=max;
            heapify(arr,i,f,1);
        }
        else if(2*f+1<i){
            max=2*f+1;
            if(arr[max]>arr[f])swap(&arr[f],&arr[max]);
        }
    }
}
void merge(int* arr,int p,int r,int q){
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
void Bubble_Sort(int* arr,int p,int q){
    int i=q;
    while(i>p){
        if(arr[i-1]>arr[i]){
            swap(&arr[i-1],&arr[i]);
        }
        i--;
    }
    if(q>p+1)Bubble_Sort(arr,p+1,q);
}
void Heap_Sort(int* arr,int p,int q){
    int i,f;
    for(i=p;i<=q;i++){
        heapify(arr,0,i,0);
    }
    for(i=q;i>0;i--){
        swap(&arr[0],&arr[i]);
        f=0;
        heapify(arr,i,f,1);
    }
}
void Insertion_Sort(int* arr,int p,int q){
    if(q>1)Insertion_Sort(arr,0,q-1);
    int i=q-1;
    while(q>p&&arr[q]<arr[i]){
        swap(&arr[q],&arr[i]);
        q--;
        i--;
    }
}
void Merge_Sort(int* arr,int p,int q){
    int r=(p+q)/2;
    if(r-p>0)Merge_Sort(arr,p,r);
    if(q-r-1>0)Merge_Sort(arr,r+1,q);
    merge(arr,p,r,q);
}
void Quick_Sort(int* arr,int p,int q){
    int piv=arr[q],i=p,j=p-1;
    for(i=p;i<=q;i++){
        if(arr[i]<=piv){
            swap(&arr[i],&arr[j+1]);
            j++;
        }
    }
    if(j-p>0)Quick_Sort(arr,p,j-1);
    if(q-j>0)Quick_Sort(arr,j+1,q);
}
void Selection_Sort(int* arr,int p,int q){
    int i,index=p,min=arr[p];
    for(i=p;i<=q;i++){
        if(arr[i]<min){
            min=arr[i];
            index=i;
        }
    }
    swap(&arr[p],&arr[index]);
    if(q>p+1)Selection_Sort(arr,p+1,q);
}
int main(){
    int n,i,j;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n],brr[n];
    printf("Enter array:");
    for(i=0;i<n;i++)scanf("%d",&arr[i]);
    for(i=0;i<n;i++)brr[i]=arr[i];
    for(i=1;i<=6;i++){
        for(j=0;j<n;j++)arr[j]=brr[j];
        auto start = high_resolution_clock::now();
        if(i==1){Bubble_Sort(arr,0,n-1);   printf("\n\x1b[31mBubble    Sort:\x1b[0m");}
        if(i==2){Selection_Sort(arr,0,n-1);printf("\n\x1b[31mSelection Sort:\x1b[0m");}
        if(i==3){Insertion_Sort(arr,0,n-1);printf("\n\x1b[31mInsertion Sort:\x1b[0m");}
        if(i==4){Merge_Sort(arr,0,n-1);    printf("\n\x1b[31mMerge     Sort:\x1b[0m");}
        if(i==5){Quick_Sort(arr,0,n-1);    printf("\n\x1b[31mQuick     Sort:\x1b[0m");}
        if(i==6){Heap_Sort(arr,0,n-1);     printf("\n\x1b[31mHeap      Sort:\x1b[0m");}
        // print(arr,n,32);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\x1b[33mTime taken by function: \x1b[0;34m"<< duration.count() << " microseconds\x1b[0m" << endl;
    }
    return 0;
}