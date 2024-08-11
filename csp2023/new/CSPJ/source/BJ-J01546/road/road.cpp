#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
int a[10010], v[10010], dp[10010][10010];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road,out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i < n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> v[i];
	}
	for (int i = 0; i <= n; i++){
		//dp[1][i] = i * v[1];
	}
	int o = 0, last = 0;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= n; j++){
			if (o > 0 && o + j - a[i] * d >= 0){
				dp[i][j] = min(dp[i - 1][last], dp[i - 1][last] + v[i] * j);
				last = j;
				o += j;
				o -= a[i] * d;
			}
			if (o == 0 && o + j - a[i] * d >= 0){
				dp[i][j] = dp[i - 1][last] + v[i] * j;
				o += j;
				o -= a[i] * d;
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}
