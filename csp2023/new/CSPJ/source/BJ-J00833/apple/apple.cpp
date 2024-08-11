#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	int day = 1;
	int day_ans = -1;
	int ans = 0;
	cin >> n;
	while (n > 0) {
		if (n % 3 == 1 && day_ans == -1) {
			day_ans = day;
		}

		if (n % 3 == 0) {
			n = n - n / 3;
		} else {
			n = n - n / 3 - 1;
		}
		day++;
		ans++;
	}
	cout << ans << " " << day_ans;
	return 0;
}