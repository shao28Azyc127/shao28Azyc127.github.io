#include<bits/stdc++.h>
using namespace std;
int n,d,v[100001],a[100001],k;
long long ans,lu;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++) scanf("%d",&v[i]);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    while (a[1]<a[k-1]) lu+=v[k++];
    if (lu%d==0) ans+=lu/d*a[1];
    else ans+=ceil(lu/d*1.0)*a[1];
    lu=0;
    for (int i=k;i<=n;i++){
        lu=0;
        while (a[i]<a[k-1]) lu+=v[k++];
        if (lu%d==0) ans+=lu/d*a[i];
        else ans+=ceil(lu/d*1.0)*a[i];
        i=k;
    }
    cout<<ans;
    return 0;
}
