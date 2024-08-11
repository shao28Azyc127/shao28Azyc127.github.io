#include<cstdio>
int n,d,v[100005],a[100005],lft;
long long ans,minn,l;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i = 1;i < n;i++) scanf("%d",&v[i]);
    for(int i = 0;i < n;i++) scanf("%d",&a[i]);
    minn = a[0];
    l = v[1];
    for(int i = 1;i < n;i++){
        if(minn > a[i]){
            if((l - lft) % d == 0) ans += ((l - lft) / d) * minn;
                else ans += ((l - lft) / d + 1) * minn;
            lft = (l - lft) % d;
            l = v[i];
            minn = a[i];
        } else {
            l += v[i];
        }
    }
    printf("%lld",ans);
    return 0;
}