# include <bits/stdc++.h>

using namespace std;

const int N=2005;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

# define chkmin(a,b) (a=min(a,b))
# define chkmax(a,b) (a=max(a,b))
# define PII pair<int,int>
# define mkp make_pair
# define ull unsigned long long

template<typename T> void read(T &x){
    x=0;int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}

int type,n,m,q;
int X[N],Y[N];
int a[N],b[N];
bool f[N][N];

bool check(int x,int y){
    return 1ll*(a[1]-b[1])*(a[x]-b[y])>0;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(type),read(n),read(m),read(q);
    Rep(i,1,n)read(X[i]);
    Rep(i,1,m)read(Y[i]);
    Rep(i,1,n)a[i]=X[i];
    Rep(i,1,m)b[i]=Y[i];
    if(a[1]==b[1])printf("0");
    else{
        f[1][1]=true;
        Rep(i,1,n)
            Rep(j,1,m){
                if(!f[i][j])continue;
                if(i+1<=n&&check(i+1,j))f[i+1][j]=true;
                if(j+1<=m&&check(i,j+1))f[i][j+1]=true;
                if(i+1<=n&&j+1<=n&&check(i+1,j+1))f[i+1][j+1]=true;
            }
        if(f[n][m])printf("1");
        else printf("0");
        Rep(i,1,n)Rep(j,1,m)f[i][j]=false;
    }
    while(q--){
        int kx,ky;
        read(kx),read(ky);
        Rep(i,1,n)a[i]=X[i],b[i]=Y[i];
        while(kx--){
            int x,y;
            read(x),read(y);
            a[x]=y;
        }
        while(ky--){
            int x,y;
            read(x),read(y);
            b[x]=y;
        }
        if(a[1]==b[1])printf("0");
        else{
            f[1][1]=true;
            Rep(i,1,n)
                Rep(j,1,m){
                    if(!f[i][j])continue;
                    if(i+1<=n&&check(i+1,j))f[i+1][j]=true;
                    if(j+1<=m&&check(i,j+1))f[i][j+1]=true;
                    if(i+1<=n&&j+1<=n&&check(i+1,j+1))f[i+1][j+1]=true;
                }
            if(f[n][m])printf("1");
            else printf("0");
            Rep(i,1,n)Rep(j,1,m)f[i][j]=false;
        }
    }
    puts("");
    return 0;
}