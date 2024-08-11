#include <bits/stdc++.h>
using namespace std;
const int p10[6] = {1, 10, 100, 1000, 10000, 100000};
int n, a[5], ans, full, t[100100];
int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d", &n); full = (1 << n) - 1;
	for(int i = 1; i <= n; i++) {
        int s = 0;
        for(int j = 0; j < 5; j++) {
            scanf("%d", &a[j]);
            s += a[j] * p10[j];
        }
        for(int j = 0; j < 5; j++)
            for(int bt = 0; bt <= 9; bt++) {
                if(bt == a[j]) continue;
                t[s + (bt - a[j]) * p10[j]] |= (1 << (i - 1));
            }
        for(int j = 1; j < 5; j++)
            for(int ad = 1; ad <= 9; ad++) {
                int bt0 = (a[j - 1] + ad) % 10;
                int bt1 = (a[j] + ad) % 10;
                int ns = s + p10[j - 1] * (bt0 - a[j - 1]) + p10[j] * (bt1 - a[j]);
                t[ns] |= (1 << (i - 1));
            }
	}
	for(int i = 0; i < p10[5]; i++) ans += (t[i] == full);
	printf("%d", ans);
	return 0;
}
