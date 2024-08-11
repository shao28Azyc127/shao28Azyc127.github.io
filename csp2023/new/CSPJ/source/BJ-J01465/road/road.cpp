#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100005],a[100005],ans=0,yx=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>d;
    for(long long i=1;i<n;i++)cin>>v[i],v[i]+=v[i-1];
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long i=1;i<n;i++){
        long long l=i,r=i+1;
        while(r+1<=n&&a[l]<=a[r])r++;
        long long cd=v[r-1]-v[l-1]-yx;
        ans+=ceil(1.0*cd/d)*a[l],yx=(long long)(ceil(1.0*cd/d))*d-cd;
        i=r-1;
    }
    cout<<ans;
    return 0;
}