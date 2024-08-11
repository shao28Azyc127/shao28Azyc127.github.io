#include<cstdio>
#define TY int
#define MAXN 500002
#define FOR(i,a,b) for(TY i=(a);i<=(b);i=-~i)
#define fOR(i,a,b) for(TY i=(a);i<(b);i=-~i)
#define ROF(i,a,b) for(TY i=(a);i>=(b);i=~-i)
#define rOF(i,a,b) for(TY i=(a);i>(b);i=~-i)
using namespace std;
typedef long long ll;
inline TY maxn(TY a,TY b){return a>b?a:b;}
inline TY minn(TY a,TY b){return a<b?a:b;}
inline TY _abs(TY a){return a<0?-a:a;}
inline void updmx(TY &a,TY b){if(a<b)a=b;}
inline void updmn(TY &a,TY b){if(a>b)a=b;}
TY qr(){
	TY x=1,s=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')x=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())s=s*10+ch-'0';return x*s;
}void qw(TY a){if(a>9)qw(a/10);putchar('0'+a%10);}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar('0'+a%10);
	if(ch)putchar(ch);
}TY N,M,T,A[MAXN],B[MAXN],ctx,cty,px[MAXN],vx[MAXN],py[MAXN],vy[MAXN];
char findans(){
	if(A[1]==B[1])return '0';
	TY *x=A,*y=B,n=N,m=M,ps=0,mxy=0,p,mn;
	if(A[1]<B[1]){x=B;y=A;n^=m^=n^=m;}
	if(x[n]<=y[m])return '0';
	FOR(i,1,n)if(x[ps]<=x[i])ps=i;
	FOR(i,1,m)updmx(mxy,y[i]);
	if(x[ps]<=mxy)return '0';p=1;mn=x[ps];
	FOR(i,1,ps){
		while(p<=m&&y[p]<x[i])updmn(mn,y[p++]);
		if(x[i]<=mn)return '0';
	}p=m;mn=x[ps];
	ROF(i,n,ps){
		while(p&&y[p]<x[i])updmn(mn,y[p--]);
		if(x[i]<=mn)return '0';
	}return '1';
}int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	qr();N=qr();M=qr();T=qr();
	FOR(i,1,N)A[i]=qr();
	FOR(i,1,M)B[i]=qr();
	putchar(findans());
	while(T--){
		ctx=qr();cty=qr();
		FOR(i,1,ctx){px[i]=qr();vx[i]=A[px[i]];A[px[i]]=qr();}
		FOR(i,1,cty){py[i]=qr();vy[i]=B[py[i]];B[py[i]]=qr();}putchar(findans());
		FOR(i,1,ctx)A[px[i]]=vx[i];FOR(i,1,cty)B[py[i]]=vy[i];
	}return 0;
}