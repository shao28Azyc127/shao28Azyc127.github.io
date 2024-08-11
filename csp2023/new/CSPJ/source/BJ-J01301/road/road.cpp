#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n,d;
int u[maxn];
int sum[maxn];
int a[maxn];
int l;
ll jg,jl=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&u[i]);
        sum[i+1]=sum[i]+u[i];
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    l=1;
    for(int i=2;i<n;i++){
        if(a[i]<a[l]){
            int c=sum[i]-sum[l]-jl;
            if(c%d>0){
                c/=d;
                c++;
            }
            else c/=d;
            jg+=a[l]*c;
            jl+=c*d;
            jl-=sum[i]-sum[l];
            l=i;
        }
    }
    int c=sum[n]-sum[l]-jl;
    if(c%d>0){
        c/=d;
        c++;
    }
    else c/=d;
    jg+=a[l]*c;
    printf("%lld",jg);
    return 0;
}
