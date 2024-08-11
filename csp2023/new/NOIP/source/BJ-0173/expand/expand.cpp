#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 500005
typedef pair<int,int> pii;
int c,n,m,q;
int a[MAXN],b[MAXN];
vector<pii> sa,sb;
inline int read(){
    int w=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        w=w*10+ch-'0';
        ch=getchar();
    }
    return w*f;
}
namespace work1{
    bool f[2005][2005],g[2005][2005];
    void work(){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0][0]=1;
        g[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=(a[i]>b[j]&&(f[i-1][j-1]||f[i][j-1]||f[i-1][j]));
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j]=(a[i]<b[j]&&(g[i-1][j-1]||g[i][j-1]||g[i-1][j]));
            }
        }
        if(f[n][m]||g[n][m]) printf("1");
        else  printf("0");
    }
    void solve(){
        work();
        while(q--){
            sa.clear(),sb.clear();
            int kx,ky;
            kx=read(),ky=read();
            for(int p,x,i=1;i<=kx;i++){
                p=read(),x=read();
                sa.push_back({p,a[p]});
                a[p]=x;
            }
            for(int p,x,i=1;i<=ky;i++){
                p=read(),x=read();
                sb.push_back({p,b[p]});
                b[p]=x;
            }
            work();
            for(auto v:sa) a[v.first]=v.second;
            for(auto v:sb) b[v.first]=v.second;
        }
    }
}
namespace work2{
    bool work1(){
        int j=1;
        if(a[1]>=b[1]) return 0;
        for(int i=1;i<=n;i++){
            while(j+1<=m&&b[j+1]>a[i]) j++;
            while(j&&b[j]<=a[i]) j--;
            if(!j) return 0;
        }
        if(j==m) return 1;
        else return 0;
    }
    bool work2(){
        int j=1;
        if(a[1]<=b[1]) return 0;
        for(int i=1;i<=n;i++){
            while(j+1<=m&&b[j+1]<a[i]) j++;
            while(j&&b[j]>=a[i]) j--;
            if(!j) return 0;
        }
        if(j==m) return 1;
        else return 0;
    }
    void solve(){
        printf("%d",bool(work1()||work2()));
        while(q--){
            sa.clear(),sb.clear();
            int kx,ky;
            kx=read(),ky=read();
            for(int p,x,i=1;i<=kx;i++){
                p=read(),x=read();
                sa.push_back({p,a[p]});
                a[p]=x;
            }
            for(int p,x,i=1;i<=ky;i++){
                p=read(),x=read();
                sb.push_back({p,b[p]});
                b[p]=x;
            }
            printf("%d",bool(work1()||work2()));
            for(auto v:sa) a[v.first]=v.second;
            for(auto v:sb) b[v.first]=v.second;
        }
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=read(),n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    if(n<=2005) work1::solve();
    else work2::solve();
    return 0;
}