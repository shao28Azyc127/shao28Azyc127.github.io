#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    int ans = 0;
    int flag = 0;
    while(n > 0) {
    	if((n - 1) % 3 == 0 && flag == 0) {
    		ans = cnt + 1;
    		flag = 1;
		}
        n -= (n - 1) / 3 + 1;
        ++cnt;
    }
    cout << cnt << " " << ans;
    return 0;
}