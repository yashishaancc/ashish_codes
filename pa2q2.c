#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int s,k,n,i,j;
    scanf("%d",&s);
    for(k=1;k<=s;k++){
        scanf("%d",&n);
        int h[n],jb[n];
        for(i=0;i<n;i++){
            scanf("%d",&h[i]);
            jb[i]=0;
            for(j=i;j>=0;j--){
                if(h[j]>h[i])break;
                jb[i]++;
            }
            printf("%d\n",jb[i]);
        }
    }
    return 0;
}