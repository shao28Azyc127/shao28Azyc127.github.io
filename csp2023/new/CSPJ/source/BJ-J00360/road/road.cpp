#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,k,dp[maxn],dis[maxn],v[maxn],pri[maxn],minpri[maxn];
int place(int x)
{
    int ge,pla;
    ge=x/k;
    if(x%k==0) return x;
    else
    {
        pla=k*(ge+1);
        return pla;
    }
}
int main()
{
    freopen(stdin,"w",road.in);
    freopen(stdout,"r",road.out);
    cin>>n>>k;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        dis[i]=dis[i-1]+v[i];
    }
    minpri[0]=999999;
    for(int i=1;i<=n;i++)
    {
        cin>>pri[i];
        minpri[i]=min(minpri[i-1],pri[i]);
       // if(pri[i]<minpri[i-1]) mark[i]=1;
    }

    dp[1]=0;
    dp[2]=(place(dis[2])/k)*pri[1];
    for(int i=3;i<=n;i++)
    {
        if(dis[i]<=place(dis[i-1]))
        {
            dp[i]=dp[i-1];
            continue;
        }
        dp[i]=dp[i-1]+place(dis[i]-place(dis[i-1]))/k*minpri[i-1];
    }
    cout<<dp[n]<<endl;
    return 0;
}