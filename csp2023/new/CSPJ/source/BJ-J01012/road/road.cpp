#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,small[100005];
ll d,oil[100005],v[100005],w[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)cin>>v[i],w[i+1]=w[i]+v[i],oil[i+1]=(w[i+1]+d-1)/d;
    for(int i=1;i<=n;i++)cin>>a[i];
    small[1]=1;
    for(int i=2;i<=n;i++)small[i]=(a[i]<a[small[i-1]]?i:small[i-1]);
    int p=n;
    ll ans=0;
    while(p>1){
        ans+=(oil[p]-oil[small[p-1]])*a[small[p-1]];//small[p]->p
        p=small[p-1];
    }
    cout<<ans;
    return 0;
}
//new T2 way   100+100+100+50(1~5,6~7,11~13)=350   by wanglexi at 2023-10-21 Sat 11:45