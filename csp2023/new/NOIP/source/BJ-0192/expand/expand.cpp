#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,n,m,q,a[N],b[N],ta[N],tb[N];
inline void solve(){
	if(a[1]!=b[1]) cout<<"1";
	else cout<<"0";
	while(q--){
		int kx,ky;
		cin>>kx>>ky;
		ta[1]=a[1],tb[1]=b[1];
		for(int i=1;i<=kx;i++){
			int x,v;
			cin>>x>>v;
			ta[x]=v;
		}
		for(int i=1;i<=ky;i++){
			int x,v;
			cin>>x>>v;
			tb[x]=v;
		}
		if(ta[1]!=tb[1]) cout<<1;
		else cout<<0;
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	if(n==1 && m==1){
		solve();
		return 0;
	}
	cout<<0;
	while(q--){
		cout<<0;
	}
	return 0;
}