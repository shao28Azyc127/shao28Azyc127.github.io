#include <cstdio>
#include <cstring>
using namespace std;

template<typename T>
T max(const T &x,const T &y){
    return x>y ? x : y;
}

const int NMAX=1e3+10;
const long long INF=1e18;

long long f[NMAX][NMAX];
long long cha[NMAX][NMAX];
long long maxn[NMAX];

void foo(){
    memset(f,0,sizeof(f));
    memset(cha,0,sizeof(cha));
    int n,m,k;
    long long d;
    scanf("%d%d%d%lld",&n,&m,&k,&d);
    for (int i=0;i<m;i++){
        int x,y;
        long long v;
        scanf("%d%d%lld",&x,&y,&v);
        for (int j=y;j<=k;j++){
            cha[x][j]+=v;
        }
    }
    maxn[0]=0;
    for (int i=1;i<=n;i++) maxn[i]=-INF;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k && j<=i;j++){
            if (j==0) f[i][j]=maxn[i-1];
            else f[i][j]=f[i-1][j-1]-d+cha[i][j];
            maxn[i]=max(maxn[i],f[i][j]);
        }
    }
    printf("%lld\n",maxn[n]);
    return;
}

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for (int i=0;i<t;i++) foo();
    return 0;
}
