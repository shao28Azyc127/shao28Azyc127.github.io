#include<cstdio>
#define TY int
#define MAXN 3002
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
}TY n,m,mx[MAXN],mn[MAXN];char s[MAXN];bool fl;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=qr();m=qr();
	FOR(i,1,n){
		scanf("%s",s+1);mn[i]=25;
		FOR(j,1,m){updmx(mx[i],s[j]-'a');updmn(mn[i],s[j]-'a');}
	}FOR(i,1,n){
		fl=true;FOR(j,1,n)if(i!=j&&mn[i]>=mx[j])fl=false;
		putchar('0'+fl);
	}return 0;
}