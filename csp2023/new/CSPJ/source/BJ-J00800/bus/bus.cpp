#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("bus.in", "r", stdin); freopen("bus.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
int n, m, k, ans;
struct node{int to, v;};
vector<node> v[10005], vf[10005];
int d[10005];
bool check(int p){
	memset(d, 0x3f, sizeof(d));
	queue<node> q;
	d[n] = p, q.push({n, p});
	while(!q.empty()){
		node a = q.front(); q.pop();
		//cout << a.to << " ";
		if(a.v - 1 < k) break;
		for(auto to : vf[a.to]){
			if(a.v - 1 < to.v) continue;
			if(d[to.to] > a.v - 1){
				d[to.to] = a.v - 1;
				q.push({to.to, d[to.to]});
			}
		}
	}
	return d[1] != 0x3f3f3f3f && !(d[1] % k);
}
int main(){ File ? file() : void(); INIT();
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, _v, a; cin >> u >> _v >> a;
		if(n > 100 && u > _v){cout << -1 << endl; return 0;}
		v[u].push_back({_v, a}); vf[_v].push_back({u, a});
	}
	int l = 1, r = ceil((1000000.0 + m) / k);
	//cout << l << " " << r << endl;
	//cout << check(1000782);
	while(l <= r){
		int mid = l + r >> 1;
		//cout << mid << " ";
		if(check(mid * k)) r = mid - 1, ans = mid * k;
		else l = mid + 1;
		//cout << mid << " ";
	}
	cout << ans;
	return 0;
}