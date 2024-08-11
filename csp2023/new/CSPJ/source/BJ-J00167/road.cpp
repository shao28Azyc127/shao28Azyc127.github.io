#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,u[100005],a[100005],minn = 1e18;
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i = 2; i <= n; i++) scanf("%lld",&u[i]);
    for(int i = 1; i <= n; i++) u[i] = u[i-1] + u[i];
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    int ans = 0,zong = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] < minn){
            int juli = u[i];
            juli = (int)ceil((double)juli / (double)d);
            juli -= zong;
            ans = ans + minn * juli;
            zong += juli,minn = a[i];
        }
    }
    int juli = u[n];
    juli = (int)ceil((double)juli / (double)d);
    ans = ans + minn * (juli - zong);
    printf("%lld\n",ans);
    return 0;
}
