#include <iostream>
#include <cmath>

using namespace std;
int n,m,k,d,sum=0,a[10005][10005],ans=2147483647;
void aaa(int dep,int cnt)
{
    if(dep==n)
    {
        ans=min(ans,cnt);
        return;
    }
    else if(cnt>=ans)return;
    else
    {

        for(int i=dep+1;i<=n;i++)
        {
            if(a[dep][i]!=-1)
            {
                if(a[dep][i]<=cnt)
                {
                    //if(a[dep][i]%k!=0)
                        //aaa(i,cnt+k*(a[dep][i]/k+1));
                    //else
                        //aaa(i,cnt+k*(a[dep][i]/k));
                        aaa(i,cnt+1);
                }

            }
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
        a[i][j]=-1;
    for(int i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    for(int i=1;k*i<n;i++)
    {
        aaa(1,k*i);
    }
    if(ans%k==0)
    ans=k*(ans/k);
    else
    {
        ans=k*(ans/k+1);
    }
    cout<<ans;
    /*while(l<=r)
    {
        int mid=(l+r+1)/2;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=mid;j++)
            {
                dp[i][j]=0;
            }
        }


        //cout<<dp[n][mid/b[n]];
        if(dp[n][mid]>=sum)r=mid;
        else l=mid+1;
    }*/
    return 0;
}
