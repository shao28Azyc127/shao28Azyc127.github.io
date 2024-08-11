# include <iostream>
using namespace std;

int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	bool flag = 1;
	int n, cnt = 0, ans;
	cin >> n;
	while (n){
		cnt++;
		if (flag && !((n - 1) % 3)){
			ans = cnt;
			flag = 0;
		}
		if (n % 3) n -= n / 3 + 1;
		else n -= n / 3;
	}
	cout << cnt << " " << ans;
	return 0;
}