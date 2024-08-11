#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N], b[N], c[N];
vector<int> g[N];

int n;

void add(int u, int v){
	g[u].push_back(v);
}

double sq(double x){
	return x*x;
}

ll tim(int id, int d){ // 第id棵树从第d天开始种需要第 tim 天达到要求
	ll f = b[id]+(long long)c[id]*d;
//	if(id==4 && d==3) cout << f << endl;
	if(c[id]==0){
		ll v = max(f, 1ll);
		return d+(a[id]-1)/v;
	}
	else if(c[id]>0){
		if(f>=1){
			ll k = 0;
			if(f<a[id]){
				k = ceil((sqrt(sq(c[id]/2.0+f)-2*c[id]*(f-a[id]))-c[id]/2.0-f)/c[id]);
			}
			return d+k;
		}
		else{
			ll t = (1-f)/c[id];
			if(1+t>=a[id]){
				return d+a[id]-1;
			}
			else{
				ll r = a[id]-1-t;
				f = f+(t+1)*c[id];
				ll k = 0;
				if(f<r){
					k = ceil((sqrt(sq(c[id]/2.0+f)-2*c[id]*(f-a[id]))-c[id]/2.0-f)/c[id]);
				}
				return d+1+t+k;
			}
		}
	}
	else{
		if(f<=1){
			return d+a[id]-1;
		}
		else{
			ll t = (f-1)/(-c[id]);
			ll h = (t+1)*f+c[id]*t*(t+1)/2;
			if(h<=a[id]){
				return d+t+a[id]-h;
			}
			else{
				ll k = 0;
				if(f<a[id]){
					k = ceil((sqrt(-sq(c[id]/2.0+f)-2*c[id]*(f-a[id]))-c[id]/2.0-f)/c[id]);
				}
				return d+k;
			}
		}
	}
}

namespace solveb{
	void solve(){
		ll ans = 0;
		for(int i=1;i<=n;i++){
			ll t = tim(i, i);
//			cout << t << endl;
			ans = max(ans, t);
		}
		cout << ans << endl;
	}
};

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
//	bool Ta = 1, Tb = 1;
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i=1;i<n;i++){
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
//		if(u!=i || v!=i+1) Tb = 0;
	}
	solveb::solve();
//	cout << tim(1, 1) << ' ' << tim(3, 2) << ' ' << tim(4, 3) << ' ' << tim(2, 4) << endl;
	
	return 0;
}
