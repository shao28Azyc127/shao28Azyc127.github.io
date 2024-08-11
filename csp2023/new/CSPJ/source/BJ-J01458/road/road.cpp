#include<cstdio>
#define int long long
int divide(int a,int b){
    if(a%b==0)
        return a/b;
    else
        return a/b+1;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,v[100005],a[100005];
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++)
        scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    int tot=0;
    for(int i=1;i<n;i++)
        tot+=v[i];
    printf("%lld",divide(tot,d)*a[1]);
    return 0;
}