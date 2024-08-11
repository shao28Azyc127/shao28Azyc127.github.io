#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int st[N];

int get(int a, int b, int c, int d, int e) {
	return (a % 10) * 10000 + (b % 10) * 1000 + (c % 10) * 100 + (d % 10) * 10 + (e % 10);
}

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n;
	cin >> n;
	int m = n;
	while (n -- ) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		for (int i = 1; i <= 9; i ++ ) {
			st[get(a + i, b + i, c, d, e)] ++ ;
			st[get(a, b + i, c + i, d, e)] ++ ;
			st[get(a, b, c + i, d + i, e)] ++ ;
			st[get(a, b, c, d + i, e + i)] ++ ;
			st[get(a + i, b, c, d, e)] ++ ;
			st[get(a, b + i, c, d, e)] ++ ;
			st[get(a, b, c + i, d, e)] ++ ;
			st[get(a, b, c, d + i, e)] ++ ;
			st[get(a, b, c, d, e + i)] ++ ;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 99999; i ++ ) {
		if (st[i] == m) {
			ans ++ ;
		}
	}
	cout << ans << endl;
	return 0;
}
