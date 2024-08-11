#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, ans = 0, ans1 = -1;
	cin >> n;
	while (n > 0){
		int x = n / 3;
		ans++;
		if (n % 3 != 0) x++;
		if (n % 3 == 1 && ans1 == -1) ans1 = ans;
		n -= x;
	}
	cout << ans << ' ' << ans1;
	return 0;
}