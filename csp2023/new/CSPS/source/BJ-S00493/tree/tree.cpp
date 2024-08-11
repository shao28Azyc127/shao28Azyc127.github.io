#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],ans=INT_MAX;
vector<int>vec[N];
bool vis[N];
int h[N],date[N];
int n;
/*void dfs(int x,int d)
{

    for(int i=1;i<=n;i++)
    {
        if(vis[i]&&d!=date[i])
        {
            h[i]=max(b[i] + x *c[i] , 1)+h[i];
        }
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        if(h[i]<a[i])
        {

            flag=0;break;
        }
    }
    if(flag)
    {
        ans=min(ans,d);
        return;
    }
    flag=1;
    if(x)
    {
        for(int i=0;i<vec[x].size();i++)
        {
            if(!vis[vec[x][i]])
            {
                flag=0;
                vis[vec[x][i]]=1;
                date[vec[x][i]]=d;
                dfs(vec[x][i],d+1);
                vis[vec[x][i]]=0;
            }
        }
    }
    if(flag) dfs(1,d+1);
}*/
int maxs=0;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n ;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    bool f=1;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        if(u!=v-1)f=0;
        maxs=max(maxs,v);
    }int tmp=0;
    if(f)
    {

        while(h[maxs]<a[maxs])
        {
            tmp++;
            h[maxs]=max(b[maxs] + tmp *c[maxs] , 1)+h[maxs];
        }
    }
    cout<<tmp+n-1;
    return 0;
}
