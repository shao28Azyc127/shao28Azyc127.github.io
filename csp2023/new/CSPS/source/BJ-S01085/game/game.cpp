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
#define MAXN 2000005
#define MAXM 200005
#define MAXK 27
#define INF (TY)(1e9)
#define mod (TY)(1e9+7)
#define IL inline
#define pb push_back
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
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
}string s;
TY n,ans,id[27],b[MAXN],num[MAXN],cnt[27],minR[27][2],c[27][MAXN],nxt[MAXN];
vector<TY> have[MAXN];
IL TY Find(TY id,TY w){
	TY l=0,r=(TY)(have[id].size())-1,ans=INF;
	while(l<=r){
		TY mid=(l+r)>>1;
		if(have[id][mid]<=w)ans=mid,r=mid-1;
		else l=mid+1;
	}return max(0ll,(TY)(have[id].size())-1-ans+1);
}stack<pair<TY,char> > T;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    /* init */
    s=' '+qs();n=s.size()-1;
    For(i,1,n){
    	FOR(j,0,26)if(s[i]-'a'==j)++cnt[j],c[j][i]=c[j][i-1]+1;else c[j][i]=c[j][i-1];
    	FOR(j,0,26)num[i]|=(1ll<<j)*(cnt[j]%2);
    	b[i]=num[i];
	}sort(b,b+1+n);
	For(i,0,n)num[i]=lower_bound(b,b+1+n,num[i])-b;
	if(n<=8000){
		For(i,1,n){
			while(!T.empty())T.pop();
			For(j,i,n){
				if(T.empty()||T.top().second!=s[j])T.push({j,s[j]});
				else T.pop();
				ans+=(T.empty());
			}
		}qw(ans);
	}else{
		TY maxx=70000000/n;
		For(i,1,n){
			while(!T.empty())T.pop();
			For(j,i,min(n,i+maxx)){
				if(T.empty()||T.top().second!=s[j])T.push({j,s[j]});
				else T.pop();
				ans+=T.empty();
			}
		}qw(ans);
	}
    return 0;
}