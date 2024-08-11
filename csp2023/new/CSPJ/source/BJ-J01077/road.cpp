#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	int a;
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		sum += a;
	}
	int b;
	cin >> b;
	if (sum % b != 0) {
		cout << sum / d * b << endl;
	} else {
		cout << sum / d * b + b << endl;
	}
	return 0;
}
