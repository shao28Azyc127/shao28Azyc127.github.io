#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);

	int n; cin >> n;
	int ans1, ans2;
	int deep = 0;
	bool flag = true;

	bool bk = false;
	while (flag) {
		deep++;
		if (n == 1) {
            ans1 = deep;
			flag = false;
		}
		if (n % 3 == 1) {
            if (bk == false) {
                ans2 = deep;
                bk = true;
            }
			n -= n / 3 + 1;
		} else if (n % 3 == 2) {
			n -= n / 3 + 1;
		} else if (n % 3 == 0) {
			n -= n / 3;
		}
	}
	cout << ans1 << " " << ans2 << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
