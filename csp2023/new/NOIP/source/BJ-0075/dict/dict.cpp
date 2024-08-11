#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 3010;
string str;
char max_c[MAXN], min_c[MAXN];
int min_n[MAXN], max_n[MAXN];
int n, L;
bool cmp(int x, int y) { // min x ___ max y
	if (min_c[x] != max_c[y]) {
		return min_c[x] < max_c[y];
	}
	if (min_n[x] != max_n[y]) {
		return false;
	}
	return min_n[x] == L;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> L;
	for (int i = 0; i < n; i++) {
		cin >> str;
		sort(str.begin(), str.end());
		max_c[i] = str[L - 1], min_c[i] = str[0];
		for (int j = 0; j < L && str[j] == min_c[i]; j++) {
			min_n[i]++;
		}
		for (int j = L - 1; i >= 0 && str[j] == max_c[i]; j--) {
			max_n[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (j == i) {
				continue;
			}
			if (!cmp(i, j)) {
				flag = false;
				break;
			}
		}
		cout << flag;
	}
	cout << endl;
	return 0;
}