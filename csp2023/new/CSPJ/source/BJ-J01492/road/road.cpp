#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100005], v[100005];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	double n, d;
	cin >> n >> d;
	for (int i = 1; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	double x = 0;
	long long cost = 0;
	long long pos = 1;
	while (pos != n) {
		long long mn = pos;
		for (int i = pos+1; i < n; i++) {
			if (a[i] < a[mn]) {
				mn = i;
				break;
			}
		}
		if (mn == pos) mn = n;
		double dis = 0;
		for (int i = pos; i < mn; i++) dis += v[i];
		long long u = ceil((dis-x*d)/d*1.0);
		cost += u*a[pos];
		x += (u*1.0-dis/d*1.0)*1.0;
		pos = mn;
	}
	cout << cost;
	return 0;
}