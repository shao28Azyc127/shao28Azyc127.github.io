#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], b[1000005], ans2 = 0, c1 = 0;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	cin >> n;
	long long nums = n;
	while (nums > 0){
		if (nums % 3 == 1 && !ans2){
			ans2 = c1 + 1;
		}
		long long mi = (nums - 1) / 3 + 1;
		nums -= mi;
		c1++;
	}
	cout << c1 << " " << ans2 << endl;
	return 0;
}
