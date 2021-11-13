#include "sort.h"
#include<stdio.h>
#include<iostream>
#include <algorithm> 
#include <chrono>
#include <vector>
using namespace std; 
using namespace std::chrono;
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
        // print(arr,n,1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\x1b[33mTime taken by function: \x1b[0;34m"                                                                                                                                                                                                                                                                                                                                                            << duration.count() << " microseconds\x1b[0m" << endl;
    }
    return 0;
}