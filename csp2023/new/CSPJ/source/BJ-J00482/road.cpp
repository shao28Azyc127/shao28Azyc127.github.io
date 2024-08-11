#include <bits/stdc++.h>
using namespace std;
long long d[100005];
long long v[100005];
long long a[100005];
long long c[100005];
long long n;
long long ans=9999999999999;
long long k;
void dfs(long long s,double now,long long val)
{
    //cout<<s<<' '<<now<<' '<<val<<endl;
    if(c[s]<=val)
        return;
    else
        c[s]=val;
    if(s==n&&val<ans)
    {
        ans=min(ans,val);
        //cout<<ans<<endl;
        return;
    }
    for(long long i=s+1;i<=n;i++)
    {
        if(ceil((double)(a[i]-a[s])/(double)k)>now)
            dfs(i,ceil((double)(a[i])/(double)k)-(double)(a[i])/(double)k,val+v[s]*ceil((double)(a[i]-a[s])/(double)k-now));
        else
            dfs(i,now-ceil((double)(a[i]-a[s])/(double)k),val);
        //if(s==4&&i==5)
            //cout<<")))"<<val<<" "<<(double)(a[i])/(double)k<<' '<<now<<"))";
    }

}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n-1;i++)
        cin>>d[i];
    for(long long i=1;i<=n;i++)
        cin>>v[i];
    for(long long i=1;i<=n;i++)
        c[i]=9999999999999;
    a[1]=0;
    for(long long i=2;i<=n;i++)
        a[i]=a[i-1]+d[i-1];
    //cout<<a[n];
    ans=v[1]*ceil(a[n]/k);
    //cout<<ans;
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
