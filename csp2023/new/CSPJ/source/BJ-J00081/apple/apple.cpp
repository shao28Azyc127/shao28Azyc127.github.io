#include <cstdio>
#define int long long
using namespace std;
int n, _count, answer;
bool flag;
signed main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%lld", &n);
	while (n) {
		_count ++;
		if (! flag && (n - 1) % 3 == 0) {
			answer = _count;
			flag = true;
		}
		n -= (n + 2) / 3;
	}
	printf("%lld %lld\n", _count, answer);
	return 0;
}
