#include<bits/stdc++.h>
using namespace std;
struct tz{
    int l,r,w;
} a[100005];
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    /*if (c<=2) {
        while (t--) {
            memset(dp,0,sizeof(dp));
            int n,m,k,d;
            scanf("%d %d %d %d",&n,&m,&k,&d);
            for (int i=1;i<=m)
        }
    }*/
    if (c==17 ||c==18) {
        while (t--) {
            int n,m,k,d;
            long long ans=0;
            scanf("%d %d %d %d",&n,&m,&k,&d);
            for (int i=1;i<=m;i++) {
                int x,y,z;
                scanf("%d %d %d",&x,&y,&z);
                if ((long long)y*d<=z && y<=k) ans+=z-y*d;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
