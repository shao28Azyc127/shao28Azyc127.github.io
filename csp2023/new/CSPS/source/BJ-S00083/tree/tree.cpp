#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define endl "\n";
#define pii pair<int,int>
#define p1(A) A.first
#define p2(A) A.second
int n;
int lim[100300];
ll a[100300],b[100300],c[100300];
int lc[3000300<<2],rc[3000300<<2];
int tg[3000300<<2],w[3000300<<2];
int cnt=0;
int rt[100200];
const int PN=1e9;
inline void clr(){
    for(int i=1;i<=cnt;i++)
        w[i]=tg[i]=lc[i]=rc[i]=0;
    for(int i=1;i<=n;i++)
        rt[i]=0;
    cnt=0;
    memset(rt,0,sizeof(rt));
}
inline void upd(int x,int l,int r){
    w[x]=l;
    int mid=l+r>>1;
    if(lc[x])
        w[x]=min(w[x],w[lc[x]]);
    if(rc[x])
        w[x]=min(w[x],w[rc[x]]);
    w[x]-=tg[x];
}
inline void add(int &x,int l,int r,int L,int R){
    if(L<=0||R<=0||L>R)return ;
    //cout<<x<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<cnt<<endl;
    //cout.flush();
    if(!x){
        ++cnt;
        x=cnt;
        //cout<<x<<" "<<l<<endl;
        //cout.flush();
        w[x]=l;
    }
    if(L<=l&&r<=R){
    //cout<<x<<" "<<l<<" "<<r<<" "<<w[x]<<endl;
        w[x]--;
        tg[x]++;
   // cout<<x<<" "<<l<<" "<<r<<" "<<w[x]<<endl;
  //  cout.flush();
       return ;
    }
    int mid=l+r>>1;
    if(L<=mid)
        add(lc[x],l,mid,L,R);
    if(R>mid)
        add(rc[x],mid+1,r,L,R);
    upd(x,l,r);
}
inline int g(int x,int l,int r,int L,int R){
    if(L<0||R<0||L>R||!x)return L;

    if(L<=l&&r<=R){
            return w[x];}
    int res=L,mid=l+r>>1;
    if(L<=mid)res=min(res,g(lc[x],l,mid,L,R));
    if(R>mid)res=min(res,g(rc[x],mid+1,r,L,R));

    return res-tg[x];
}
inline int mg(int x,int y,int l,int r){
    if(!x||!y)return x|y;
    tg[x]+=tg[y];
    w[x]-=tg[y];
    if(l==r)return x;
    int mid=l+r>>1;
    lc[x]=mg(lc[x],lc[y],l,mid);
    rc[x]=mg(rc[x],rc[y],mid+1,r);
    upd(x,l,r);
    return x;
}
__int128_t U=1;
inline __int128_t calc(int i,int st,int ed){
    return  U*(st+ed)*(ed-st+1)/2*c[i]+(ed-st+1)*b[i];
}
inline bool chk(int i,int st,int ed){
    __int128_t res=0;
    if(c[i]>=0)
        res=calc(i,st,ed);
    else{
        int sp=(b[i]-1)/(-c[i]);
        if(sp<st)
            res=ed-st+1;
        else if(sp>=ed)
            res=calc(i,st,ed);
        else
             res=calc(i,st,sp)+ed-sp;
    }
    return res>=a[i];
}
inline int calc(int i,int LIM){
    int l=0,r=LIM;
    while(l<r){
        int mid=l+r+1>>1;
        if(chk(i,mid,LIM))
            l=mid;
        else r=mid-1;
    }
    return l;
}
inline bool FLS(int LIM){
    for(int i=1;i<=n;i++){
        lim[i]=calc(i,LIM);
        if(!lim[i])return 0;
    }
    return 1;
}
bool OK;
vector<int>G[100030];
inline bool dfs(int u,int fa){
    int mn=PN;
    for(int v:G[u])
        if(v!=fa){
            if(!dfs(v,u))return 0;
            rt[u]=mg(rt[u],rt[v],1,PN);
            mn=min(mn,lim[v]);
        }
    lim[u]=min(lim[u],g(rt[u],1,PN,mn,PN));
    //cout<<mn<<" "<<u<<" "<<lim[u]<<" "<<g(rt[u],1,PN,mn,PN)<<endl;
    if(lim[u]<=0)return 0;
    add(rt[u],1,PN,lim[u],PN);
    return 1;
}
inline bool chk(int LIM){
    if(!FLS(LIM))return 0;
    //cout<<LIM<<endl;
    //for(int i=1;i<=n;i++)
     //   cout<<lim[i]<<" ";
      //  cout<<endl;
    OK=1;
    clr();
    return dfs(1,0);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    //freopen("tree.in","r",stdin);////////////////////////////////////////////////////////
    //freopen("tree.out","w",stdout);//remember to update
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int l=n,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(chk(mid))r=mid;
        else l=mid+1;
        //cout.flush();
    }
    cout<<l<<endl;
    fflush(stdout);
    fflush(stdin);
    fflush(stdout);
    fflush(stdin);
    cout.flush();
    return 0;
}
