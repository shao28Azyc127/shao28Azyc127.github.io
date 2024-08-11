#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>
#include<ctime>
using namespace std;
#define int long long
inline int read(){
    int i=getchar(),r=0;
    while(i<'0'||i>'9')i=getchar();
    while(i>='0'&&i<='9')r=(r<<1)+(r<<3)+(i^48),i=getchar();
    return r;
}
namespace sub1{
    //m^2
    const int N=400100;
    struct range{int l,r,v;}a[N],b[N];
    int n,m,k,d,c;
    set<int>pos;
    struct node{int l,v;};
    inline bool cmp(const node&A,const node&B){return A.l>B.l;}
    vector<node>ad[N];
    int val[N],cnt;
    inline int get_rnk(int x){
        int p=lower_bound(val+1,val+cnt+1,x)-val;
        if(val[p]==x)return p;
        else return 0;
    }
    void init(){
        pos.clear();
        c=cnt=0;
        memset(val,0,sizeof(val));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>n>>m>>k>>d;
        pos.insert(0);
        pos.insert(n);
        for(int i=1;i<=m;i++){
            int x=read(),y=read(),v=read();
            int l=x-y+1,r=x;
            val[++cnt]=r;
            val[++cnt]=l;
            a[i]={l,r,v};
            pos.insert(l-1);
            pos.insert(r);
        }
        int lst=0;
        for(int p:pos)if(p>0)b[++c]={lst+1,p,-d*(p-lst)},lst=p;
        sort(val+1,val+cnt+1);
        for(int i=1;i<=cnt;i++)ad[i].clear();
        for(int i=1;i<=m;i++)ad[get_rnk(a[i].r)].emplace_back((node){get_rnk(a[i].l),a[i].v});
    }
    int f[N];
    int t[N];
    signed main(){
        int T;cin>>T;
        while(T--){
            init();
            f[0]=0;
            memset(f,0,sizeof(f));
            memset(t,0,sizeof(t));
            for(int i=1;i<=c;i++){
                for(node j:ad[get_rnk(b[i].r)])t[j.l]+=j.v;
                int sum=0;
                f[i]=f[i-1];
                for(int j=i-1;j>=0;j--){
                    if(b[i].r-b[j].r>k)break;
                    sum+=b[j+1].v+t[get_rnk(b[j+1].l)];
                    if(j>0)f[i]=max(f[i],f[j-1]+sum);
                    else f[i]=max(f[i],sum);
                }
            }
            printf("%lld\n",f[c]);
        }
        return 0;
    }
}
namespace sub3{
    //B
    const int N=400100;
    struct range{int l,r,v;}a[N];
    inline bool cmp(const range&A,const range&B){return A.v<B.v;}
    int n,m,k,d;
    void init(){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            int x=read(),y=read(),v=read();
            int l=x-y+1,r=x;
            v-=y*d;
            a[i]={l,r,v};
        }
        sort(a+1,a+m+1,cmp);
    }
    int ans;
    signed main(){
        int t;cin>>t;
        while(t--){
            init();
            ans=0;
            for(int i=1;i<=m;i++)if(a[i].r-a[i].l+1<=k&&a[i].v>0)ans+=a[i].v;
            printf("%lld\n",ans);
        }
        return 0;
    }
}
#define TIME (clock()*1000/CLOCKS_PER_SEC)
signed main(){
    // freopen("run/run1.in","r",stdin);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c;cin>>c;
    if(c<=7||c==10||c==11||c==15||c==16){
        sub1::main();
    // cerr<<TIME;
        return 0;
    }
    if(c==17||c==18){
        sub3::main();
        return 0;
    }
    return 0;
}