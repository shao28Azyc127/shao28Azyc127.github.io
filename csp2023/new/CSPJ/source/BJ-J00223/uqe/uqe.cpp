#include<bits/stdc++.h>
using namespace std;
int m,t;
int a[10000][5];
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&m,t);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
    for(int i=1;i<=m;i++)
        if(a[i][2]==0&&a[i][3]==0)
            printf("0");
    return 0;
}
