#include <iostream>
#include <stack>

using namespace std;

const int N = 2e6 + 10;

string a[N];

bool cmp(string a, string b) {
	if (a.size() != b.size()) return false;
	else {
		for (int i = 0; i < a.size(); i ++ ) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n;
	cin >> n;
	string stk;
	int ans = 0;
	char last = 'A';
	for (int i = 1; i <= n; i ++ ) {
		char c;
		cin >> c;
		if (c == last) ans ++ ;
		last = c;
		if (stk.size() > 0 && stk.back() == c) {
			stk.pop_back();
		} else stk += c;
		a[i] = stk;
		//cout << stk << endl;
	}
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ ) {
			if (cmp(a[i], a[j])) {
				ans ++ ;
				//cout << i << ' ' << j << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
