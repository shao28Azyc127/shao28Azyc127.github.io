#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long 
using namespace std;

int rd(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())f|=(ch=='-');
    for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return f?-x:x;
}

int c,t,n,m,k,d;

const int maxn=1e5+10;
const int maxm=1e5+10;

struct chllg{
    int x,y,v;
}cl[maxm];

bool check(int nu){
    int cnt=0;
    for(int i=0;i<n;++i){
        if(1&(nu>>i))++cnt;
        else cnt=0;
        if(cnt>k)return 0;
    }
    return 1;
}

int count(int nu){
    int cnt=0;
    for(int i=0;i<n;++i){
        cnt+=(1&(nu>>i));
    }
    return cnt;
}

bool ck(int nu,int x,int y){
    // int cnt=0;
    // for(int i=0;i<x;++i){
    //     if(1&(nu>>i))++cnt;
    //     else cnt=0;
    //     if(cnt==y)return 1;
    // }
    // return 0;
    if(x-y<0)return 0;
    for(int i=x-y;i<x;++i){
        if(!(1&(nu>>i)))return 0;
    }
    return 1;
}

void prt(int nu){
    for(int i=0;i<n;++i)printf("%d",(1&(nu>>i)));
    printf("\n");
}

int f[1010][1010];
int act[1010][1010];
int aact[1010][1010];

signed main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    c=rd(),t=rd();
    while(t--){
        n=rd(),m=rd(),k=rd(),d=rd();
        memset(act,0,sizeof(act));
        for(int i=1;i<=m;++i){
            cl[i].x=rd(),cl[i].y=rd(),cl[i].v=rd();
            act[cl[i].x][cl[i].y]+=cl[i].v;
            // for(int j=cl[i].y;j<=k;++j) act[cl[i].x][j]+=cl[i].v;
        }
        if(1<=c&&c<=2){
            // zhuang ya
            int ans=0;
            for(int i=0;i<(1<<n);++i){
                int eg=0;
                if(!check(i))continue;
                eg-=d*count(i);
                for(int j=1;j<=m;++j){
                    if(ck(i,cl[j].x,cl[j].y))eg+=cl[j].v;
                }
                // printf("==%d\n",eg);
                // prt(i);
                ans=max(ans,eg);
            }
            printf("%lld",ans);
        }
        if(3<=c&&c<=14){
            for(int i=0;i<=n;++i){
                for(int j=0;j<=k;++j){
                    f[i][j]=-0x3f3f3f3f3f3f3f3f;
                }
            }
            f[0][0]=0;
            // f[1][0]=0;
            for(int i=1;i<=n;++i){
                for (int j=1;j<=k;++j){
                    aact[i][j]=aact[i][j-1]+act[i][j];
                }
            }
            for(int i=1;i<=n;++i){
                // if(i>1){
                    for(int j=0;j<=k;++j){
                        f[i][0]=max(f[i][0],f[i-1][j]);
                    }
                // }
                for(int j=1;j<=k;++j){
                    f[i][j]=max(f[i][j],f[i-1][j-1]-d);
                    // printf("%lld %lld %lld %lld\n",i,j,f[i][j],act[i][j]);
                    f[i][j]+=aact[i][j];
                    // for(int k=0;k<=j;++k)f[i][j]+=act[i][k];
                }
            }
            int ans=0;
            for(int i=0;i<=k;++i)ans=max(ans,f[n][i]);
            printf("%lld\n",ans);
        }
    }

    return 0;
}