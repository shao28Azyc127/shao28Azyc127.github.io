#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	if (n == 2) return 2;
	if (n % 3 == 0) return f(n - n/3)+1;
	else return f(n - n/3 - 1)+1;
}
int g(int n) {
	if (n <= 3) return n;
	if (n % 3 == 1) return 1;
	if (n % 3 == 2) return g(n - n/3-1)+1;
	else return g(n-n/3)+1;
}
int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout); 
	int n;
	cin >> n;
	int ans1 = f(n), ans2 = g(n);
	cout << ans1 << " " << ans2;
	return 0;
}