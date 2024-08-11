#include <bits/stdc++.h>
using namespace std;
int now=1000000000,x,k;
int a[100010],d,n;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (int i=1; i<n; i++) scanf("%d",&a[i]);
    for (int i=1; i<n; i++){
        scanf("%d",&k);
        now=min(now,k);
        int tmp=(a[i]-x+d-1)/d;
        ans+=1ll*tmp*now;
        x=tmp*d-a[i]+x;
    }
    cout<<ans;
    return 0;
}
