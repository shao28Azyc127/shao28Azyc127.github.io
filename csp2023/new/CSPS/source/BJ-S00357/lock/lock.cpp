#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][5];
int tmp[100050][5];
int flag[5];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) for (int j = 0;j < 5;j++) cin >> a[i][j];
	//if (n == 1) cout << 81;
	//else {
		for (int i = 0;i < 10;i++){
			for (int j = 0;j < 10;j++){
				for (int k = 0;k < 10;k++){
					for (int a = 0;a < 10;a++){
						for (int b = 0;b < 10;b++){
							int m = i * 10000 + j * 1000 + k * 100 + a * 10 + b;
							tmp[m][0] = i;
							tmp[m][1] = j;
							tmp[m][2] = k;
							tmp[m][3] = a;
							tmp[m][4] = b;
						}
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0;i < 100000;i++){
			int flag = 0;
			for (int j = 0;j < n;j++){
				int cnt1 = 0;
				for (int k = 0;k < 5;k++){
					if (tmp[i][k] != a[j][k]) cnt1++;
					if (tmp[i][k] != a[j][k] && cnt1 == 2){
						if (tmp[i][k - 1] - a[j][k - 1] != tmp[i][k] - a[j][k] && tmp[i][k - 1] - a[j][k - 1] + 10 != tmp[i][k] - a[j][k] && tmp[i][k - 1] - a[j][k - 1] - 10 != tmp[i][k] - a[j][k]){
							flag = 1;
						}
					}
					if (cnt1 > 2){
						flag = 1;
					}
				}
				if (cnt1 == 0){
					flag = 1;
				} 
			}
			if (flag == 0) cnt++;
		}
		cout << cnt;
	//}
	return 0;
}