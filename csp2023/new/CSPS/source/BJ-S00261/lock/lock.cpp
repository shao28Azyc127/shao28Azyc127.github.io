#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxc=7;
const int maxn=15;
const int maxsum=1e5+5;
const int mod=10;
const int m=5;
int n,a[maxn][maxc];
bitset <maxsum> vis,nw;
inline int calc(int id){
    int res=0;
    for (int i=m;i;i--) res=res*10+a[id][i];
    return res;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    vis.set();
    scanf("%d",&n);
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            for (int k=1;k<=mod;++k){
                a[i][j]++;
                if (a[i][j]>=mod) a[i][j]-=mod;
                if (k==mod) continue;
                int sum=calc(i);
                if (!nw[sum]) nw[sum]=1;
            }
        }
        for (int j=1;j<m;++j){
            for (int k=1;k<=mod;++k){
                a[i][j]++;
                if (a[i][j]>=mod) a[i][j]-=mod;
                a[i][j+1]++;
                if (a[i][j+1]>=mod) a[i][j+1]-=mod;
                if (k==mod) continue;
                int sum=calc(i);
                if (!nw[sum]) nw[sum]=1;
            }
        }
        vis&=nw;
        nw.reset();
    }
    printf("%lld\n",vis.count());
    return 0;
}
/*
1
0 0 1 1 5

2
2 8 3 5 5
2 8 3 5 1

8
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
5 4 3 2 1
1 2 3 4 5
5 4 3 2 1

*/
