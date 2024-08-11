#include<bits/stdc++.h>
using namespace std;
int n, a[9][6], flag[6][2];
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	if(n == 1){
		cout << "81";
	}else{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++){
				scanf("%d", &a[i][j]);
				if(!flag[j][0]){
					flag[j][0] = a[i][j];
				}else if(flag[j][0] != a[i][j]){
					flag[j][1] = 1;
				}
			}
		}
		int flagg = 0, x = 0, y = 0;
		for(int i = 0; i < 5; i++){
			if(flag[i][1] == 1 && x == 0){
				x = i;
			}else if(flag[i][1] == 1 && y == 0)y = i;
			flagg+=flag[i][1];
		}
		if(flagg >2){
			cout << "0";
		}else{
			if(x-y != 1&&y-x != 1 && x != 0 && y != 0){
				cout << "0";
			}else if(x == 0){
				for(int i = 0; i < n; i++){
					if(a[i][y-1] == a[i][y] || a[i][y + 1] == a[i][y]){
						cout << "10";
						return 0;
					}
				}
				cout <<  10 - n;
			}else if(y == 0){
				for(int i = 0; i < n; i++){
					if(a[i][x-1] == a[i][x] || a[i][x + 1] == a[i][x]){
						cout << "10";
						return 0;
					}
				}
				cout <<  10 - n;
			}else{
				int qqq = 1;
				for(int i = 1; i < n;i++){
					if(a[i-1][x]-a[i-1][y] != a[i][x] - a[i][y]){
						qqq = 0;
						break;
					}
				}
				if(qqq){
					cout << 10 - n;
				}else{
					cout << "0";
				}
			}
		}
	}
	return 0;
}
