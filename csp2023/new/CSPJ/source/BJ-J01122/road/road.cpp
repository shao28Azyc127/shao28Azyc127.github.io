#include<bits/stdc++.h>
using namespace std;
long long n,d,v[100001],a[100001],lzp,lzx,lzy;
long long jl[100001];
void solve(){
    for(int i=1;i<=n;i++){
        int j;
        for(j=i+1;j<=n;j++){
            if(a[j]<a[i]){
            lzx=jl[j]-jl[i]-lzp;
            lzp=0;
            if(lzx%d==0)lzy+=lzx/d*a[i];
            else{
                lzy+=(lzx/d+1)*a[i];
                lzp+=d-lzx%d;
            }
            break;
            }
            if(j==n){
                lzx=jl[j]-jl[i]-lzp;
                if(lzx%d==0)lzy+=lzx/d*a[i];
                else lzy+=(lzx/d+1)*a[i];
                return;
            }
        }
        i=j-1;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
        jl[i+1]=jl[i]+v[i];
    }
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    solve();
    printf("%lld",lzy);
    return 0;
}
