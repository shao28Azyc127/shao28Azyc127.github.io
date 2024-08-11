#include<iostream>
#include<cstdio>
using namespace std;
long long n,d,a[100010],b[100010],now=9e18,ans;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++) {
        now=min(now,b[i]);
        ans+=now*((a[i]+3)/4);
        a[i+1]-=4-((a[i]+3)%4+1);
    }
    cout<<ans<<"\n";
    return 0;
}