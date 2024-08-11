//tiny hopeless thing--a piece of s**t
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pf push_front
using namespace std;
inline ll read(){
    ll k=0,flag=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')flag=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=(k<<1)+(k<<3)+(c^48);
        c=getchar();
    }
    return k*flag;
}
inline void print(ll n){
    if(n<0){
        putchar('-');
        n=-n;
    }
    if(n>9)print(n/10);
    putchar(n%10+'0');
    return ;
}
inline void fre(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);//"W"
}
const int N=2e5+10;
ll n,m,k,u,v,a,di[N];
vector<pll>g[N];
inline void dfs(int x,ll dis){
    if(x==n){
	flag=1;
	return ;
    }
    for(auto i:g[x]){
	if(x+d<i.fi)continue;
	di[x]=min(di[x],dis+d);
	dfs(i.se,dis+d);
    }
}
int main(){
    memset(di,0x7f,sizeof di);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
	u=read(),v=read(),w=read();
	g[u].pb({w,v});
    }
    dfs(1,0);
    if(!flag)cout<<"-1";
    else cout<<di[n];
    return 0;
}
