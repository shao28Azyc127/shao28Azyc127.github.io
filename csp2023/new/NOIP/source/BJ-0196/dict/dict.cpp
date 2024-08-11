#include <bits/stdc++.h>
using namespace std;
long long n, m, bk[1005];
char a[3005][3005];
string b[3005], zheng[3005], fan[3005];
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++){
		for (long long j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for (long long i = 1; i <= n; i++){
		for (long long j = 0; j <= 25; j++){
			bk[j] = 0;
		}
		for (long long j = 1; j <= m; j++){
			bk[a[i][j] - 'a']++;
		}
		fan[i] = "";
		for (long long j = 25; j >= 0; j--){
			for (long long k = 1; k <= bk[j]; k++){
				fan[i] += (char)(j + 'a');
			}
		}
	}
	for (long long i = 1; i <= n; i++){
		for (long long j = 0; j <= 25; j++){
			bk[j] = 0;
		}
		for (long long j = 1; j <= m; j++){
			bk[a[i][j] - 'a']++;
		}
		zheng[i] = "";
		for (long long j = 0; j <= 25; j++){
			for (long long k = 1; k <= bk[j]; k++){
				zheng[i] += (char)(j + 'a');
			}
		}
	}
	for (long long num = 1; num <= n; num++){
		if (n == 1){
			cout << "1";
		}else{
			bool flg = true;
			for (long long i = 1; i <= n; i++){
				if (i == num){
					continue;
				}
				if (zheng[num] >= fan[i]){
					flg = false;
					break;
				}
			}
			if (flg){
				cout << "1";
			}else{
				cout << "0";
			}
		}
	}
	cout << endl;
	return 0;
}
