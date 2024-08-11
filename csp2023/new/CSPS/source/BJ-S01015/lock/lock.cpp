#include <bits/stdc++.h>
using namespace std;
long long n, a[15][15], b[15][15], zt[100005][15], zt2[100005][15], zt3[100005][15], cnt = 0;
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++){
		for (long long j = 1; j <= 5; j++){
			scanf("%lld", &a[i][j]);
		}
	}
	for (long long j = 1; j <= 5; j++){
		for (long long l = 0; l <= 9; l++){
			if (l == a[1][j]){
				continue;
			}
			cnt++;
			for (long long k = 1; k <= 5; k++){
				if (k == j){
					zt[cnt][k] = l;
				}else{
					zt[cnt][k] = a[1][k];
				}
			}
		}
	}
	for (long long j = 1; j <= 4; j++){
		for (long long l = 1; l <= 9; l++){
			cnt++;
			for (long long k = 1; k <= 5; k++){
				if (k == j || k == j + 1){
					zt[cnt][k] = a[1][k];
					for (long long p = 1; p <= l; p++){
						zt[cnt][k]++;
						if (zt[cnt][k] == 10){
							zt[cnt][k] = 0;
						}
					}
				}else{
					zt[cnt][k] = a[1][k];
				}
			}
		}
	}
	for (long long i = 2; i <= n; i++){
		long long cnt2 = 0;
		for (long long j = 1; j <= 5; j++){
			for (long long l = 0; l <= 9; l++){
				if (l == a[i][j]){
					continue;
				}
				cnt2++;
				for (long long k = 1; k <= 5; k++){
					if (k == j){
						zt2[cnt2][k] = l;
					}else{
						zt2[cnt2][k] = a[i][k];
					}
				}
			}
		}
		for (long long j = 1; j <= 4; j++){
			for (long long l = 1; l <= 9; l++){
				cnt2++;
				for (long long k = 1; k <= 5; k++){
					if (k == j || k == j + 1){
						zt2[cnt2][k] = a[i][k];
						for (long long p = 1; p <= l; p++){
							zt2[cnt2][k]++;
							if (zt2[cnt2][k] == 10){
								zt2[cnt2][k] = 0;
							}
						}
					}else{
						zt2[cnt2][k] = a[i][k];
					}
				}
			}
		}
		long long cnt3 = 0;
		for (long long j = 1; j <= cnt; j++){
			bool flag = false;
			for (long long k = 1; k <= cnt2; k++){
				bool flg1 = true;
				for (long long l = 1; l <= 5; l++){
					if (zt[j][l] != zt2[k][l]){
						flg1 = false;
						break;
					}
				}
				if (flg1){
					flag = true;
					break;
				}
			}
			if (flag){
				cnt3++;
				for (long long k = 1; k <= 5; k++){
					zt3[cnt3][k] = zt[j][k];
				}
			}
		}
		cnt = cnt3;
		for (long long j = 1; j <= cnt3; j++){
			for (long long k = 1; k <= 5; k++){
				zt[j][k] = zt3[j][k];
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
