#include<bits/stdc++.h>
using namespace std;
int a[100005],v[100005];
int minn[100005];
int n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    minn[0]=1e9;
    for(int i=1;i<=n;i++)minn[i]=min(minn[i-1],a[i]);
    int dy=0;
    long long ans=0;
    for(int i=1;i<n;i++){
        if(dy>v[i]){
            dy-=v[i];
            continue;
        }
        ans+=(v[i]-dy)/d*minn[i];
        if((v[i]-dy)%d){
            ans+=minn[i];
            dy=(v[i]-dy+d)%d;
        }else dy=0;
    }
    cout<<ans;
    return 0;
}
