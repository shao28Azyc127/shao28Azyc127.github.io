#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int N=1e5+5;
long long n,a[N],b[N],c[N],ans=9e18,av[N],sz;
vector<int> v[N];
bool vis[N];

void dfs(int x,long long mx,int cnt)
{
    //printf("%d %d %d\n",x,mx,cnt);
    long long h=0,d=cnt-1;
    while(h<a[x])
    {
        d++;
        h+=max(b[x]+d*c[x],1ll);
    }
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]])av[++sz]=v[x][i];
    for(int i=1;i<=sz;i++)
    {
        int y=av[i];
        if(vis[y])continue;
        vis[y]=1;
        dfs(y,max(mx,d),cnt+1);
        vis[y]=0;
    }
    for(int i=0;i<v[x].size();i++)if(!vis[v[x][i]])sz--;
    if(cnt==n){
        long long mxx=max(mx,d);
        ans=min(ans,mxx);
        //printf("ans is %d\n",ans);
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vis[1]=1;
    dfs(1,0,1);
    cout<<ans;
    return 0;
}

