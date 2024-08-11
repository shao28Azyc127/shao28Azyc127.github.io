# include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

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

int type,T;
int n,m;
PII a[N];
// T n+1,F n+2,U n+3
int fa[N<<1];
bool U[N<<1];

int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

void merge(int x,int y){
    fa[find(x)]=find(y);
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read(type),read(T);
    while(T--){
        read(n),read(m);
        Rep(i,1,n+3)a[i]=mkp(i,1);
        Rep(i,1,n*2)fa[i]=i,U[i]=false; 
        Rep(i,1,m){
            char opt[10];
            int x,y;
            scanf("%s",opt);
            if(opt[0]=='+'){
                read(x),read(y);
                a[x]=a[y];
            }
            if(opt[0]=='-'){
                read(x),read(y);
                a[x]=a[y];
                a[x].second*=-1;
            }
            if(opt[0]=='T'){
                read(x);
                a[x]=mkp(n+1,1);
            }
            if(opt[0]=='F'){
                read(x);
                a[x]=mkp(n+2,1);
            }
            if(opt[0]=='U'){
                read(x);
                a[x]=mkp(n+3,1);
            }
        }
        Rep(i,1,n)
            if(a[i].second==-1)
                if(a[i].first==n+1)a[i]=mkp(n+2,1);
                else if(a[i].first==n+2)a[i]=mkp(n+1,1);
                else if(a[i].first==n+3)a[i]=mkp(n+3,1);
        Rep(i,1,n){
            if(a[i].first>n)continue;
            if(a[i].second==1){
                merge(i,a[i].first);
                merge(i+n,a[i].first+n);
            }
            else{
                merge(i,a[i].first+n);
                merge(i+n,a[i].first);
            }
        }
        Rep(i,1,n){
            if(find(i)==find(i+n))U[find(i)]=true;
            else if(a[i].first==n+3)U[find(i)]=U[find(i+n)]=true;
        }
        int ans=0;
        Rep(i,1,n)if(U[find(i)]||U[find(i+n)])ans++;
        printf("%d\n",ans);
    }
    return 0;
}