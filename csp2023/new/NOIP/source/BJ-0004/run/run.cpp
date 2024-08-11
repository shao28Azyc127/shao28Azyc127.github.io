#include<cstdio>
#include<vector>
#include<algorithm>
#define TY ll
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
}TY kd,T,n,m,k,d,tre[MAXN<<2],tag[MAXN<<2],l,r,vl;
TY b[MAXN<<1],L[MAXN],R[MAXN],v[MAXN],dp[MAXN<<1];
vector<TY>ps[MAXN<<1],V[MAXN<<1];
void FA(){
	while(T--){
		qr();n=0;m=qr();k=qr();d=qr();
		while(m--){
			r=qr();l=r-qr();
			if(r-l>k){qr();continue;}
			L[++n]=l;R[n]=r+1;v[n]=qr();
		}m=0;FOR(i,1,n){b[++m]=L[i];b[++m]=R[i];}
		sort(b+1,b+m+1);m=unique(b+1,b+m+1)-b-1;
		FOR(i,1,m){ps[i].clear();V[i].clear();}
		FOR(i,1,n){
			L[i]=lower_bound(b+1,b+m+1,L[i])-b;
			R[i]=lower_bound(b+1,b+m+1,R[i])-b;
			ps[R[i]].push_back(L[i]);
			V[R[i]].push_back(v[i]);
		}++k;dp[l=1]=r=0;
		FOR(i,2,m){
			dp[i]=r;
			while(b[i]-b[l]>k)++l;
			fOR(j,0,ps[i].size())
				FOR(x,l,ps[i][j])dp[x]+=V[i][j];
			fOR(j,l,i)dp[j]-=d*(b[i]-b[i-1]);dp[i-1]+=d;
			fOR(j,l,i)updmx(dp[i],dp[j]);updmx(r,dp[i]);
		}qw(r,'\n');
	}
}void FB(){
	while(T--){
		qr();m=qr();k=qr();d=qr();vl=0;
		while(m--){
			qr();l=qr();
			if(l>k){qr();continue;}
			vl+=maxn(0,qr()-l*d);
		}qw(vl,'\n');
	}
}void build(TY i,TY j,TY id){
	tre[id]=tag[id]=0;if(i==j)return;
	TY mid=i+j>>1;build(i,mid,id<<1);
	build(mid+1,j,id<<1|1);
}void ask(TY i,TY j,TY id){
	if(l<=i&&j<=r){updmx(vl,tre[id]);tre[id]-=d;tag[id]-=d;return;}
	TY mid=i+j>>1,sn=id<<1;tre[sn]+=tag[id];tag[sn]+=tag[id];
	tre[sn|1]+=tag[id];tag[sn|1]+=tag[id];tag[id]=0;
	if(l<=mid)ask(i,mid,sn);if(mid<r)ask(mid+1,j,sn|1);
	tre[id]=maxn(tre[sn],tre[sn|1]);
}void chg(TY i,TY j,TY id){
	if(i==j){tre[id]=vl;return;}
	TY mid=i+j>>1,sn=id<<1;tre[sn]+=tag[id];tag[sn]+=tag[id];
	tre[sn|1]+=tag[id];tag[sn|1]+=tag[id];tag[id]=0;
	if(l<=mid)chg(i,mid,sn);else chg(mid+1,j,sn|1);
	tre[id]=maxn(tre[sn],tre[sn|1]);
}void add(TY i,TY j,TY id){
	if(j<=r){tre[id]+=vl;tag[id]+=vl;return;}
	TY mid=i+j>>1,sn=id<<1;tre[sn]+=tag[id];tag[sn]+=tag[id];
	tre[sn|1]+=tag[id];tag[sn|1]+=tag[id];tag[id]=0;
	add(i,mid,sn);if(mid<r)add(mid+1,j,sn|1);
	tre[id]=maxn(tre[sn],tre[sn|1]);
}int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	kd=qr();T=qr();
	if(kd==17||kd==18){FB();return 0;}
	if(kd==15||kd==16||kd>18){FA();return 0;}
	while(T--){
		n=qr()+1;m=qr();k=qr();d=qr();
		FOR(i,1,n){ps[i].clear();V[i].clear();}
		build(0,n,1);while(m--){
			r=qr()+1;ps[r].push_back(r-qr()-1);
			V[r].push_back(qr());
		}FOR(i,1,n){
			fOR(j,0,ps[i].size()){
				r=ps[i][j];vl=V[i][j];add(0,n,1);
			}l=i-k-1;r=i-1;vl=0;ask(0,n,1);
			l=i;chg(0,n,1);
		}qw(vl,'\n');
	}return 0;
}