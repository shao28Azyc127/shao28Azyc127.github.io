#include <bits/stdc++.h>
using namespace std;

int num;
int loc[20][5];
bool can[105];
int way[105][5];

bool cmp(int a, int b) {
	
	int dif = 0;
	int di[4] = {-1, -1, -1, -1};
	for (int i = 0; i < 5; i++) {
		if (loc[b][i] != way[a][i]) {
			dif++;
			di[dif] = i;
		}
		if (dif > 2) {
			return false;
		}
	}
	
	if (dif == 1) {
		return true;
	} else if (dif == 2){
		if (di[2] - di[1] != 1) {
			return false;
		} else {
			int k = way[a][di[2]];
			if (way[a][di[1]] < k) {
				k -= way[a][di[1]];
			} else {
				k = 10 + k - way[a][di[1]];
			}

			int k1 = loc[b][di[2]];
			if (loc[b][di[1]] < k1) {
				k1 -= loc[b][di[1]];
			} else {
				k1 = 10 + k1 - loc[b][di[1]];
			}
			if (k1 == k) {
				return true;
			} else {
				return false;
			}
		}
	}
	return false;
}

int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	int ans = 0;
	num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> loc[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 9; j++) {
			loc[0][i]++;
			loc[0][i] %= 10;
			for (int k = 0; k < 5; k++) {
				way[num][k] = loc[0][k];
				can[num] = 1;
			}
			num++;
		}
		loc[0][i]++;
		loc[0][i] %= 10;
	}

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j <= 9; j++) {
			loc[0][i]++;
			loc[0][i] %= 10;
			loc[0][i - 1]++;
			loc[0][i - 1] %= 10;
			for (int k = 0; k < 5; k++) {
				way[num][k] = loc[0][k];
				can[num] = 1;
			}
			num++;
		}
		loc[0][i]++;
		loc[0][i] %= 10;
		loc[0][i - 1]++;
		loc[0][i - 1] %= 10;
	}
	for (int i = 1 ; i <= n - 1; i++) {
		for (int j = 0; j < 100; j++) {
			if (can[j]) {
				can[j] = cmp(j, i);
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		if (can[i]) {
			for (int j = 0; j < 5; j++) {
				cout << way[i][j] << " ";
			}
			cout << endl;
			ans++;
		}
	}
	cout << ans;
	return 0;
}