#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,a,f[10005][20005],p[10005][20005],c[10005],c2[10005];
int main() {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d %d %d",&u,&v,&a);
        p[v][++c[i]]=u;
    }
    c[1]=1;
    f[1][1]=0;
    c2[1]=1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=c[i];j++)
            for (int k=1;k<=c2[p[i][j]];k++)
                f[i][++c2[i]]=f[p[i][j]][k]+1;
    sort(f[n]+1,f[n]+c2[n]+1);
    for (int i=1;i<=c2[n];i++)
        if (f[n][i]%k==0) {
            printf("%d",f[n][i]);
            return 0;
        }
    printf("%d",-1);
    return 0;
}
