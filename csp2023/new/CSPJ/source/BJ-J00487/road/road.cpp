#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],b[100001],s[100001],op[100001],flag=0,ans=INT_MAX;
void dfs(int id,int sum,int oil,int step)
{
    if(id>=n)
    {
        ans=min(ans,sum);
        return ;
    }
    for(int i=id+1;i<=n;i++)
    {
        op[step]=i;
        if((s[i]-s[id])%m==0) dfs(i,sum+((s[i]-s[id])/m)*b[id],oil+(s[i]-s[id])/m-(s[i]-s[id]),step+1);
        else dfs(i,sum+((s[i]-s[id])/m+1)*b[id],oil+(s[i]-s[id])/m+1-(s[i]-s[id]),step+1);
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<b[1]) flag=1;
    }
    if(flag==0)
    {
        if(s[n]%m==0) cout<<(s[n]/m)*s[1];
        else cout<<(s[n]/m+1)*s[1];
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
