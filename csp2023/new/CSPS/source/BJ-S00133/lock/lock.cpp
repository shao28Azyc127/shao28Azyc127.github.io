#include<bits/stdc++.h>
using namespace std;
int cnt[100003];
int a[105][105];
void calc(int c,int i,int j)
{
    int p=1e4,q=0;
    for(int k=1;k<=5;k++)
    {
        if(k!=j) q+=a[i][k]*p;
        else q+=(c*p);
        p/=10;
    }
    cnt[q]++;
    //cout<<q<<endl;
    return;
}
void dfs(int w,int dep)
{
    if(dep==5) return;
    for(int i=0;i<=9;i++)
    {
        if(i!=a[w][dep+1])
        {
            calc(i,w,dep+1);
        }
    }
    dfs(w,dep+1);
    return;
}
void calc1(int c1,int c2,int i,int j)
{
    int p=1e4,q=0;
    for(int k=1;k<=5;k++)
    {
        if(k==j)
        {
            q+=(c1*p);
        }
        else if(k==j+1)
        {
            q+=(c2*p);
        }
        else
        {
            q+=(a[i][k]*p);
        }
        p/=10;
    }
    cnt[q]++;
    //cout<<q<<endl;
    return;
}
void dfs1(int w,int dep)
{
    if(dep==4) return;
    for(int i=0;i<=9;i++)
    {
        if(a[w][dep+1]==i) continue;
        calc1(i,(i+(a[w][dep+2]-a[w][dep+1]+10))%10,w,dep+1);
    }
   // cout<<dep<<endl;
    dfs1(w,dep+1);
    return;
}
int main()
{
    int n;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
        dfs(i,0);
        dfs1(i,0);
    }
    int ans=0;
    for(int i=0;i<=100000;i++)
    {
        if(cnt[i]==n) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
