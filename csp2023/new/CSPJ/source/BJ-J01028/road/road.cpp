#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long v[N],a[N];
long long sum[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long minn=1e9;
    long long ans=0;
    long long km=0;
    for(int i=1;i<n;i++){
        long long vi=sum[i]-km;
        if(minn>a[i])minn=a[i];
        long long mon=vi/m;
        if(vi%m!=0)mon++;
        km+=m*mon;
        mon*=minn;
        ans+=mon;
    }
    cout<<ans;
    return 0;
}
