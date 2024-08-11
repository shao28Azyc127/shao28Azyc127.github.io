#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
#define TIME (clock()*1000/CLOCKS_PER_SEC)
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
namespace sub1{
    //n^3----n^2
    const int N=2010;
    int n,m,q;
    bool f[N][N];
    int a[N],b[N],A[N],B[N];
    inline bool calc(){
        //f_i>g_i forall
        memset(f,0,sizeof(f));
        f[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=j;k;k--){
                    if(a[i]<=b[k])break;
                    f[i][j]|=f[i-1][k-1];
                }
                for(int k=i;k;k--){
                    if(a[k]<=b[j])break;
                    f[i][j]|=f[k-1][j-1];
                }
            }
        }
        if(f[n][m])return f[n][m];
        //f_i<g_i forall
        memset(f,0,sizeof(f));
        f[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=j;k;k--){
                    if(a[i]>=b[k])break;
                    f[i][j]|=f[i-1][k-1];
                }
                for(int k=i;k;k--){
                    if(a[k]>=b[j])break;
                    f[i][j]|=f[k-1][j-1];
                }
            }
        }
        return f[n][m];
    }
    void init(){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)A[i]=a[i]=read();
        for(int i=1;i<=m;i++)B[i]=b[i]=read();
    }
    int main(){
        init();
        if(calc())printf("1");
        else printf("0");
        while(q--){
            memcpy(a,A,sizeof(a));
            memcpy(b,B,sizeof(B));
            int kx=read(),ky=read();
            for(int i=1;i<=kx;i++){
                int x=read();
                a[x]=read();
            }
            for(int i=1;i<=ky;i++){
                int x=read();
                b[x]=read();
            }
            if(calc())printf("1");
            else printf("0");
        }
        return 0;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int type;cin>>type;
    if(type<=5){
        sub1::main();
    }
}