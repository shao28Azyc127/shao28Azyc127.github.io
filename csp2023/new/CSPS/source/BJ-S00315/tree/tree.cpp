#include<bits/stdc++.h>//15
using namespace std;
struct node
{
    long long a;
    int b,c,nd;
}p[100010];
vector<int> v[100010];
int tot,ans;
bool operator <(node a1,node a2)
{
    return a1.nd>a2.nd;
}
void dfs(int x,int fa)
{
    tot++;
    for(int i=1;i<=v[x].size();i++)
    {
        int y=v[x][i];
        if(y==fa) continue;
        ans=max(ans,tot+p[y].nd-1);
        dfs(y,x);
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,A=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>p[i].a>>p[i].b>>p[i].c;
        if(p[i].c!=0) A=1;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(A==0)
    {
        for(int i=1;i<=n;i++)
        {
            p[i].nd=(p[i].a%p[i].b==0)?(p[i].a/p[i].b):(p[i].a/p[i].b+1);
        }
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
        dfs(1,0);
        cout<<ans;
    }
}