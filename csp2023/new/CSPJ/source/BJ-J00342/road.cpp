#include <bits/stdc++.h>
using namespace std;
long long n,d,a[100005],v[100005],s[100005],x = 1,y = 1,p,c;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for (int i = 1;i < n;i++) {
		cin >> v[i];
		s[i] = s[i - 1] + v[i - 1];
	}
	s[n] = s[n - 1] + v[n - 1];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	while (y <= n) {
		if (a[x] > a[y]) {
			long long cur = max(0ll,(long long)(ceil((s[y] - s[x] - p) * 1.0 / d)));
			c += cur * a[x];
			p += cur * d - s[y] + s[x];
			x = y;
		}
		else{
			y++;
		}
	}
	cout << c + max(0ll,(long long)(ceil((s[n] - s[x] - p) * 1.0 / d))) * a[x] << endl;
	return 0;
}
