#include <cstdio>
#include <algorithm>
using namespace std;

int rd(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())f|=(ch=='-');
    for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return f?-x:x;
}

int c,n,m,q;
const int maxn=5e5+10;
int a[maxn],b[maxn];
int aa[maxn],bb[maxn];
// int px[maxn],vx[maxn],py[maxn],vy[maxn];

int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=rd(),n=rd(),m=rd(),q=rd();
    for(int i=1;i<=n;++i){
        a[i]=rd();
    }
    for(int i=1;i<=m;++i){
        b[i]=rd();
    }
    if(c==1){
        if(a[1]!=b[1])printf("1");
        else printf("0");
        for(int i=1;i<=q;++i){
            for(int j=1;j<=n;++j)aa[j]=a[j];
            for(int j=1;j<=m;++j)bb[j]=b[j];
            int kx=rd(),ky=rd();
            for (int j=1;j<=kx;++j){
                int px=rd(),vx=rd();
                aa[px]=vx;
            }
            for (int j=1;j<=ky;++j){
                int px=rd(),vx=rd();
                bb[px]=vx;
            }

            if(a[1]!=b[1])printf("1");
            else printf("0");
        }
    }

    return 0;
}