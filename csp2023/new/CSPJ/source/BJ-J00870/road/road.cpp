#include <bits/stdc++.h>
using namespace std;

int n, d, cost = 0;
int w[100005], p[100005];
int f(int l, int k){
	int sum = 0;
	while (sum * d < l - k) {
		sum++;
	}
	return sum;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i <= n - 1; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		cin >> p[i];
	}
	int k = 0;
	for (int i = 1; i <= n - 1; i++) {
		int l = 0;
		int j = 0;
		for (j = i + 1; j <= n - 1; j++) {
			if (p[i] <= p[j]) {
				l += w[i];
			} else {
				break;
			}
		}
		if (i == 1 && l == 0) {
			cost += p[1] * f(w[1], k);
			k += f(w[1], k) * d - w[1];
			continue;
		}
		cost += p[i] * f(l, k);
		k += f(l, k) * d - l;
		i = j;
	}
	cout << cost;
	return 0;
}
