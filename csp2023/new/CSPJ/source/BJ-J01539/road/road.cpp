#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,d,a[100005],v[100005],minn[100005];
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>d;
    for(long long i=1;i<=n-1;i++) cin>>v[i];
    for(long long i=1;i<=n;i++) cin>>a[i];
    minn[0]=2e9;
    for(long long i=1;i<=n;i++)
    {
        minn[i]=min(minn[i-1],a[i]);
    }
    for(long long i=1;i<=n-1;i++)
    {
        long long now=v[i]/d*d+d;//oil
        if(v[i]%d==0) now-=d;
        ans+=now/d*minn[i];
        v[i+1]-=(now-v[i]);
    }
    cout<<ans<<endl;
    return 0;
}
