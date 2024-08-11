/*
    author: honglan0301

    [abc262_h]~[mou wei ge ji de gu shi]~[noip T4]   6666666..

    2023-11-18 11:12:06
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
#define mod 998244353

int cc,T,n,m,k,d,ans;
int u[100005],v[100005],w[100005],c[400005],cntc;
vector <pair<int,int>> gx[200005];

struct tree
{
    int mxx,tagadd;
}tree[800005];

#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define m(x) tree[x].mxx
#define tg(x) tree[x].tagadd
#define md(x,y) ((x+y)>>1)
#define push_up(x) m(x)=max(m(ls(x)),m(rs(x)))
#define cz(k,p) m(p)+=k,tg(p)+=k
#define push_down(p) cz(tg(p),ls(p)),cz(tg(p),rs(p)),tg(p)=0

void build(int l,int r,int p)
{
    tg(p)=0; if(l==r) return m(p)=0,void(); int mid=md(l,r);
    build(l,mid,ls(p)); build(mid+1,r,rs(p)); push_up(p);
}
void czx(int l,int r,int x,int k,int p)
{
    if(l==r) return m(p)=k,void(); int mid=md(l,r); push_down(p);
    if(mid>=x) czx(l,mid,x,k,ls(p)); else czx(mid+1,r,x,k,rs(p)); push_up(p);
}
void cza(int l,int r,int x,int y,int k,int p)
{
    if(l>=x&&r<=y) return cz(k,p),void(); int mid=md(l,r); push_down(p);
    if(mid>=x) cza(l,mid,x,y,k,ls(p)); if(mid<y) cza(mid+1,r,x,y,k,rs(p)); push_up(p);
}
int ask(int l,int r,int x,int y,int p)
{
    if(l>=x&&r<=y) return m(p); int mid=md(l,r); push_down(p);
    if(mid>=x&&mid<y) return max(ask(l,mid,x,y,ls(p)),ask(mid+1,r,x,y,rs(p)));
    else if(mid>=x) return ask(l,mid,x,y,ls(p)); else if(mid<y) return ask(mid+1,r,x,y,rs(p));
}

signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>cc>>T;
    while(T--)
    {
        cin>>n>>m>>k>>d; cntc=ans=0;
        for(int i=1;i<=m;i++)
        {
            cin>>u[i]>>v[i]>>w[i]; swap(u[i],v[i]); u[i]=v[i]-u[i]+1;
            //cout<<u[i]<<" "<<v[i]<<" "<<w[i]<<endl;
            if(u[i]!=1) c[++cntc]=u[i]-1; c[++cntc]=v[i];
        }
        sort(c+1,c+cntc+1); cntc=unique(c+1,c+cntc+1)-c-1;
        for(int i=1;i<=m;i++) v[i]=lower_bound(c+1,c+cntc+1,v[i])-c,u[i]=lower_bound(c,c+cntc+1,u[i]-1)-c;
        for(int i=1;i<=cntc;i++) gx[i].clear();
        for(int i=1;i<=m;i++) gx[v[i]].pb(mp(u[i],w[i]));
        build(0,cntc,1); int nl=0;
        for(int i=1;i<=cntc;i++)
        {
            int dd=c[i]-c[i-1];
            int nmx=ask(0,cntc,0,i-1,1); czx(0,cntc,i,nmx,1);
            while(c[i]-c[nl]>k) czx(0,cntc,nl,-1000000000000000000,1),nl++;
            cza(0,cntc,0,i-1,-dd*d,1);
            for(auto j:gx[i])
            {
                //cout<<i<<" "<<j.fi<<" "<<j.se<<endl;
                cza(0,cntc,0,j.fi,j.se,1);
            }
            //for(int j=0;j<=i;j++) cout<<i<<" "<<j<<" "<<ask(0,cntc,j,j,1)<<endl;
            ans=max(ans,ask(0,cntc,0,i,1));
        }
        cout<<ans<<endl;
    }
}
