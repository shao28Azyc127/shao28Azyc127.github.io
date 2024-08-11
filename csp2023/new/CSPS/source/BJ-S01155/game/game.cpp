# include <bits/stdc++.h>

using namespace std;

const int N=2e6+5;
const int M=26;

typedef long long ll;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)
# define PII pair<int,int>
# define mkp make_pair

template<typename T> void read(T &x){
    x=0;int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}

int n;
char s[N];
int a[N];
int f[N],lft[N];
int lst[N][M];
ll ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    read(n);
    scanf("%s",s+1);
    Rep(i,1,n)a[i]=s[i]-'a';
    Rep(i,1,n){
        lft[i]=lst[i-1][a[i]]-1;
        if(lft[i]!=-1){
            f[i]=f[lft[i]]+1;
            Rep(j,0,25)lst[i][j]=lst[lft[i]][j];
        }
        lst[i][a[i]]=i;
    }
    // Rep(i,1,n)printf("%d ",lft[i]);
    // puts("");
    // Rep(i,1,n)printf("%d ",f[i]);
    // puts("");
    Rep(i,1,n)ans+=f[i];
    printf("%lld\n",ans);
    return 0;
}