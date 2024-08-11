#include <bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    long long cnt=0;
    for(int i=1;i<n;i++)cnt+=v[i];
    int q=ceil((double)cnt/d);
    cnt=q*a[1];
    cout<<cnt;
    return 0;
}
