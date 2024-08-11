#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 998244353
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define maxn 1000010
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,m,tot,p[maxn],lst[maxn],v[maxn];

int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
void merge(int x,int y)
{
    int px=find(x),py=find(y);
    p[px]=py;
}

void solve()
{
    n=read(),m=read(),tot=n+3;
    int N=3*n;
    fup(i,1,N) lst[i]=0,v[i]=0;
    fup(i,1,3*N) p[i]=i;

    fup(i,1,n) v[i]=i;
    merge(n+1+N+N,n+1+N),merge(n+2,n+2+N+N),merge(n+3,n+3+N);
    //cout<<lst[N-2]<<' '<<lst[N-1]<<' '<<lst[N]<<endl;
    fup(o,1,m)
    {
        string cmd;
        cin>>cmd;
        int x,y;
        if(isupper(cmd[0]))
        {
            char c=cmd[0];
            x=read();
            if(c=='T')
            {
                int a=n+1,b=++tot;
                merge(a,b);
                merge(a+N,b+N);
                merge(a+N+N,b+N+N);
                v[x]=b;
            }
            else if(c=='F')
            {
                int a=n+2,b=++tot;
                merge(a,b);
                merge(a+N,b+N);
                merge(a+N+N,b+N+N);
                v[x]=b;
            }
            else
            {
                int a=n+3,b=++tot;
                merge(a,b);
                merge(a+N,b+N);
                merge(a+N+N,b+N+N);
                v[x]=b;
            }
        }
        else if(cmd[0]=='+')
        {
            x=read(),y=read();
            int a=v[y],b=++tot;
            merge(a,b);
            merge(a+N,b+N);
            merge(a+N+N,b+N+N);
            v[x]=b;
        }
        else
        {
            x=read(),y=read();
            int a=v[y],b=++tot;
            merge(a+N,b);
            merge(a,b+N);
            merge(a+N+N,b+N+N);
            v[x]=b;
        }
    }
    fup(i,1,n)
    {
        int a=v[i],b=i;
        merge(a,b);
        merge(a+N,b+N);
        merge(a+N+N,b+N+N);
    }

    int ans=0;
    fup(i,1,n)
    {
        int a=i;
        int px=find(a),py=find(a+N);
        if(px==py) ans++;
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int fhjd=read(),T=read();
    while(T--) solve();

    return 0;
}
