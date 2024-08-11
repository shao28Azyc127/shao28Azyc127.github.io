#include <bits/stdc++.h>
using namespace std;
const int check[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1 ,2, 3, 4, 5 ,6, 7, 8, 9};
int x[10][10], a[10], cnt = 0;
map<int, int>m, m2;
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= 5 ; j++){
			cin >> x[i][j];
		}
	}
	if(n == 1){
		cout << 81 << endl;
		return 0;
	}
	for(int i = 0 ; i < 10 ; i++){
		m[check[i]] = i;
	}
	for(int i = 10 ; i < 20 ; i++){
		m2[check[i]] = i;
	}
	for(a[1] = 0 ; a[1] <= 9 ; a[1]++)
		for(a[2] = 0 ; a[2] <= 9 ; a[2]++)
			for(a[3] = 0 ; a[3] <= 9 ; a[3]++)
				for(a[4] = 0 ; a[4] <= 9 ; a[4]++)
					for(a[5] = 0 ; a[5] <= 9 ; a[5]++){
						bool flag = true;
						for(int i = 1 ; i <= n ; i++){
							int cntt = 0;
							for(int j = 1 ; j <= 5 ; j ++){
								if( a[j] != x[i][j] && a[j - 1] != x[i][j - 1]){
									if(m[a[j]] - m[a[j - 1]]== m[x[i][j]] - m[x[i][j - 1]]){
										if(j != 5)j++;
										else continue;
									}
									else if(m2[a[j]] - m[a[j - 1]]== m[x[i][j]] - m[x[i][j - 1]] || m[a[j]] - m2[a[j - 1]] == m[x[i][j]] - m[x[i][j - 1]]){
										if(j != 5)j++;
										else continue;
									}
								}
								if(a[j] != x[i][j]){
									cntt ++;
								}
							}
							if(cntt >= 2 || cntt == 0){
								flag = false;
								break;
							}
						}
						if(flag){
							cnt++;
						}
					}
	cout << cnt << endl;
	return 0;
}
