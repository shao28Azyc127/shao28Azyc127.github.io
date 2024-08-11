#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int N=1e5+5;
int n;
int a[N],b[N],c[N];
vector<int> vec[N];
int mark[N];
int ans;
void dfs(int key,int dep)
{
    int i,j;
    mark[key]=dep;
    for(i=0; i<vec[key].size(); i++)
        if(mark[vec[key][i]]==0)
            dfs(vec[key][i],dep+1);
    return;
}
void check()
{
    int i;
    for(i=1; i<=n; i++)
    {
        int x=mark[i]-1;
        int h=0;
        while(h<a[i])
        {
            x++;
            h+=max(b[i]+x*c[i],(int)1);
        }
        ans=max(ans,x);
    }
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int i,j;
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(i=1; i<n; i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,1);
    check();
    printf("%lld",ans);
    return 0;
}
/*
5
5 5 -3
4 1 -1
3 2 0
3 3 0
4 4 0
1 2
2 3
3 4
4 5
*/
