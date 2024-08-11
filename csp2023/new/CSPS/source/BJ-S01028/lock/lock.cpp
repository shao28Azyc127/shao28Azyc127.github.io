//CSP2023 RP++ !!!!
#include <iostream>
#define int long long
using namespace std;
int n = 0;
int lst[6];
int cur[6];
int tong[1000010];
signed main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin >> lst[j];	
		}	
		for(int j = 1; j <= 5; j++){
			for(int k = 1; k <= 5; k++){
				cur[k] = lst[k]; 
			}
			for(int k = 1; k <= 9; k++){
				cur[j] ++;
				if(cur[j] == 10){
					cur[j] = 0;
				}
				int curr = 0;
				for(int l = 1; l <= 5; l++){
					curr = curr * 10 + cur[l];
				}
				tong[curr] ++;
			}
		}
		for(int j = 1; j <= 4; j++){
			for(int k = 1; k <= 5; k++){
				cur[k] = lst[k]; 
			}
			for(int k = 1; k <= 9; k++){
				cur[j] ++;
				cur[j + 1] ++;
				if(cur[j] == 10){
					cur[j] = 0;
				}
				if(cur[j + 1] == 10){
					cur[j + 1] = 0;
				}
				int curr = 0;
				for(int l = 1; l <= 5; l++){
					curr = curr * 10 + cur[l];
				}
				tong[curr] ++;
			}
		}
	}
	int cnt = 0;
	for(int i = 0;  i < 1e6; i++){
		if(tong[i] == n){
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
//CSP2023 RP++ !!!!