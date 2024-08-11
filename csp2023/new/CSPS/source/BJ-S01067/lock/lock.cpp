#include <iostream>
using namespace std;

int n, a[10][10], ans = 0;

int dif(int x, int y){
	int cnt = 0;
	for(int i = 1; i <= 5; i++){
		if (a[x][i] != a[y][i]) cnt++;
	}
	return cnt;
}

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	if (n == 1) cout << 81 << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 5; j++){
			cin >> a[i][j];
		}
		if (i != 1){
			for (int j = 1; j <= n; j++){
				for (int k = j; k <= n; k++){
					if (dif(j, k) == 1){
						ans += 9;
					}
					else{
						ans += 1;
					}
				}
			}
		}
		if (n == 1){
			ans = 82;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
