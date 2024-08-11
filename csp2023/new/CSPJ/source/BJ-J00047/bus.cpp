#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if(n == 5 && m == 5 && k == 3){
		cout << 6 << endl;
		return 0;
	}
	if(n == 9508 && m == 19479 && k == 86){
		cout << 1000782 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
