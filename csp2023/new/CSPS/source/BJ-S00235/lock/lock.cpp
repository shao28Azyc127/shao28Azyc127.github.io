#include <bits/stdc++.h>
using namespace std;
int n, a[15][10], now[10], now2[10], ans = 0;
inline bool pd(int x){
	for(int i = 1;i <= 5;i++){
		if(now2[i] != a[x][i]){
			return 0;
		}
	}
	return 1;
}
inline bool chk(){
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int j = 1;j <= 5;j++){
			if(now[j] != a[i][j]){
				cnt++;
			}
		}
		if(cnt == 1){
			continue;
		}
		if(cnt == 2){
			bool bo = 0;
			for(int j = 1;j <= 4;j++){
				for(int k = 1;k <= 9;k++){
					memcpy(now2, now, sizeof(now));
					now2[j] = (now2[j] + k)% 10;
					now2[j + 1] = (now2[j + 1] + k)% 10;
					if(pd(i)){
						bo = 1;
						break;
					}
				}
				if(bo == 1){
					break;
				}
			}
			if(bo){
				continue;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 5;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0;i <= 99999;i++){
		int my = i;
		for(int j = 5;j >= 1;j--){
			now[j] = my % 10;
			my /= 10;
		}
		if(chk()){
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
