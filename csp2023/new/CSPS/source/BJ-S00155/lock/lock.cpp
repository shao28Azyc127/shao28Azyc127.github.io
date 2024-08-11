# include <iostream>
# include <vector>
using namespace std;

int l1, l2, a[10][10], cor[100][10], cor2[100][10];

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 5; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++){
		if (i == 1){
			for (int j = 1; j <= 5; j++){
				for (char k = 0; k <= 9; k++){
					if (a[i][j] == k) continue;
					int t = a[i][j];
					a[i][j] = k;
					l1++;
					for (int l = 1; l <= 5; l++) cor[l1][l] = a[i][l];
					a[i][j] = t;
				}
			}
			for (int j = 1; j <= 4; j++){
				for (int k = 1; k <= 9; k++){
					int t1 = a[i][j], t2 = a[i][j + 1];
					a[i][j] += k;
					a[i][j + 1] += k;
					if (a[i][j] > 9) a[i][j] = a[i][j] % 9 - 1;
					if (a[i][j + 1] > 9) a[i][j + 1] = a[i][j + 1] % 9 - 1;
					l1++;
					for (int l = 1; l <= 5; l++) cor[l1][l] = a[i][l];
					a[i][j] = t1, a[i][j + 1] = t2;
				}
			}
		}
		else {
			for (int j = 1; j <= 5; j++){
				for (char k = 0; k <= 9; k++){
					if (a[i][j] == k) continue;
					int t = a[i][j];
					a[i][j] = k;
					l2++;
					for (int l = 1; l <= 5; l++) cor2[l2][l] = a[i][l];
					a[i][j] = t;
				}
			}
			for (int j = 1; j <= 4; j++){
				for (int k = 1; k <= 9; k++){
					int t1 = a[i][j], t2 = a[i][j + 1];
					a[i][j] += k;
					a[i][j + 1] += k;
					if (a[i][j] > 9) a[i][j] = a[i][j] % 9 - 1;
					if (a[i][j + 1] > 9) a[i][j + 1] = a[i][j + 1] % 9 - 1;
					l2++;
					for (int l = 1; l <= 5; l++) cor2[l2][l] = a[i][l];
					a[i][j] = t1, a[i][j + 1] = t2;
				}
			}
			for (int j = 1; j <= l1; j++){
				if (cor[j][1] == 10) continue;
				bool flag = 1;
				for (int k = 1; k <= l2; k++){
					bool flagin = 1;
					for (int l = 1; l <= 5; l++){
						if (cor[j][l] != cor2[k][l]){
							flagin = 0;
							break;
						}
					}
					if (flagin){
						flag = 0;
						break;
					}
				}
				if (flag) cor[j][1] = 10;
			}
		}
	}
	for (int i = 1; i <= l1; i++){
		if (cor[i][1] != 10){
			// for (int j = 1; j <= 5; j++) cout << cor[i][j] << " ";
			// cout << endl;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}