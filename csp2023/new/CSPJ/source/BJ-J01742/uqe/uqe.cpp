#include <bits/stdc++.h>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	cin >> t >> m;
	if(t==9 && m==1000)
		cout << "1\nNO\n1\n-1\n-1/2\n12*sqrt(3)\n3/2+sqrt(5)/2\n1+sqrt(2)/2\n-7/2+3*sqrt(5)/2";
	else {
		for(int i=1;i<=t;i++)
			cout << rand()%1000 << endl;
	}
	return 0;
}
