#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int C, T;
struct Node{
	int st, lst;
	// st = -1, 0, 1 -> F, U, T
	// st = 2, -2 -> set at beginning
	// lst = latest x[lst] which updated x[i]
	// lst = 0
	inline Node(int x, int y){ st = x, lst = y; }
	inline Node(){ st = lst = 0; }
}x[N];
Node operator!(Node x){ return Node(-x.st, x.lst); }
int n, m, p, q;
char op;
void init(int t = 2){
	cin>>n>>m;
	for(int i = 1; i <= n; i++) x[i].st = t, x[i].lst = i;
}
int cnt0(){
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (x[i].st == 0);
	return cnt;
}
void solve1(){ // task3&4, v=TFU
	while(T--){
		init();
		for(int i = 1; i <= m; i++){
			cin>>op>>p;
			if(op == 'T') x[p].st = 1;
			else if(op == 'F') x[p].st = -1;
			else/* op == 'U' */ x[p].st = 0;
		}
		cout<<cnt0()<<endl;
	}
}
void solve(){
	while(T--){
		init(1);
		for(int i = 1; i <= m; i++){
			cin>>op>>p;
			if(op == 'T') x[p].st = 1, x[p].lst = 0;
			else if(op == 'F') x[p].st = -1, x[p].lst = 0;
			else if(op == 'U') x[p].st = 0, x[p].lst = 0;
			else if(op == '+'){
				cin>>q;
				x[p] = x[q];
			}
			else/* op == '-' */{
				cin>>q;
				x[p] = !x[q];
			}
			//cout<<p<<' '<<x[p].st<<' '<<x[p].lst<<endl;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(x[i].st == 0) cnt++;
			else if(x[i].lst == i && x[i].st == -1) cnt++;
		}
		cout<<cnt<<endl;
	}
}
#define File "tribool"
int main(){
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>C>>T;
	if(C == 3 || C == 4){ // v=TFU
		solve1();
		return 0;
	}
	solve();
	return 0;
}
