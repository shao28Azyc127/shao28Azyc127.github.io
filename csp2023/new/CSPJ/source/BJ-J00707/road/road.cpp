#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int INF=1e9;
long long i,j,k,n,d,ans,cnt=INF,lo,flg;
long long v[N],a[N],dp[N],f[N],remain;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(i=1;i<=n-1;i++) scanf("%lld",&v[i]);
    for(i=1;i<=n-1;i++) scanf("%lld",&a[i]);///checked,O(2n);

    for(i=1;i<=n-1;i++)
    {
        f[i]=1;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[i]) break;
            f[i]++;
        }
        i+=f[i]-1;
    }///checked,O(n)
    for(i=1;i<=n-1;i++)
    {
        cnt=0;
        for(j=i;j<=i+f[i]-1;j++) cnt+=v[j];
        if(remain<cnt)
        {
            long long temp=cnt-remain;//remain to go;
            long long fz=ceil(temp/(d*1.0));
            ans+=fz*a[i];
            remain+=fz*d;
        }
        remain-=cnt;
        i+=f[i]-1;
    }
    cout<<ans;
    return 0;
}

