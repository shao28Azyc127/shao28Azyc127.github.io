#include<bits/stdc++.h>
using namespace std;
int n,d,k=1,oil,ans,a[100001],csp[100001],v[100001];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>csp[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) v[i]=v[i-1]+csp[i-1];
    while(k<n) {
        int t=k;
        while(t<n && a[t]>=a[k]) t++;
        ans+=(a[k]*((v[t]-v[k]-oil+d-1)/d));
        oil=(v[t]-v[k]-oil)%d;
        k=t;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
