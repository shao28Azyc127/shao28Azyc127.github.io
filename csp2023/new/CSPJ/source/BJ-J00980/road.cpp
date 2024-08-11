#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=2100000000;
long long dis[N],pri[N];
long long ans[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    int cur=0;
    cin>>n>>d;
    int x;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        dis[i]=dis[i-1]+x;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>pri[i];
        ans[i]=INF;
    }
    ans[n]=0;
    ans[n-1]=ceil(abs(dis[n-1]-dis[n]-cur)/(d+0.0))*pri[n-1];
    cur=abs(dis[n-1]-dis[n]);
    cur%=d;
    for(int i=n-2;i>=1;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            double dis_in=ceil(abs(dis[i]-dis[n]-cur)/(d+0.0))*pri[i];
            double dis_ij=ceil(abs(dis[i]-dis[j]-cur)/(d+0.0))*pri[i];
            double dis_jn=ceil(abs(dis[j]-dis[n]-cur)/(d+0.0))*pri[j];
            long long x=(long long)dis_in%d;
            if(cur>=x)
                cur-=x;
            else cur+=x;
            ans[i]=min(min(dis_in,dis_ij+dis_jn),ans[i]+0.0);
        }
    }
    cout<<ans[1]<<endl;
    return 0;
}
