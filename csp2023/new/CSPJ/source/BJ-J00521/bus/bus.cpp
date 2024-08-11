#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long ll;
ll n,m,k,x,y,z,minans=1e18,amax=-1e18;
struct node
{
    ll v,a;
};
struct node2
{
    ll now;
    ll time;
};
vector<node> v[10010];
queue<node2> q;
bool flag=false;

void dfs(ll nows,ll times)
{
    q.push(node2{nows,times});
    while(!q.empty())
    {
        node2 t=q.front();q.pop();
        if(t.now==n&&t.time%k==0)
        {
            minans=min(minans,t.time);
            return;
        }
        if(t.time>minans) return;
        for(int i=0;i<v[t.now].size();i++)
        {
            if(v[t.now][i].a>t.time) continue;
            q.push(node2{v[t.now][i].v,t.time+1});
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        v[x].push_back(node{y,z});
        if(y==n) flag=true;
        amax=max(amax,z);
    }
    if(flag==false)
    {
        cout<<-1;
        return 0;
    }
    dfs(1,0);
    if(minans!=1e18)
    {
        cout<<minans;
        return 0;
    }
    for(int i=k;i<=amax;i+=k)
    {
//        cout<<i<<endl;
        dfs(1,i);
        if(minans!=1e18)
        {
            cout<<minans;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
