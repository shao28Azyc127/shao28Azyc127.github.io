#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef pair<int, char> P;
const int MAXN = 2000010;
string str;
unsigned long long cnt[MAXN];
int ed[MAXN];
int n;
stack<P> stk;
int maxs = 0;
int main() {
	ios::sync_with_stdio(false);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (!stk.empty() && stk.top().second == str[j]) {
				stk.pop();
			} else {
				stk.push({j, str[j]});
			}
			if (stk.size() == 0) {
				cnt[i] = 1;
				ed[i] = j + 1;
				break;
			}
		}
		while (stk.size()) {
			stk.pop();
		}
	}
	unsigned long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (cnt[i] == 0) {
			continue;
		}
		cnt[i] += cnt[ed[i]];
		ans += cnt[i];
	}
	cout << ans << endl;
	return 0;
}