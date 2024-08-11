#include<bits/stdc++.h>
#define int long long 
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define wh(lzm) while(lzm--)
using namespace std;
void fre(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
const int maxn=100020;
int id,lzm,n,m,k,d;
void chkmax(int &x,int y){
	x=max(x,y);
}
#define lowbit(x) (x&(-x))
int c[maxn];
void add(int x,int y){
	for(;x;x^=lowbit(x)) c[x]+=y;
}
int query(int x){
	int rt=0;
	for(;x<=n;x+=lowbit(x)) rt+=c[x];
	return rt;
}
struct Seg{
	int l,r,w,id;
};
vector<Seg>S[maxn];
int f[maxn],f1[maxn];
void solve(){
	cin>>n>>m>>k>>d;
	F(i,1,n) S[i].clear();
	F(i,1,n) c[i]=0;
	F(i,1,m){
		int x,y,w;
		cin>>x>>y>>w;
		int l=x-y+1,r=x;
		S[r].push_back((Seg){l,r,w,i});
	}
	F(i,1,n) f[i]=f1[i]=0;
	f[0]=f1[0]=0;
	F(i,1,n){
		int len=S[i].size();
		F(j,0,len-1){
			int l=S[i][j].l,w=S[i][j].w;
			add(l,w);
		}
		F(p,max(1ll,i-k+1),i){
			int num=query(p);
			chkmax(f1[i],f[p-1]+num-(i-p+1)*d);
		}
		f[i]=max(f1[i-1],f[i-1]);
	}
	cout<<max(f1[n],f[n])<<endl;
}
signed main(){
	fre();
	//freopen("run2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>lzm;
	wh(lzm) solve();
}
