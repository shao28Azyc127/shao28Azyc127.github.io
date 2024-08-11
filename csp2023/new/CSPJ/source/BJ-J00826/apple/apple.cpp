#include <bits/stdc++.h>
using namespace std;

int n,p,i;

int main() {
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	while (n && ++i) {
		if (n % 3 == 1 && !p) p = i;
		n -= (n + 2) / 3;
	}
	cout << i << " " << p << endl;
	return 0;
}