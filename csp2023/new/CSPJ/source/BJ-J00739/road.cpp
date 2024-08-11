#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
int n,d;
const int N = 1e5 + 10;
LL dis[N];
int a[N];
PLL f[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<n;i++) scanf("%lld",&dis[i]);
    for(int i=1;i<n;i++) dis[i] += dis[i - 1];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int minn = 1e9;
    for(int i=1;i<=n;i++) minn = min(minn,a[i]);
    if(minn = a[1]){
        printf("%lld",1ll * ceil(1.0 * dis[n - 1] / d) * a[1]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        f[i].x = 1e18;
        f[i].y = 0;
    }
    f[1].x = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            LL t = ceil(1.0 * (dis[i - 1] - dis[j - 1]) / d);
            if(f[j].y){
                t = ceil(1.0 * (dis[i - 1] - dis[j - 1] - f[j].y) / d);
                f[i].y += t * d - (dis[i - 1] - dis[j - 1]);
            }
            f[i].x = min(f[i].x,LL(f[j].x + t * a[j]));
            if(t * d > dis[i - 1] - dis[j - 1]){
                f[i].y = t * d - dis[i - 1] + dis[j - 1];
            }
        }
    }
    printf("%d",f[n].x);
    return 0;
}
