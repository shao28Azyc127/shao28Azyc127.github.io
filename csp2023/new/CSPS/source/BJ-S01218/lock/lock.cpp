#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
int a[10][10];
int b[11][11][11][11][11];
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	int www= 0;
	if(n == 1){
		cout << 81;
		return 0;
	}
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){//dange qingkuang
		for(int j = 0; j <= 9; j++){
			if(j == a[i][1]) continue;
			//www++;
			b[j][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
			//cout << b[j][a[i][2]][a[i][3]][a[i][4]][a[i][5]] << endl;
		}
		for(int j = 0; j <= 9; j++){
			if(j == a[i][2]) continue;
			//www++;
			b[a[i][1]][j][a[i][3]][a[i][4]][a[i][5]]++;
			//cout << b[a[i][1]][j][a[i][3]][a[i][4]][a[i][5]] << endl;
		}
		for(int j = 0; j <= 9; j++){
			if(j == a[i][3]) continue;
			//www++;
			b[a[i][1]][a[i][2]][j][a[i][4]][a[i][5]]++;
			//cout << b[a[i][1]][a[i][2]][j][a[i][4]][a[i][5]] << endl;
		}
		for(int j = 0; j <= 9; j++){
			if(j == a[i][4]) continue;
			//www++;
			b[a[i][1]][a[i][2]][a[i][3]][j][a[i][5]]++;
			//cout << b[a[i][1]][a[i][2]][a[i][3]][j][a[i][5]] << endl;
		}
		for(int j = 0; j <= 9; j++){
			if(j == a[i][5]) continue;
			//www++;
			b[a[i][1]][a[i][2]][a[i][3]][a[i][4]][j]++;
			//cout << b[a[i][1]][a[i][2]][a[i][3]][a[i][4]][j] << endl;
		}
	}
	for(int i = 1; i <= n; i++){//liande
		for(int j = 0; j <= 9; j++){
			if(a[i][1] == j) continue;
		//	www++;
			int cha = a[i][1]-j;//under cha ge
			int cha2 = a[i][2]-cha;//under cha
			//cout << cha << endl;
			//cout << cha2 << endl;
			if(cha2 < 0) cha2 += 10;
			if(cha2 > 9) cha2 -= 10;
			//cout << cha2 << endl;
			b[j][cha2][a[i][3]][a[i][4]][a[i][5]]++;
		}
		for(int j = 0; j <= 9; j++){
			if(a[i][2] == j) continue;
			//www++;
			int cha = a[i][2]-j;//under cha ge
			int cha2 = a[i][3]-cha;//under cha ge
			if(cha2 < 0) cha2 += 10;
			if(cha2 > 9) cha2 -= 10;
			b[a[i][1]][j][cha2][a[i][4]][a[i][5]]++;
		}
		for(int j = 0; j <= 9; j++){
			if(a[i][3] == j) continue;
			//www++;
			int cha = a[i][3]-j;//under cha ge
			int cha2 = a[i][4]-cha;//under cha ge
			if(cha2 < 0) cha2 += 10;
			if(cha2 > 9) cha2 -= 10;
			b[a[i][1]][a[i][2]][j][cha2][a[i][5]]++;
		}
		for(int j = 0; j <= 9; j++){
			if(a[i][4] == j) continue;
			//www++;
			int cha = a[i][4]-j;//under cha ge
			int cha2 = a[i][5]-cha;//under cha ge
			if(cha2 < 0) cha2 += 10;
			if(cha2 > 9) cha2 -= 10;
			b[a[i][1]][a[i][2]][a[i][3]][j][cha2]++;
		}
	}
	for(int v = 0; v <= 9; v++){
		for(int w = 0; w <= 9; w++){
			for(int x = 0; x <= 9; x++){
				for(int y = 0; y <= 9; y++){
					for(int z = 0; z <= 9; z++){
						if(b[v][w][x][y][z] == n) ans++;
					}
				}
			}
		}
	}
	cout << ans /*<< " " << www*/ ;
	return 0;
}
