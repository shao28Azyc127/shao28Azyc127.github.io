#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#define TY ll
#define MAXN 102
#define MAXM 2002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
#define EDG(i,u) for(TY i=hed[u];i;i=nxt[i])
#define ALL(i,st) for(it=st.begin();it!=st.end();++it)
using namespace std;
typedef long long ll;
inline TY maxn(TY a,TY b){return a>b?a:b;}
inline TY minn(TY a,TY b){return a<b?a:b;}
inline TY _abs(TY a){return a<0?-a:a;}
inline void updmx(TY &a,const TY b){if(a<b)a=b;}
inline void updmn(TY &a,const TY b){if(a>b)a=b;}
TY qr(){
	TY x=1,s=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');
	if(ch)putchar(ch);
}TY T,ct=4,mem,ar[MAXN],pr[MAXN],sz,ps;string name[MAXN];
string str,out;map<string,TY>mp,kdmp;char s[MAXM];
struct node{
	map<string,TY>mp;string name[MAXN];
	TY ln,mx,ar[MAXN],sz,pr[MAXN];
}kinds[MAXN];
void newstruct(){
	cin>>str;kdmp[str]=++ct;
	node &res=kinds[ct];
	res.sz=qr();TY vl,L=0;
	FOR(i,1,res.sz){
		cin>>str;res.ar[i]=vl=kdmp[str];
		res.pr[i]=L=(L+kinds[vl].mx-1)/kinds[vl].mx*kinds[vl].mx;
		updmx(res.mx,kinds[vl].mx);L+=kinds[vl].ln;
		cin>>str;res.mp[str]=i;res.name[i]=str;
	}res.ln=(L+res.mx-1)/res.mx*res.mx;
	qw(res.ln,' ');qw(res.mx,'\n');
}TY findans(TY id){
	if(!s[ps])return 0;str.clear();
	for(++ps;s[ps]&&s[ps]!='.';)str+=s[ps++];
	TY vl=kinds[id].mp[str],ans;
//	cout<<id<<'-'<<str<<' '<<vl<<' '<<kinds[id].mx<<'\n';
	ans=findans(kinds[id].ar[vl]);
	return kinds[id].pr[vl]+ans;
}void findpth(TY id){
//	qw(id,'-');qw(ps,'\n');
	if(kinds[id].ln<=ps){str="ERR";return;}
	if(id<5)return;node &res=kinds[id];
	FOR(i,1,res.sz){
		if(i<res.sz&&ps>=kinds[id].pr[i+1])continue;ps-=kinds[id].pr[i];
		str+='.';str+=res.name[i];findpth(res.ar[i]);return;
	}
}int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	kinds[kdmp["byte"]=1].ln=kinds[1].mx=1;
	kinds[kdmp["short"]=2].ln=kinds[2].mx=2;
	kinds[kdmp["int"]=3].ln=kinds[3].mx=4;
	kinds[kdmp["long"]=4].ln=kinds[4].mx=8;
	T=qr();while(T--){
		switch(qr()){
			case 1:newstruct();break;
			case 2:cin>>str;ar[++sz]=ps=kdmp[str];
				pr[sz]=mem=(mem+kinds[ps].mx-1)/kinds[ps].mx*kinds[ps].mx;qw(mem,'\n');
				mem+=kinds[ar[sz]].ln;cin>>str;name[sz]=str;mp[str]=sz;break;
			case 4:ps=qr();str="ERR";
				FOR(i,1,sz){
					if(i<sz&&ps>=pr[i+1])continue;
					str=name[i];ps-=pr[i];findpth(ar[i]);break;
				}cout<<str<<'\n';break;
			case 3:scanf("%s",s+1);str.clear();
				for(ps=1;s[ps]&&s[ps]!='.';)str+=s[ps++];
				TY vl=mp[str];qw(pr[vl]+findans(ar[vl]),'\n');break;
		}
	}return 0;
}