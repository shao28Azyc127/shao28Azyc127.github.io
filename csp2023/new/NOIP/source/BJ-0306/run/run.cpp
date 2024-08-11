#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
// #define int long long
using namespace std;
struct chal{
    int l,r,v;
    bool operator<(const chal &x)const{
        if(r==x.r)
            return l>x.l;
        return r<x.r;
    }
}cx[100005];
long long sum,dp[1005][1005],ans;
int c,T,n,m,k,d,tx,ty,chh[1005],now;
signed main()
{
    freopen("run.in" ,"r",stdin );
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>tx>>ty>>cx[i].v;
            cx[i].r=tx,cx[i].l=tx-ty+1;
        }
        sort(cx+1,cx+1+m);
        for(int i=1;i<=m;i++)
            chh[cx[i].r]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=min(i,k);j++)
                dp[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            sum=0,now=chh[i];
            // cout<<chh[i]<<endl;
            dp[i][0]=ans;
            for(int j=1;j<=min(i,k);j++)
            {
                while(now!=0&&cx[now].r==i&&(cx[now].r-cx[now].l+1)<=j)
                    sum+=cx[now--].v;
                dp[i][j]=dp[i-1][j-1]+sum-d;
                // cout<<dp[i][j]<<" ";
                ans=max(ans,dp[i][j]);
            }
            // cout<<endl;
        }
        cout<<ans<<"\n";
    }
    return 0;
}