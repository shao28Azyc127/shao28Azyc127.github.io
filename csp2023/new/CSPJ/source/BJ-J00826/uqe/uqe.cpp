#include <bits/stdc++.h>
using namespace std;

double a,b,c,p;
int t,m;

int main() {
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> t >> m;
	while (t--) {
		cin >> a >> b >> c;
		p = b * b - 4 * a * c;
		if (p < 0) {cout << "NO" << endl;continue;}
		cout << (sqrt(p) - b) / a / 2 << endl;
	}
	return 0;
}