#include <bits/stdc++.h>
using namespace std;

const int NR = 3010;

int n, m;
int a[NR][30];

int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][c - 'a' + 1]++;
		}
	}
	
	
	for (int j = 1; j <= n; j++) {
		int f = 1;
		for (int i = 1; i <= n; i++) {
			if (i == j) continue;
			int l = 1, r = 26; 
			while (!a[i][r]) r--;
			while (!a[j][l]) l++;
			//cout << j << " " << i<< ": "<< l << " " << r << '\n';
			if (l >= r) {
				f = 0;
				break;
			}
			//cout << '\n';
		}
		cout << f;
	}
	cout << '\n';
	return 0;
}
