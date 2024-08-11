#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 1e9, d[10010][3], cur = 0;
long long a[10010][5];//a[i][4]表示树当前的高度
bool flag[10010], flag1[10010];//标记种没种树

int g(int x, int h, int a, int b){
		h += max(a + x * b, 1);
	return h;
}

bool check(int t){
	for (int i = 1; i <= n; i++){
		if (a[i][4] || flag[i] == false){
			return false;
		}
	}
	return true;
}

void dfs(int x, int t){//当前时间为t
	//让树长高
	if (flag1[t] == false){
		flag1[t] = true;
		for (int i = 1; i <= n; i++){
			if (flag[i] == true){
				a[i][4] = g(t, a[i][4], a[i][2], a[i][3]);
			}
		}
	}
	cout << check() << endl;
	if (check()){
		ans = min(ans, t + 1);
		return;
	}
	//种树
	flag[x] = true;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if(d[j][1] == i && flag[d[j][2]] == false){
				flag[d[j][2]] = true;
				dfs(d[j][2], d[j][2]);
			}
		}
	}
	t++;
}

int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	for (int i = 1; i <= n - 1; i++){
		cin >> d[i][1] >> d[i][2];
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}
