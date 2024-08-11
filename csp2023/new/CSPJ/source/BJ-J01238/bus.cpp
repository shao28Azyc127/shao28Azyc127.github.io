#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[1000006],e[1000006],a[100006],minn=INT_MAX,maxx=INT_MIN;
void dfs(int time,int station)
{
    if(time%k==0&&station==n)
    {
        minn=min(time,minn);
        return;
    }
    else if(station==n||time>=minn)
        return;
    for(int i=1;i<=m;i++)
    {
        if(s[i]==station&&time>=a[i])
        {
            dfs(time+1,e[i]);
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {cin>>s[i]>>e[i]>>a[i];maxx=max(a[i],maxx);}
    for(int i=0;i<=maxx;i+=k)
    {

    dfs(i,1);
    if(minn!=INT_MAX)break;
    }
    if(minn==INT_MAX)
    {
        cout<<-1;
        return 0;
    }
    cout<<minn;
    return 0;
}

