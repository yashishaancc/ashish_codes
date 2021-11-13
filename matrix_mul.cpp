#include<stdio.h>
// void Mat_mul(int** A,int** B,int** C,int n){
//     int i,j,k,sum;
//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             sum=0;
//             for(k=0;k<n;k++){
//                 sum+=A[i][k]*B[k][j];
//             }
//             C[i][j]=sum;
//         }
//     }
// }
int main(){
    int n,i,j,k,max_sum;
    printf("Enter side length of square Matrix:");
    scanf("%d",&n);
    int A[n][n],B[n][n],C[n][n];
    printf("Enter 1st matrix of %dx%d:\n",n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter 2nd matrix of %dx%d:\n",n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&B[i][j]);
        }
    }
    // Mat_mul(A,B,C,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            C[i][j]=0;
            for(k=0;k<n;k++)C[i][j]+=A[i][k]*B[k][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}