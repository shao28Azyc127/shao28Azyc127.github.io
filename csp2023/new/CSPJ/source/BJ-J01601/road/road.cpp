#include <bits/stdc++.h>
using namespace std;
void fileio(string fname){
	string in=fname+".in",out=fname+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
const int N=1e5+10;
#define int long long
int n,d,dis[N],a[N],f[N],r[N],lst=1;
int dv(int a,int b){
	int d=a/b;
	return d+(a>(b*d));
}
signed main(){
	fileio("road");
	cin>>n>>d;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	for(int i=2;i<=n;++i){
		cin>>dis[i];
		dis[i]+=dis[i-1];
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=2;i<=n;++i){
		int now=dv(dis[i]-dis[lst]-r[lst],d);
		f[i]=f[lst]+a[lst]*now;
		r[i]=now*d+dis[lst]+r[lst]-dis[i];
		if(a[i]<=a[lst]) lst=i;
	}
	cout<<f[n]<<'\n';
	return 0;
}