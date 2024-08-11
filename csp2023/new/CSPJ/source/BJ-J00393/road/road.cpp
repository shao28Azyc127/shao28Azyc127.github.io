#include <bits/stdc++.h>
using namespace std;
int v[10005],a[10005],b[10005];
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<n;i++){
        ans+=v[i];
    }
    printf("%lld",a[1]*ans);
    return 0;
}
