#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN=1010,MAXM=1e5+10;
struct Task{int x,y,v;}a[MAXM];
ll f[MAXN][MAXN];
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
bool cmp(Task aa,Task bb){return aa.x<bb.x;}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
int tid=read(),T=read();while(T--){
    int n=read(),m=read(),k=read(),d=read();
    for(int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].v=read();
    sort(a+1,a+m+1,cmp);
if(tid<=9){
    for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) f[i][j]=-1e18;
    f[0][0]=0;
    for(int i=1,p=1;i<=n;i++){
        for(int j=0;j<=k;j++) f[i][0]=max(f[i][0],f[i-1][j]);
        for(int j=1;j<=k;j++) f[i][j]=max(f[i][j],f[i-1][j-1]-d);
        while(i==a[p].x){
            for(int j=a[p].y;j<=k;j++) f[i][j]+=a[p].v;
            p++;
        }
    }
    ll ans=0;
    for(int j=0;j<=k;j++) ans=max(ans,f[n][j]);
    printf("%lld\n",ans);
}
if(tid==17||tid==18){
    ll ans=0;
    for(int i=1;i<=m;i++) if(a[i].y<=k&&(ll)a[i].y*d<a[i].v)
        ans+=(a[i].v-a[i].y*d);
    printf("%lld\n",ans);
}
}
    return 0;
}