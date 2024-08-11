#include<cstdio>
#define TY int
#define MAXN 100002
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
}void qw(TY a){if(a>9)qw(a/10);putchar(a%10+'0');}
void qw(TY a,char ch){
	if(a<0){putchar('-');a=-a;}
	if(a>9)qw(a/10);putchar(a%10+'0');
	if(ch)putchar(ch);
}TY n,a[MAXN][5],b[5],p,q,ans;bool fl;
bool can(TY x){
	fOR(i,0,5){b[i]=x%10;x/=10;}
	FOR(i,1,n){
		p=q=-1;fl=false;
		fOR(j,0,5){
			if(a[i][j]==b[j])continue;
			if(p==-1)p=j;
			else{
				if(q==-1)q=j;
				else fl=true;
			}
		}if(fl||p==-1)return false;
		if(q==-1)continue;
		if(q!=p+1)return false;
		p=a[i][p]-b[p];if(p<0)p+=10;
		q=a[i][q]-b[q];if(q<0)q+=10;
		if(p!=q)return false;
	}return true;
}int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	n=qr();FOR(i,1,n)fOR(j,0,5)a[i][j]=qr();
	fOR(i,0,100000)if(can(i))++ans;
	qw(ans);return 0;
}