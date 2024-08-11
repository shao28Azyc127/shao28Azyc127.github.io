#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r)for(int i=(l);i>=(r);--i)
#define p_b push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
inline ll read(){
    ll x=0;
    short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int n,d;
ll a[maxn],dis[maxn];
ll cl(ll x,ll y){
    return (x+y-1)/y;
}
void slv(){
    n=read(),d=read();
    up(i,2,n)dis[i]=dis[i-1]+read();up(i,1,n)a[i]=read();
    vector<int>g;
    up(i,1,n-1){
        if(!g.size())g.p_b(i);
        else if(a[g.back()]>a[i])g.p_b(i);
    }g.p_b(n);
    ll now=0,res=0;
    int sz=g.size()-1;
    up(i,0,sz-1){
        ll x=dis[g[i+1]]-dis[g[i]]-now;
        ll y=cl(x,d);
        now-=dis[g[i+1]]-dis[g[i]],now+=y*d;
        res+=a[g[i]]*y;
    }cout<<res<<'\n';
}int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}