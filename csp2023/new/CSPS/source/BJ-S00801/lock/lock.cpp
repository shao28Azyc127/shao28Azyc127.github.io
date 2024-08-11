#include <cstdio>
#include <iostream>
using namespace std;
int mp[13] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int n, a[10][6];
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= 5; j ++){
			cin >> a[i][j];
		}
	}
	if(n == 1){
		cout << 81;
		return 0;
	}
	if(n == 2){
		int cnt = 0;
		int de = 0, des1 = 0, dex1 = 0, des2 = 0, dex2 = 0;
		for(int i = 1; i <= 5; i ++){
			if(a[1][i] != a[2][i]){
				de ++;
				if(des1 == 0){
					des1 = a[1][i];
					dex1 = a[2][i];
				}else {
					des2 = a[1][i];
					dex2 = a[2][i];
				}
			}
		}
		if(de == 1)cnt = 7;
		if(de == 0)cnt = 32;
		if(de == 2){
			if(des1 - des2 == dex1 - dex2 || des1 - des2 == dex1 - dex2 + 10 || des1 - des2 == dex1 - dex2 - 10){
				cnt = 8;
			}
		}
		if(de > 2)cnt = 0;
		cout << cnt;
		return 0;
	}
	if(n > 2){
		int cnt = 0;
		int de = 0;
		for(int i = 1; i <= 5; i ++){
			for(int j = 1; j <= n; j ++){
				if(a[j][i] != a[1][i]){
					de ++;
					break;
				}
			}
		}
		if(de == 1) cnt = 9-n;
		if(de == 0) cnt = 32;
		cout << cnt;
		return 0;
	}
	return 0;
}
