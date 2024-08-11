#include<cstdio>
#include<queue>
#define TY ll
#define MAXN 100002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
#define EDG(i,u) for(TY i=hed[u];i;i=nxt[i])
#define ALL(i,st) for(it=st.begin();it!=st.end();++it)
using namespace std;
typedef long long ll;const TY INF=1e18;
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
}TY n,u,v,a[MAXN],b[MAXN],c[MAXN],hed[MAXN],nxt[MAXN<<1],to[MAXN<<1];
TY l,r,mid,p[MAXN],id[MAXN],fa[MAXN],ans;bool vs[MAXN],fl;
void addedge(TY id){nxt[id]=hed[u];to[hed[u]=id]=v;}
struct node{TY id,d;};bool operator<(node a,node b){return a.d>b.d;}priority_queue<node>q;
void dfs(TY u){id[++v]=u;EDG(i,u)if(to[i]!=fa[u]){fa[to[i]]=u;dfs(to[i]);}}
TY sm(TY n,TY b,TY c){
	if(c>=0)return n*b+(c*n*(n-1)>>1);TY p=(b-1)/(-c);
	if(n<=p+1)return n*b+(c*n*(n-1)>>1);
	return (p+1)*b+(c*p*(p+1)>>1)+n-p-1;
}TY js(TY n,TY a,TY b,TY c){
	if(c<0){
		TY p=(b-1)/(-c);
		if(n>p){
			if(n-p>=a)return n-a+1;
			a-=n-p;n=p;
		}
	}b+=c*n;c=-c;TY x=0;
	for(TY i=1;;i<<=1){
		x|=i;if(sm(x,b,c)<a)continue;x-=i;
		for(TY j=i>>1;j;j>>=1)
			if(sm(x+j,b,c)<a)x+=j;
		break;
	}return n-x;
}int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=qr();FOR(i,1,n){
		a[i]=qr();b[i]=qr();c[i]=qr();
	}fOR(i,1,n){
		u=qr();v=qr();addedge(i<<1);
		u^=v^=u^=v;addedge(i<<1|1);
	}v=0;dfs(1);l=n;r=1e9;
	while(l<r){
		mid=l+r>>1;FOR(i,1,n)p[i]=js(mid,a[i],b[i],c[i]);
//		qw(mid,' ');FOR(i,1,n)qw(p[i],' ');putchar('\n');
		ROF(i,n,1)updmn(p[fa[id[i]]],p[id[i]]-1);
		while(q.size())q.pop();fl=true;
		q.push((node){.id=1,.d=p[1]});
		FOR(i,1,n){
			u=q.top().id;q.pop();
			if(i>p[u]){fl=false;break;}
			EDG(i,u)if(to[i]!=fa[u])q.push((node){.id=to[i],.d=p[to[i]]});
		}if(fl)r=mid;else l=mid+1;
	}qw(l);return 0;
}