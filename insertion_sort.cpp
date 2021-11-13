#include<stdio.h>
#include<iostream>
#include <algorithm> 
#include <chrono> 
#include <vector>
using namespace std; 
using namespace std::chrono;
void print(int *arr,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Insertion_Sort(int* arr,int p,int q){
    if(q>1)Insertion_Sort(arr,0,q-1);
    int i=q-1,temp;
    while(q>p&&arr[q]<arr[i]){
        temp=arr[q];
        arr[q]=arr[i];
        arr[i]=temp;
        q--;
        i--;
    }
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
    auto start = high_resolution_clock::now();
    Insertion_Sort(arr,0,n-1);
    // print(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\x1b[33mTime taken by function: \x1b[0;34m"<< duration.count() << " microseconds\x1b[0m" << endl;
    return 0;
}