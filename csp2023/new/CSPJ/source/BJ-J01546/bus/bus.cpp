#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int a[10010][3], ans = 1e9;
bool flag[10010];

void dfs(int x, int t){
	if (a[x][1] == n){
		ans = min(ans, t);
		return;
	}
	for (int i = 1; i <= m; i++){
		if (a[i][1] == a[x][2] && t >= a[i][3] && flag[a[i][2]] == false){
			flag[a[i][2]] = true;
			t += a[i][3];
			dfs(i, t);
			t += a[i][3];
			cout << 1 << endl;
		}
	}
}

int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	dfs(1, a[1][3]);
	cout << ans << endl;
	return 0;
}
