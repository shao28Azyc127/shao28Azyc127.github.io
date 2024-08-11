#include <bits/stdc++.h>
using namespace std;
const int N = 15;

int n, ans;
int now[N];
int a[N][N];

bool check() {
	for(int i = 1; i <= n; i++) {
		bool flag = 0, f = 0;
		for(int j = 1; j <= 5; j++)
			if(a[i][j] != now[j])
				f = 1;
		if(!f)
			return 0;
		for(int j = 1; j <= 5; j++) {
			bool is = 0;
			for(int k = 1; k <= 5; k++)
				if(j != k && a[i][k] != now[k])
					is = 1;
			if(!is) {
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		for(int j = 1; j <= 4; j++) {
			bool is = 0;
			if((now[j] - a[i][j] + 10) % 10 != (now[j + 1] - a[i][j + 1] + 10) % 10)
				continue;
			for(int k = 1; k <= 5; k++)
				if(j != k && j + 1 != k && a[i][k] != now[k])
					is = 1;
			if(!is) {
				flag = 1;
				break;
			}
		}
		if(!flag)
			return 0;
	}
	return 1;
}	

void dfs(int stp) {
	if(stp == 6) {
		if(check()) {
		//	for(int i = 1; i <= 5; i++)
			//	cout << now[i] << " ";
		//cout << endl;
		ans++;
	}
		return;
	}
	for(int i = 0; i <= 9; i++)
		now[stp] = i, dfs(stp + 1);
}

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 5; j++)
			cin >> a[i][j];
	dfs(1);
	cout << ans;
	return 0;
}
