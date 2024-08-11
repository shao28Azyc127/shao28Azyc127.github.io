#include <cstdio>
int n,m,k,u,v,w,to[2000005],a[2000005],nxt[2000005],head[1000005],cnt,l,r = 3000000,mid,ans = -1,q[1000005],ql,qr,dis[1000005];
void adde(int x,int y,int z){
    to[cnt] = y;
    a[cnt] = z;
    nxt[cnt] = head[x];
    head[x] = cnt++;
}
bool check(int x){
    for(int i = 1;i <= n * k;i++){
        dis[i] = -1;
    }
    dis[n] = x * k;
    q[ql = qr = 0] = n;
    while(ql <= qr){
        for(int i = head[q[ql]];i >= 0;i = nxt[i]){
            if(dis[to[i]] < 0 && dis[q[ql]] > a[i]){
                dis[to[i]] = dis[q[ql]] - 1;
                q[++qr] = to[i];
            }
        }
        ql++;
    }
    return dis[1] >= 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= n * k;i++){
        head[i] = -1;
    }
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&u,&v,&w);
        for(int j = 0;j < k;j++){
            adde(v + (j + 1) % k * n,u + j * n,w);
        }
    }
    while(l <= r){
        mid = l + r >> 1;
        if(check(mid)){
            ans = mid * k;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d",ans);
    return 0;
}
