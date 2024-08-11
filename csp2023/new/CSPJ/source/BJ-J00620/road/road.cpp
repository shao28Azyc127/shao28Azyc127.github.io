#include<bits/stdc++.h>
using namespace std;
struct station{
    int v,a;
}s[100005];
int main(){
    int n,d;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for (int i=2;i<=n;i++) {
        scanf("%d",&s[i].v);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&s[i].a);
    }
    int Min=100005;
    long long ans=0,z=0;
    for (int i=1;i<n;i++) {
        Min=min(Min,s[i].a);
        if (z<s[i+1].v) {
            long long x=((long long)s[i+1].v-z)/d+(((long long)s[i+1].v-z)%d!=0);
            z=z+(long long)x*d-s[i+1].v;
            ans+=x*Min;
        }
        else z-=s[i+1].v;
    }
    printf("%lld",ans);
    return 0;
}
