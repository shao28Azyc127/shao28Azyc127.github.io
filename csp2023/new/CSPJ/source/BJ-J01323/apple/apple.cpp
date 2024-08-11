#include <iostream>

using namespace std;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	int cntn = 0;
	while (n) {
		cnt ++ ;
		if (n % 3 == 1 && cntn == 0) cntn = cnt;
		n = n - ((n + 2) / 3);
	}
	cout << cnt << ' ' << cntn << endl;
	return 0;
}
