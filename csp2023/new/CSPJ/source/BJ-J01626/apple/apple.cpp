#include<bits/stdc++.h>
using namespace std;
const int M = 10e8+2;
bool f[M];
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	int n, now, cnt = 1, day = -1, cd = 0;
	cin >> n;
	now = n;
	while(now){
		cd = 0;
		for(int i = 0; i < n; i ++){
			if(f[i]){
				continue;
			}
			else if(cd){
				cd --;
				continue;
			}
			f[i] = true;
			cd = 2;
			if(i == n - 1){
				day = cnt;
			}
			now --;
		}
		cnt ++;
	}
	cout << cnt - 1 << " " << day;
	return 0;
}