#include <iostream>
using namespace std; 

int n,nn;
int a[10][10],cnt;
bool flag[10];
int vis[10];

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
	}

	nn = n;

	for(int i = 1;i < n;i++){
		if(a[i][1] == a[i + 1][1] && a[i][2] == a[i + 1][2] && a[i][3] == a[i + 1][3] && a[i][4] == a[i + 1][4] && a[i][5] == a[i + 1][5]){
			nn--;
		}
	}

	if(n == 1){
		cout << 81;
		return 0;
	}
	
	for(int i = 1;i <= 5;i++){
		for(int j = 1;j <= n;j++){
			if(a[j][i] != a[1][i]){
				flag[i] = true;
				cnt++;
				break;
			}
		}
	}

	if(cnt >= 5){
		cout << 0;
		return 0;
	}

	if(cnt == 0){
		cout << 81;
		return 0;
	}
	if(n == 2){
		if(cnt == 1){
			cout << 10;
			return 0;
		}


		if(cnt == 2){
			int x = 0,y = 0;
			for(int i = 1;i <= 5;i++){
				if(flag[i] && x == 0){
					x = i;
					continue;
				}else if(flag[i]){
					y = i;
					break;
				}
			}
			if(abs(x - y) == 1){
				if(a[1][x] - a[1][y] == a[2][x] - a[2][y]){
					if(a[1][x] == a[1][y]) cout << 10;
					else cout << 8;
				}else cout << 2;

				return 0;
			}

			cout << 2;
			return 0;
		}
		
		for(int i = 1;i <= 5;i++){
			if(flag[i] && !flag[i + 1] && !flag[i - 1]){
				cout << 2;
				return 0;
			}
		}
	}

	if(cnt == 1){
		cout << 10 - nn;
		return 0;
	}

	for(int i = 1;i <= 5;i++){
		for(int j = 1;j <= n;j++){
			if(a[j][i] != a[1][i]){
				vis[j]++;
			}
		}
	}

	for(int i = 1;i <= n;i++){
		if(vis[i] > 1){
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}