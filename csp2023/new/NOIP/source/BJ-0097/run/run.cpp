#include <cstdio>
#include <algorithm>
using namespace std;
int c,t,n,m,k,d;
long long dp[2][100005],mx;
struct node{
    int x,y,v;
}a[100005];
bool operator<(node n1,node n2){
    return n1.x < n2.x;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c <= 11){
        while(t--){
            scanf("%d%d%d%d",&n,&m,&k,&d);
            for(int i = 1;i <= m;i++){
                scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
            }
            sort(a + 1,a + 1 + m);
            for(int i = 0;i <= k;i++){
                dp[0][i] = dp[1][i] = -1e18;
            }
            dp[0][0] = 0;
            for(int i = 1,o = 1;i <= m;i++,o ^= 1){
                mx = -1e18;
                for(int j = 0;j <= k;j++){
                    mx = max(mx,dp[!o][j]);
                }
                for(int j = 0;j <= k;j++){
                    if(j < a[i].x - a[i - 1].x){
                        if(j < a[i].y){
                            dp[o][j] = mx - 1LL * j * d;
                        }
                        else{
                            dp[o][j] = mx - 1LL * j * d + a[i].v;
                        }
                    }
                    else if(j < a[i].y){
                        dp[o][j] = dp[!o][j - a[i].x + a[i - 1].x] - 1LL * (a[i].x - a[i - 1].x) * d;
                    }
                    else{
                        dp[o][j] = dp[!o][j - a[i].x + a[i - 1].x] - 1LL * (a[i].x - a[i - 1].x) * d + a[i].v;
                    }
                }
            }
            mx = -1e18;
            for(int i = 0;i <= k;i++){
                mx = max(mx,dp[m & 1][i]);
            }
            printf("%lld\n",mx);
        }
    }
    else{
        while(t--){
            scanf("%d%d%d%d",&n,&m,&k,&d);
            mx = 0;
            for(int i = 1;i <= m;i++){
                scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
                if(a[i].y <= k && a[i].v - 1LL * a[i].y * d > 0){
                    mx += a[i].v - 1LL * a[i].y * d;
                }
            }
            printf("%lld\n",mx);
        }
    }
    return 0;
}
