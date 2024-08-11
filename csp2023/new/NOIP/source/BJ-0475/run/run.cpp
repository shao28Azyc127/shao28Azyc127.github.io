#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int N=1e5+10;
const ll inf=1e18;
char AAA;
int n,m,k,d;
struct Q
{
    int l,r,w;
}q[N];
vector<int> p[N<<1];
int nums[N<<1],vn;

ll mx[N<<3],add[N<<3];
char BBB;
void build(int u,int l,int r)
{
    mx[u]=0,add[u]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}

void mt(int u,ll o)
{
    add[u]+=o,mx[u]+=o;
}

void pushdown(int u)
{
    if(add[u]!=0)
    {
        mt(u<<1,add[u]),mt(u<<1|1,add[u]);
        add[u]=0;
    }
}

void modify(int u,int l,int r,int ql,int qr,ll o)
{
    if(ql<=l&&r<=qr)
    {
        mt(u,o);
        return;
    }
    int mid=l+r>>1;
    pushdown(u);
    if(ql<=mid) modify(u<<1,l,mid,ql,qr,o);
    if(qr>mid) modify(u<<1|1,mid+1,r,ql,qr,o);
    mx[u]=max(mx[u<<1],mx[u<<1|1]);
}

ll query(int u,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr) return mx[u];
    pushdown(u);
    int mid=l+r>>1;
    ll res=-inf;
    if(ql<=mid) res=max(res,query(u<<1,l,mid,ql,qr));
    if(qr>mid) res=max(res,query(u<<1|1,mid+1,r,ql,qr));
    return res;
}

ll f[N<<1];
void solve(int T)
{
    vn=0;
    scanf("%d%d%d%d",&n,&m,&k,&d);
    for(int i=0;i<=n*2;i++) f[i]=0;
    nums[vn++]=1;
    nums[vn++]=n;
    for(int i=1;i<=m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        nums[vn++]=x;
        nums[vn++]=x-y+1;
        q[i]={x-y+1,x,v};
    }
    sort(nums,nums+vn);
    vn=unique(nums,nums+vn)-nums;
    for(int i=0;i<vn;i++) p[i].clear();
    for(int i=1;i<=m;i++)
    {
        q[i].l=lower_bound(nums,nums+vn,q[i].l)-nums;
        q[i].r=lower_bound(nums,nums+vn,q[i].r)-nums;
        p[q[i].r].push_back(i);
    }
    build(1,0,vn);
    for(int i=0;i<vn;i++)
    {
        f[i]=max(f[i],f[i-1]);
        modify(1,0,vn,0,i,-1LL*d*(nums[i]-(i>0? nums[i-1]:0)));
        if(i>1) modify(1,0,vn,i,i,f[i-2]);
        for(int id:p[i])
        {
            int l=q[id].l,r=q[id].r,w=q[id].w;
            modify(1,0,vn,0,l,w);
        }
        int l=upper_bound(nums,nums+vn,nums[i]-k)-nums;
        if(l<=i) f[i]=max(f[i],query(1,0,vn,l,i));
    }
    printf("%lld\n",f[vn-1]);
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
//    cout<<(abs(&AAA-&BBB)/1024.0/1024.0)<<endl;
    int C,T;
    scanf("%d%d",&C,&T);
    while(T--) solve(T);

    return 0;
}
