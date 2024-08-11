/*
 hmz is cute!
----------------------------
 You've got to have faith
 Don't let them cut you down cut you down once more
*/
#include<bits/stdc++.h>
using namespace std;
#define TY long long
#define ll long long
#define db double
#define MAXN 200005
#define MAXM 200005
#define MAXK 27
#define INF (TY)(2e9)
#define mod (TY)(1e9+7)
#define IL inline
#define pb push_back
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
IL TY qr(){
    TY u=0,v=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())v=(ch=='-'?-1:1);
    for(;ch>='0'&&ch<='9';ch=getchar())u=u*10+(ch-'0');
    return u*v;
}IL void qw(TY now){
    if(now<0){putchar('-');now=-now;}
    if(!now){putchar('0');return;}
    if(now>=10)qw(now/10);putchar(now%10+'0');
}IL void qw(TY now,char c){qw(now);putchar(c);}
IL bool ischar(char c){return (c>='a'&&c<='z')||(c>='A'&&c<='Z');}
IL char getc(){
    char ch=getchar();
    while(!ischar(ch))ch=getchar();
    return ch;
}IL string qs(){
    string lst="";char ch=getc();
    while(!ischar(ch))ch=getchar();
    while(ischar(ch))lst+=ch,ch=getchar();
    return lst;
}IL void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
IL TY Mod(TY a){return (a>=mod?a-mod:a);}
IL TY Ceil(TY a,TY b){return a/b+(a%b!=0);}
IL TY Pow(TY a,TY b){
    TY ans=1,base=a;
    while(b){
        if(b&1)ans=ans*base%mod;
        base=base*base%mod;b>>=1;
    }return ans;
}TY n,a[MAXN];
signed b[MAXN],c[MAXN],num[MAXN],in[MAXN];
vector<signed> e[MAXN];
struct node{
	signed id,w;
	IL bool operator<(const node&A) const{
		return w>A.w;
	}
};multiset<node> s;
IL void Pb(signed i,signed j){e[i].pb(j);e[j].pb(i);}
IL __int128 Sum(TY a,TY b,TY len){return (__int128)(a+b)*len/2;}
IL bool calc(TY now,TY L,TY R){
	if(c[now]>=0)return Sum(L*c[now],R*c[now],R-L+1)+(R-L+1)*b[now]>=a[now];
	TY ch=(c[now]>=0?INF:Ceil(b[now],abs(c[now])));
	TY lst=max(0ll,(TY)R-max(ch,(TY)L)+1);
	if(ch>L)lst+=Sum(L*c[now]+b[now],min(ch-1,R)*c[now]+b[now],min(ch-1,R)-L+1);
	return lst>=a[now];
}IL TY Find(signed now,signed tim){
	TY l=1,r=tim,ans=0;
	while(l<=r){
		TY mid=(l+r)>>1;
		if(calc(now,mid,tim))ans=mid,l=mid+1;
		else r=mid-1;
	}return ans;
}IL bool check(signed mid){
	s.clear();
	For(i,1,n)in[i]=0;
	signed nowtim=INF,cnt=0;
	++in[1];
	For(i,1,n){
		num[i]=Find(i,mid);
		if(!num[i])return false;
		FOR(j,0,e[i].size())++in[e[i][j]];
	}For(i,1,n)if(in[i]==1)s.insert({i,num[i]});
	while(!s.empty()){
		node now=*s.begin();
		s.erase(s.begin());
		++cnt;if(cnt==n)return true;
		nowtim=min(nowtim,now.w)-1;
		if(!nowtim)return false;
		FOR(i,0,e[now.id].size()){
			TY y=e[now.id][i];
			--in[y];
			if(in[y]==1)s.insert({y,num[y]});
		}
	}return false;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    /* init */
    n=qr();For(i,1,n)a[i]=qr(),b[i]=qr(),c[i]=qr();
    FOR(i,1,n){
    	TY u=qr(),v=qr();
    	Pb(u,v);
	}signed l=0,r=1e9,ans=0;
	while(l<=r){
		TY mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}qw(ans);
    return 0;
}