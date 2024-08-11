#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define wh(lzm) while(lzm--)
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
void fre(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
}
const int maxn=500005;
int id,lzm,n,m,a[maxn],b[maxn],c[maxn],d[maxn];
namespace subtask{
	int mn[maxn<<2],mx[maxn<<2];
	#define ls (o<<1)
	#define rs (o<<1|1)
	void solve(){
		cout<<0;
		wh(lzm){
			F(i,1,n) c[i]=a[i];
			F(i,1,m) d[i]=b[i];
			int kx,ky,pos,val;
			cin>>kx>>ky;
			wh(kx){
				cin>>pos>>val;
				c[pos]=val;
			}
			wh(ky){
				cin>>pos>>val;
				d[pos]=val;
			}
			cout<<0;
		}
	}
}
signed main(){
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>id>>n>>m>>lzm;
	F(i,1,n) cin>>a[i];
	F(i,1,m) cin>>b[i];
	if(id>=8) return subtask::solve(),0;
	F(i,1,n) c[i]=a[i];
	F(i,1,m) d[i]=b[i];
	if(c[1]==d[1]) cout<<0;
	else cout<<1;
	wh(lzm){
		F(i,1,n) c[i]=a[i];
		F(i,1,m) d[i]=b[i];
		int kx,ky,pos,val;
		cin>>kx>>ky;
		wh(kx){
			cin>>pos>>val;
			c[pos]=val;
		}
		wh(ky){
			cin>>pos>>val;				
			d[pos]=val;
		}
		if(id==1){
			if(c[1]==d[1]) cout<<0;
			else cout<<1;
		}
		else if(id==2){
			if(c[1]==d[1]) {
				cout<<0;
				continue;
			}
			if(min(n,m)==1){
				if(n==1){
					int x=(c[1]>d[1])?1:-1;
					int y=(c[1]>d[2])?1:-1;
					if(x*y<0) cout<<0;
					else cout<<1;
				}
				else{
					int x=(c[1]>d[1])?1:-1;
					int y=(c[2]>d[1])?1:-1;
					if(x*y<0) cout<<0;
					else cout<<1;
				}
				continue;
			}
			if(c[1]==d[1]||c[2]==d[2]) cout<<0;
			else{
				int x=(c[1]>d[1])?1:-1;
				int y=(c[2]>d[2])?1:-1;
				if(x*y<0) cout<<0;
				else cout<<1;
			}
		}
	}
}
