#include<iostream>
using namespace std;
int n;
int a[11][45];
int b[14][19][19][18][10];
int add(int a, int b){
	return (a + b) % 10;
}
void plussss(int x){
	for(int i = 0; i <= 9; i++){
		if(i != a[x][1]){
			b[i][a[x][2]][a[x][3]][a[x][4]][a[x][5]]++;
		}
	}
	for(int i = 0; i <= 9; i++){
		if(i != a[x][2]){
			b[a[x][1]][i][a[x][3]][a[x][4]][a[x][5]]++;
		}
	}
	for(int i = 0; i <= 9; i++){
		if(i != a[x][3]){
			b[a[x][1]][a[x][2]][i][a[x][4]][a[x][5]]++;
		}
	}
	for(int i = 0; i <= 9; i++){
		if(i != a[x][4]){
			b[a[x][1]][a[x][2]][a[x][3]][i][a[x][5]]++;
		}
	}
	for(int i = 0; i <= 9; i++){
		if(i != a[x][5]){
			b[a[x][1]][a[x][2]][a[x][3]][a[x][4]][i]++;
		}
	}
	for(int i = 1; i <= 9; i++){
		b[add(a[x][1], i)][add(a[x][2], i)][a[x][3]][a[x][4]][a[x][5]]++;
	}
	for(int i = 1; i <= 9; i++){
		b[a[x][1]][add(a[x][2], i)][add(a[x][3], i)][a[x][4]][a[x][5]]++;
	}
	for(int i = 1; i <= 9; i++){
		b[a[x][1]][a[x][2]][add(a[x][3], i)][add(a[x][4], i)][a[x][5]]++;
	}
	for(int i = 1; i <= 9; i++){
		b[a[x][1]][a[x][2]][a[x][3]][add(a[x][4], i)][add(a[x][5], i)]++;
	}
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin >> a[i][j];
		}
		plussss(i);
	}
	int ans = 0;
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				for(int l = 0; l <= 9; l++){
					for(int o = 0; o <= 9; o++){
						if(b[i][j][k][l][o] >= n){
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}