#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 5e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int C;
int n, m, q, X[N], Y[N], x[N], y[N];
struct Node{
	int l, r;
	inline Node(int a, int b){ l = a, r = b; }
};
vector<Node> sx, sy;
bool check(){
	int xmx = 0, xmn = INF, ymx = 0, ymn = INF;
	for(int i = 1; i <= n; i++) xmx = max(xmx, x[i]), xmn = min(xmn, x[i]);
	for(int i = 1; i <= m; i++) ymx = max(ymx, y[i]), ymn = min(ymn, y[i]);
	if((x[1]-y[1])*(x[n]-y[m]) <= 0) return 0;
	else{
		if(x[1] < y[1]) return xmn < ymx;
		else return xmx > ymn;
	}
}	
#define File "expand"
int main(){
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>C;
	cin>>n>>m>>q;
	for(int i = 1; i <= n; i++) cin>>X[i];
	for(int i = 1; i <= m; i++) cin>>Y[i];
	for(int i = 1; i <= n; i++) x[i] = X[i];
	for(int i = 1; i <= m; i++) y[i] = Y[i];
	cout<<check();
	int kx, ky, p, v;
	while(q--){
		for(int i = 1; i <= n; i++) x[i] = X[i];
		for(int i = 1; i <= m; i++) y[i] = Y[i];
		cin>>kx>>ky;
		for(int i = 1; i <= kx; i++){
			cin>>p>>v;
			x[p] = v;
		}
		for(int i = 1; i <= ky; i++){
			cin>>p>>v;
			y[p] = v;
		}
		cout<<check();
	}
	cout<<endl;
	return 0;
}
