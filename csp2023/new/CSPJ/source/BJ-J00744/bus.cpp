#include<iostream>
#include<cmath>
using namespace std;
int a[1000010],b[1000010],c[1000010],s[1000010],n,ans=1e9,m;
void dfs(int step,int sum)
{
    if(b[step]==n)
    {
        ans=min(sum,ans);
        return;
    }
    for(int i=1;i<=m;i++)
    {
        if(s[i]!=1&&a[i]==b[step])
        {
            s[i]=1;
            if(sum>=c[i])
                dfs(i,sum+1);
            else
                dfs(i,c[i]);
            s[i]=0;
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int i=1;i<=m;i++)
        {
            s[i]=0;
        }
        if(a[i]==1)
        {
            s[i]=1;
            dfs(i,c[i]);
        }
    }
    if(ans%k==0)
        cout<<ans+k;
    else if(ans!=1e9)
        cout<<(ans/k)*k+k+k;
    else
        cout<<"-1";
    return 0;
}
