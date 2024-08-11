#include<iostream>

using namespace std;
int v[100000];
int a[100000];
int main() {
	freopen("road.in","r", stdin);
	freopen("road.out","w", stdout);
	int n, d;
	cin >> n >> d;
        for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b = 0;
	int i = 0;
	int ans = 0;
	while (i < n - 1) {
		int j = i;
		int sum = 0;
		while (a[j] >= a[i] && j < n - 1) {
			j++;
			sum += v[j - 1];
		}
                ans += max((sum - b + d - 1), 0) / d * a[i];
		b += (sum - b + d - 1) / d * d - sum;
		i = j;
	}
        cout << ans;
	return 0;
}
