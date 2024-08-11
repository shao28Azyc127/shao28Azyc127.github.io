#include<bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int a[100005],b[100005],c[100005];
int nowh[100005]; //当前高度
int hvtr[100005]; //已经种树
int ans=1919810;
int n;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    int day=1;
    while(q.size())
    {
        int now=q.front();
        q.pop();
        for(int i=0;i<G[now].size();i++)
        {
            for(int j=1;j<=n;j++)
                if(hvtr[j])
                    nowh[j]+=max(b[j]+day*c[j],1);
            q.push(G[now][i]),hvtr[G[now][i]]=1;
            day++;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(nowh[i]<a[i])
            {
                flag=false;
                break;
            }
        if(flag)
        {
            ans=min(ans,day);
            return;
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    bool f=true;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        if(v!=u+1)
            f=false;
    }
    if(f) //整个图是链
    {
        int day=0;
        while(true)
        {
            bool flag=true;
            for(int i=1;i<=n;i++)
                if(nowh[i]<a[i])
                {
                    flag=false;
                    break;
                }
            if(flag)
                break;
            day++;
            //种植第day颗树
            if(day<=n)
                hvtr[day]=1;
            for(int i=1;i<=n;i++)
                if(hvtr[i])
                    nowh[i]+=max(b[i]+day*c[i],1);
        }
        cout<<day;
        return 0;
    }
    bfs(1);
    if(ans==1919810)
        cout<<n+1;
    else
        cout<<ans;
    return 0;
}
