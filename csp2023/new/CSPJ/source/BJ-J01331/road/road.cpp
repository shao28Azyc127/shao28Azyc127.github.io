#include <bits/stdc++.h>
using namespace std;
int n,s,a[100005],f[100005],m[100005],l[100005],cnt,nd,ans;
double now,p;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&s);
    for (int i=2;i<=n;i++) {
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&m[i]);
    f[++cnt]=1;
    for (int i=2;i<=n;i++)
        if (m[i]<m[f[cnt]]) {
            l[cnt]=a[i]-a[f[cnt]];
            f[++cnt]=i;
        }
    if (f[cnt]!=n) {
        l[cnt]=a[n]-a[f[cnt]];
        f[++cnt]=n;
    }
    for (int i=1;i<cnt;i++) {
        p=(l[i]*1.0-now*s)/(s*1.0);
        nd=p;
        if (nd<p)
            nd++;
        ans+=nd*m[f[i]];
        now=nd*1.0-p;
    }
    printf("%d",ans);
    return 0;
}
