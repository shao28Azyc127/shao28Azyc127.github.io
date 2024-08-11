#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int dp[100005];
int n, d;
int v[100005];
int a[100005];
int minn=1e9;
int minm=0;
float c;

int check(int l)
{
    int num;
    num=l/d;
    if(l%d!=0)
    {
        num++;
        c+=num-(float)l/(float)d;
    }
    return num;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    for(int i=1; i<=n-1; i++)
    {
        int k;
        cin>>k;
        v[i]=v[i-1]+k;
    }
    int sum[100005];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i==n) continue;
        int num;
        num=v[i]/d;
        if(v[i]%d!=0)
        {
            num++;
        }
        sum[i]=num;
    }
    dp[1]=a[1]*sum[1];
    minn=dp[1];
    minm=1;
    for(int i=2; i<n; i++)
    {
        if(a[i]<minn)
        {
            minn=a[i];
            minm=i;
        }
        dp[i]=dp[minm-1]+check(v[i]-v[minm-1])*minn;
        if(c>=1)
        {
            dp[i]-=(int)c*a[i];
            c=0;
        }
    }
    if(c>=1)
    {
        dp[n-1]-=(int)c*a[n-1];
    }
    cout<<dp[n-1];

}
