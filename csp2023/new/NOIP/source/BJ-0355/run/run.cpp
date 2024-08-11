#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 1e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int C, T;
int n, m, k;
LL d;
struct Node{
	LL l, r, v, len;
	bool operator<(Node x){ return l < x.l; }
}a[N];
int vis[N];
#define File "run"
int main(){
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>C>>T;
	while(T--){
		memset(vis, 0, sizeof(vis));
		cin>>n>>m>>k>>d;
		LL ans = 0;
		for(int i = 1; i <= m; i++){
			cin>>a[i].r>>a[i].len>>a[i].v;
			a[i].l = a[i].r-a[i].len+1;
		}
		sort(a+1, a+n+1);
		for(int i = 1; i <= m; i++){
			LL cost = 0;
			if(vis[a[i].l-1]+a[i].len > k) continue;
			for(int j = a[i].l; j <= a[i].r; j++){
				if(!vis[j]) vis[j] = vis[j-1]+1, cost += d;
			}
			if(a[i].v > cost){
				ans += a[i].v-cost;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
