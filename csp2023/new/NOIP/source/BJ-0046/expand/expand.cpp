#include<bits/stdc++.h>
using namespace std;
const int n1=2005;
const int n2=1e6+5;
const int inf=1e9;
struct Tree
{
    set<int> s[n2];
    int Min[n2<<2];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            s[i].clear();
            s[i].insert(inf);
        }
        for(int i=1;i<=4*n;i++) Min[i]=inf;
    }
    void pushup(int id)
    {
        Min[id]=min(Min[id<<1],Min[id<<1|1]);
    }
    void update(int id,int l,int r,int x,int w,int k)
    {
        if(l==r)
        {
            if(k==0) s[l].erase(w);
            else s[l].insert(w);
            Min[id]=(*s[l].begin());
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) update(id<<1,l,mid,x,w,k);
        else update(id<<1|1,mid+1,r,x,w,k);
        pushup(id);
    }
    int query_pos(int id,int l,int r,int x,int y)
    {
        if(x>y) return inf;
        if(l>=x && r<=y) return Min[id];
        int ret=inf,mid=(l+r)>>1;
        if(x<=mid) ret=min(ret,query_pos(id<<1,l,mid,x,y));
        if(y>mid) ret=min(ret,query_pos(id<<1|1,mid+1,r,x,y));
        return ret;
    }
    pair<int, int> query_val(int id,int l,int r,int k)
    {
        if(l==r) return make_pair(l,Min[id]);
        int mid=(l+r)>>1;
        if(k==0)
        {
            if(Min[id<<1]<inf) return query_val(id<<1,l,mid,k);
            else return query_val(id<<1|1,mid+1,r,k);
        }
        if(k==1)
        {
            if(Min[id<<1|1]<inf) return query_val(id<<1|1,mid+1,r,k);
            else return query_val(id<<1,l,mid,k);
        }
    }
};
Tree Ta,Tb;
int c,n,m,q,dp[n1][n1],a[n2],b[n2],vv[n2],len,ca[n2],cb[n2];
void zy(int x,int y)
{
    if(x>n || y>m) return;
    if(a[1]<b[1]) dp[x][y]|=(a[x]<b[y]);
    else dp[x][y]|=(a[x]>b[y]);
}
void solve()
{
    pair<int, int> p;
    int ans,x,y,px,py,k,wx,wy;
    if(a[1]==b[1])
    {
        cout<<0;
        return;
    }
    if(c<=7)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) dp[i][j]=0;
        dp[1][1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dp[i][j]==0) continue;
                zy(i+1,j);
                zy(i,j+1);
                zy(i+1,j+1);
            }
        }
        ans=dp[n][m];
    }
    else
    {
        ans=len=0;
        for(int i=1;i<=n;i++) vv[++len]=a[i];
        for(int i=1;i<=m;i++) vv[++len]=b[i];
        sort(vv+1,vv+1+len);
        len=unique(vv+1,vv+1+len)-vv-1;
        for(int i=1;i<=n;i++) a[i]=lower_bound(vv+1,vv+1+len,a[i])-vv;
        for(int i=1;i<=m;i++) b[i]=lower_bound(vv+1,vv+1+len,b[i])-vv;
        Ta.init(len),Tb.init(len);
        for(int i=1;i<=n;i++) Ta.update(1,1,len,a[i],i,1);
        for(int i=1;i<=m;i++) Tb.update(1,1,len,b[i],i,1);
        x=n,y=m,k=0;
        while(x!=0 && y!=0)
        {
            if(k==0)
            {
                p=Ta.query_val(1,1,len,1);
                wx=p.first,px=p.second;
                py=Tb.query_pos(1,1,len,wx+1,len);
                if(px>x || py>y) break;
                for(int i=px;i<=x;i++) Ta.update(1,1,len,a[i],i,0);
                for(int i=py+1;i<=y;i++) Tb.update(1,1,len,b[i],i,0);
                x=px-1,y=py;
            }
            if(k==1)
            {
                p=Tb.query_val(1,1,len,0);
                wy=p.first,py=p.second;
                px=Ta.query_pos(1,1,len,1,wy-1);
                if(px>x || py>y) break;
                for(int i=px+1;i<=x;i++) Ta.update(1,1,len,a[i],i,0);
                for(int i=py;i<=y;i++) Tb.update(1,1,len,b[i],i,0);
                x=px,y=py-1;
            }
            k^=1;
        }
        if((x==0 && y<=1) || (x<=1 && y==0)) ans=1;
    }
    cout<<ans;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int kx,ky,p,w;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>ca[i];
    for(int i=1;i<=m;i++) cin>>cb[i];
    for(int i=1;i<=n;i++) a[i]=ca[i];
    for(int i=1;i<=m;i++) b[i]=cb[i];
    solve();
    for(int i=1;i<=q;i++)
    {
        cin>>kx>>ky;
        for(int j=1;j<=n;j++) a[j]=ca[j];
        for(int j=1;j<=m;j++) b[j]=cb[j];
        for(int j=1;j<=kx;j++)
        {
            cin>>p>>w;
            a[p]=w;
        }
        for(int j=1;j<=ky;j++)
        {
            cin>>p>>w;
            b[p]=w;
        }
        solve();
    }
    cout<<'\n';
    return 0;
}
