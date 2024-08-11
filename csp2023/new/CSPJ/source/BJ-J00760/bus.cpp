#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,inf=1000000007;;
vector<int>e[N];
inline void Insert(int u,int v)
{
    e[u].push_back(v);
    return;
}
int ans=inf,n,m,k;
void dfs(int in,int depth)
{
    if(in==n&&!(depth%k))
    {
        ans=min(ans,depth);
        return;
    }
    for(int i=0;i<e[in].size();i++)
        dfs(e[in][i],depth+1);
    return;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        int u,v,a;
        cin >> u >> v >> a;
        Insert(u,v);
    }
    dfs(1,0);
    if(ans==inf)cout<<"-1";
    else cout<<ans;
    return 0;
}