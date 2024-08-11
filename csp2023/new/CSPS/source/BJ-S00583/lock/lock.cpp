#include <iostream>

using namespace std;

const int N = 13;
int n, ans;
int a[N][7], b[7];

bool check(){
	for(int i = 1; i <= n; ++i){
		int op = 1, use = 0, cnt = 0, w1, w2;
		for(int j = 1; j <= 5; ++j){
			if(a[i][j] == b[j]) continue;
			cnt++;
			if(cnt > 2){
				op = 0;
				break;
			}
			if(cnt == 1) w1 = j;
			if(cnt == 2) w2 = j;
		}
		if(op == 0){
			return false;
		}
		if(cnt == 0){
			return false;
		}if(cnt == 2){
			if(abs(w1 - w2) != 1){
				return false;
			}
			int t1, t2;
			if(a[i][w1] >= b[w1]){
				t1 = a[i][w1] - b[w1];
			}else{
				t1 = 10 + a[i][w1] - b[w1];
			}
			if(a[i][w2] >= b[w2]){
				t2 = a[i][w2] - b[w2];
			}else{
				t2 = 10 + a[i][w2] - b[w2];
			}
			if(t1 != t2){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 5; ++j){
			cin >> a[i][j];
		}
	}
	for(b[1] = 0; b[1] < 10; ++b[1]){
		for(b[2] = 0; b[2] < 10; ++b[2]){
			for(b[3] = 0; b[3] < 10; ++b[3]){
				for(b[4] = 0; b[4] < 10; ++b[4]){
					for(b[5] = 0; b[5] < 10; ++b[5]){
						if(check()){
							ans++;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}