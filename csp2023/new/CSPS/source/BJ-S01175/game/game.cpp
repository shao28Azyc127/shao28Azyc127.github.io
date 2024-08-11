#include<cstdio>
#define TY int
#define MAXN 2000005
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
TY qr(){
	TY x=1,s=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(ll a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');
	if(ch)putchar(ch);
}TY n,to[MAXN][26],fa[MAXN],dep[MAXN];ll ans;char s[MAXN];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=qr();scanf("%s",s+1);dep[n+2]=-1;
	fOR(i,0,26)to[n+1][i]=to[n+2][i]=n+2;
	ROF(i,n,1){
		//for(TY j=i+1;s[i]!=s[j];j=fa[j])
		fa[i]=to[i+1][s[i]-'a'];
		if((dep[i]=dep[fa[i]]+1)>0)ans+=dep[i];
		fOR(j,0,26)to[i][j]=to[fa[i]][j];
		to[i][s[i]-'a']=i+1;
	}qw(ans);return 0;
}