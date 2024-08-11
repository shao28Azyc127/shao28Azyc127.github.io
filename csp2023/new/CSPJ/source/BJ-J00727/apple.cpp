#include <bits/stdc++.h>
using namespace std;
int arr [1000005];
bool brr [1000005];
int main () {
    freopen ("apple.in","r",stdin);
    freopen ("apple.out","w",stdout);
    int n, ans, sum = 0, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
		arr [i] = i;
		brr [i] = 1;
	}
	m = n;
    while (n >= 1) {
		sum++;
		for (int i = 1, j = 1; i <= m;i++) {
			if (brr [i] == 0) continue;
			if (j % 3 == 1) {
				n--;
				brr [i] = 0;
			}
			if (i == m) ans = sum;
			j++;
		}
		
	}
	cout << sum << ' ' << ans;
    return 0;
}
