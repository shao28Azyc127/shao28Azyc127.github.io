# include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

typedef long long ll;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)
# define chkmax(a,b) (a=max(a,b))
# define chkmin(a,b) (a=min(a,b))
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

struct func{
    ll a,b,c;
    ll sum(int t){
        if(c==0)return b*t;
        if(c>0){
            // (b+c+b+t*c)*t/2
            if(5e18/t>=(b+c+b+t*c))return (b+c+b+t*c)*t/2;
            else return 2e18;
        }
        else{
            // (b-c+b-t*c)*t/2
            int t0=(b-1)/(-c);
            if(t<=t0)return (b+c+b+t*c)*t/2;
            else return (b+c+b+t0*c)*t0/2+(t-t0);
        }
    }
    int range(int j){
        int l=j,r=1e9,res=0;
        while(l<=r){
            int mid=l+r>>1;
            if(sum(mid)-sum(j)>=a)res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;
    }
}a[N];

int head[N],cnt;

struct Edge{
    int to,next;
}e[N<<1];

void add(int x,int y){
    e[++cnt]=(Edge){y,head[x]},head[x]=cnt;
}

namespace Subtask1{
    const int M=20;
    int f[1<<M];
    int g[M][M];
    void solve(){
        memset(f,0x3f,sizeof(f));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                g[i][j]=a[i+1].range(j);
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //         printf("%d%c",g[i][j],j==n-1?'\n':' ');
        f[1]=g[0][0];
        for(int S=1;S<1<<n;S++){
            if(f[S]>1e9)continue;
            int ppc=0;
            for(int i=0;i<n;i++)if(S>>i&1)ppc++;
            for(int i=0;i<n;i++)
                if(S>>i&1^1){
                    bool flag=false;
                    RepG(j,i+1){
                        int v=e[j].to;
                        if(S>>(v-1)&1){
                            flag=true;
                            break;
                        }
                    }
                    if(!flag)continue;
                    chkmin(f[S|(1<<i)],max(f[S],g[i][ppc]));
                }
        }
        int U=(1<<n)-1;
        printf("%d\n",f[U]);
    }
}

namespace Subtask2{
    void solve(){
        int ans=0;
        Rep(i,1,n)chkmax(ans,a[i].range(i-1));
        printf("%d\n",ans);
    }
}

namespace Subtask3{
    int sum[N];
    bool check(int t){
        if(a[1].sum(t)<a[1].a)return false;
        Rep(i,1,n)sum[i]=0;
        Rep(i,2,n){
            int l=1,r=n,res=-1;
            while(l<=r){
                int mid=l+r>>1;
                if(a[i].sum(t)-a[i].sum(mid)>=a[i].a)res=mid,l=mid+1;
                else r=mid-1;
            }
            // printf("%d\n",res);
            if(res==-1)return false;
            sum[res]++;
        }
        Rep(i,1,n)sum[i]+=sum[i-1];
        Rep(i,1,n)if(sum[i]>i)return false;
        return true;
    }   
    void solve(){
        // check(5);
        int l=n,r=1e9,ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(head,-1,sizeof(head));
    read(n);
    Rep(i,1,n)read(a[i].a),read(a[i].b),read(a[i].c);
    bool B=true,D=true;
    Rep(i,1,n-1){
        int x,y;
        read(x),read(y);
        add(x,y),add(y,x);
        if((x!=i)||(y!=i+1)) B=false;
        if(x!=1&&y!=1)D=false;
    }
    // Subtask1::solve();
    // Subtask2::solve();
    // printf("!!!%d\n",B);
    if(n<=20)Subtask1::solve();
    else if(B)Subtask2::solve();
    else Subtask3::solve();
    return 0;
}
/*
4
12 1 1
2 4 -1
10 3 0
7 10 -2
1 2
1 3
1 4

7
114 1 3
514 100 -2
1919 2006 -10
810 13 7
1920 100 39
114514 1919 810
100 1 1
1 2
1 3
1 4
1 5
1 6
1 7
*/