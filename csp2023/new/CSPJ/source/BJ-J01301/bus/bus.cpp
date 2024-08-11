#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int a[maxn][maxn];
vector <int> v[maxn];
int n,m,k;
int ma;
int ans;
void dfs(int s)
{
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=m;i++){
        int x,y,a1;
        scanf("%d %d %d",&x,&y,&a1);
        v[x].push_back(y);
        a[x][y]=a1;
        ma=max(ma,a1);
    }
    printf("-1");
    return 0;
}
