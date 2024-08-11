#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000,maxm = 2e4;

int n,m,k,u[maxm + 5],v[maxm + 5],a[maxm + 5],first[maxn + 5],nxt[maxm + 5];
bool vis[maxn + 5];
int ans = 2e9;

void dfs(int cur,int dep,int maxa){
	if(cur == n){
		if(dep % k == 0){
			if(maxa + dep % k == 0) ans = min(ans,(maxa+dep)/k*k);
			else ans = min(ans,((maxa+dep)/k+1)*k);
		}
		return;
	}
	for(int k = first[cur];k;k = nxt[k])
		dfs(v[k],dep+1,max(maxa,a[k]-dep));
}
	

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
		for(int i = 1;i <= m; i++){
			cin >> u[i] >> v[i] >> a[i];
			nxt[i] = first[u[i]];
			first[u[i]] = i;
		}
		dfs(1,0,0);
		cout << ans << endl;
	
	return 0;
}
//图论中，dfs的复杂度是O(n+m)。
//在本题目中，可以出现环（但不允许走总环的长度是k的倍数的环）O(nk+m)
//连续走k次，观察是否合法
//当前：25分
//总分（估分）：325分