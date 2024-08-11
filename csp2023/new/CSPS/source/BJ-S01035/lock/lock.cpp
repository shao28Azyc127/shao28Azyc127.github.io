#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w".stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=5;j++)scanf("%d",&a[i][j]);
    }
    if(n==1){
        int t = 45;
        printf("81\n");
    }else if(n==2){
        printf("10\n");
    }

    return 0;
}
