#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m, a, b, c, s;
	cin >> t >> m;
	while (t--){
		cin >> a >> b >> c;
		s = b * b - 4 * a * c;
		if (s < 0) cout << "NO";
		cout << endl;
	}
	return 0;
}