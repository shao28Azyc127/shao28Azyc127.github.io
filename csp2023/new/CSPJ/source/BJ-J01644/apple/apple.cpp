#include <bits/stdc++.h>
using namespace std;
int ans1 = 0, ans2;int a;
bitset<1000000010> bs;
void pd() {
	while (true) {
		ans1++;
		int cnt = -1; bool flag = true;
		for (int i = 0; i < a; i++) {
			if (!bs[i]) {
				cnt++;
				cnt %= 3;
				if (cnt == 0) {
					bs[i] = true;
					flag = false;
					if (i == a - 1) {
						ans2 = ans1;
					}
				}
			}
			
		}
		if (flag) {
			ans1--;
			break;
		}
	}
}
int main() {
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
    scanf("%d", &a);
    pd();
    printf("%d %d\n", ans1, ans2);
    return 0;
}
