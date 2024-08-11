#include<cstdio>
#define TY int
#define MAXN 100002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
using namespace std;
typedef long long ll;
const TY M=998244353;
inline TY maxn(TY a,TY b){return a>b?a:b;}
inline TY minn(TY a,TY b){return a<b?a:b;}
inline TY _abs(TY a){return a<0?-a:a;}
inline void updmx(TY &a,TY b){if(a<b)a=b;}
inline void updmn(TY &a,TY b){if(a>b)a=b;}
inline void add(TY &a,TY b){if((a+=b)>=M)a-=M;}
TY qr(){
	TY x=1,s=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(TY a){if(a>9)qw(a/10);putchar('0'+a%10);}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar('0'+a%10);
	if(ch)putchar(ch);
}TY T,n,m,u,v,nd,id[MAXN],fa[MAXN],sz[MAXN];char ch;bool d[MAXN],fl[MAXN];
TY getfa(TY u){
	if(fa[u]==u)return u;TY tmp=getfa(fa[u]);
	d[u]^=d[fa[u]];return fa[u]=tmp;
}int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	qr();T=qr();
	while(T--){
//0-->U  inf-->T  -inf-->F  i-->i  -i-->!i
		n=qr();m=qr();FOR(i,1,n){
			sz[id[i]=fa[i]=i]=1;
			d[i]=fl[i]=false;
		}while(m--){
			ch=getchar();
			while(ch==' '||ch=='\n'||ch=='\r')ch=getchar();
			switch(ch){
				case 'U':id[qr()]=0;break;
				case 'T':id[qr()]=MAXN;break;
				case 'F':id[qr()]=-MAXN;break;
				case '+':u=qr();id[u]=id[qr()];break;
				case '-':u=qr();id[u]=-id[qr()];break;
			}
		}FOR(i,1,n){
			if(_abs(id[i])>n)continue;
			if(id[i]==0){fl[getfa(i)]=true;continue;}
			u=getfa(i);v=getfa(nd=_abs(id[i]));
			if(u==v){if(d[i]^d[nd]^(id[i]<0))fl[u]=true;continue;}
			sz[fa[u]=v]+=sz[u];fl[v]|=fl[u];d[u]=(d[i]^d[nd]^(id[i]<0));
		}u=0;FOR(i,1,n)if(fa[i]==i&&fl[i])u+=sz[i];qw(u,'\n');
	}return 0;
}