#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d,v[N],a[N],mina=INT_MAX;long long s,minn=LONG_LONG_MAX;map<double,long long> tmp[N];
void dfs(int cur,double sum,long long ans)
{
    if(tmp[cur][sum]!=0&&tmp[cur][sum]<=ans) return;
    tmp[cur][sum]=ans;
    if(cur>n)
    {
        minn=min(minn,ans);
        return;
    }
    for(int i=0;i<=ceil(double(s)/d);i++) if(sum+i>=v[cur]/double(d)) dfs(cur+1,sum-v[cur]/double(d)+i,ans+a[cur]*i);
}
int main()
{
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) scanf("%d",&v[i]),s+=v[i];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),mina=min(mina,a[i]);
    if(mina==a[1])
    {
        cout<<ceil(double(s)/d)*a[1];
        return 0;
    }
    dfs(1,0,0);
    cout<<minn;
    return 0;
}
