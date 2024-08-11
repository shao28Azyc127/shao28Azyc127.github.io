#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int r1, r2;
	bool c = true;
	for (int i = 1; n > 0; i++) {
		if (c && (n % 3 == 1)) {
			c = false;
			r2 = i;
		}
		r1 = i;
		n -= (n + 2) / 3;
	}
	cout << r1 << " " << r2 << endl;
	return 0;
}