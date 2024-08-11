#include<iostream>

using namespace std;

int main() {
	freopen("apple.in","r", stdin);
	freopen("apple.out","w", stdout);
	int n;
	cin >> n;
	int i = 0;
	bool a = false;
	int ans;
	while (n > 0) {
		if ((n % 3 == 1) && (!a)) {
			a = !a;
                        ans = i + 1;
		}
		n -= (n+ 2) / 3;
		i++;
	}
	cout << i << ' ' << ans;
	return 0;
}