#include<bits/stdc++.h>
using namespace std;
vector<int>v[100003];
int n;
long long N=1000000003;
struct tree
{
    long long a;
    long long b;
    long long c;
    long long day;
}t[100003];
queue<long long>q;
bool vis[100003];
void DFS(int x,long long d,long long needday)
{
    if(d==n)q.push(needday);
    vis[x]=true;
    for(auto i:v[x])
    {
        if(!vis[i])
        {
            DFS(i,d+1,max(needday,t[i].day-(n-(d+1))));
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].b>>t[i].c;
        if(t[i].b<1)t[i].b=1;
        t[i].day=t[i].a/t[i].b;
        if(t[i].a%t[i].b!=0)t[i].day++;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    long long zs=t[1].day-n;
    if(zs<0)zs=0;
    DFS(1,1,zs);
    while(!q.empty())
    {
        N=min(N,q.front());
        q.pop();
    }
    cout<<N+n;
    return 0;
}
