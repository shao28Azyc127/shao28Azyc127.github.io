#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;
int C,T;
int n,m,k;
ll f[N][N],d;
// now i day, recently run for j days-- max V
struct chal{
    int x,y;
    ll v;
}a[N];
bool cmp(chal x,chal y){
    return x.x==y.x?x.y<y.y:x.x<y.x;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        memset(f,-0x3f,sizeof(f));
        f[0][0]=0;
        scanf("%d%d%d%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++) scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].v);
        sort(a+1,a+m+1,cmp);
        int nw=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(i,k);j++){
                if(j) f[i][j]=max(f[i][j],f[i-1][j-1]-d);
                f[i][0]=max(f[i][0],f[i-1][j]);
            }
            while(a[nw].x==i){
                for(int j=a[nw].y;j<=k;j++) f[i][j]+=a[nw].v;
                nw++;
            }
        }
        ll ans=0;
        for(int i=0;i<=min(n,k);i++) ans=max(ans,f[n][i]);
        printf("%lld\n",ans);
    }
    return 0;
}
// f[i] the i(th)'s challenge -- max V
// between i and i-1 chal 