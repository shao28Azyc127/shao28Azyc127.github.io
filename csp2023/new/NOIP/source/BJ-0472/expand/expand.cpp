#include<bits/stdc++.h>
using namespace std;
const int NR=5e5+5;
int c,n,m,q;
int a[NR],b[NR];
int ya[NR],yb[NR];
void solve(){
	if(c==1){
		if(a[1]!=b[1])cout<<1;
		else cout<<0;
		return;
	}
	if(c==2){
		if(a[1]!=b[1]&&a[n]!=b[m]&&(a[1]-b[1])*(a[n]-b[m])>0)
			cout<<1;
		else cout<<0;
		return; 
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;++i)
		cin>>ya[i];
	for(int i=1;i<=m;++i)
		cin>>yb[i];
	for(int i=1;i<=n;++i)
		a[i]=ya[i];
	for(int i=1;i<=m;++i)
		b[i]=yb[i];
	solve();
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		for(int i=1;i<=n;++i)
			a[i]=ya[i];
		for(int i=1;i<=m;++i)
			b[i]=yb[i];
		for(int i=1;i<=kx;++i){
			int p,v;cin>>p>>v;
			a[p]=v;
		}
		for(int i=1;i<=ky;++i){
			int p,v;cin>>p>>v;
			b[p]=v;
		}
		solve();
	}
	return 0;
}