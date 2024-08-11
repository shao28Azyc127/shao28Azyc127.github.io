#include<bits/stdc++.h>
using namespace std;
struct f{
	int a, b, c, d, e;
};
int ans[10][10][10][10][10];
int a[10], b[10], c[10], d[10], e[10];
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n;
	cin >> n;
	if(n == 1){
		cout << 81;
		return 0;
	}
	for(int i = 1;i <= n;i ++) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	for(int aa = 0;aa <= 9;aa ++){
		for(int bb = 0;bb <= 9;bb ++){
			for(int cc = 0;cc <= 9;cc ++){
				for(int dd = 0;dd <= 9;dd ++){
					for(int ee = 0;ee <= 9;ee ++){
						for(int k = 1;k <= n;k ++){
							int cnt = 0;
							if(aa != a[k]) cnt ++;
							if(bb != b[k]) cnt ++;
							if(cc != c[k]) cnt ++;
							if(dd != d[k]) cnt ++;
							if(ee != e[k]) cnt ++;
							if(cnt >= 3) break;
							if(cnt == 1) ans[aa][bb][cc][dd][ee] ++;
							if(cnt == 2){
								if(aa != a[k] && bb == b[k]) break;
								if(aa == a[k] && bb != b[k] && cc == c[k]) break;
								if(bb == b[k] && cc != c[k] && dd == d[k]) break;
								if(cc == c[k] && dd != d[k] && ee == e[k]) break;
								if(dd == d[k] && ee != e[k]) break;
								if(aa != a[k] && bb != b[k]){
									int ans1 = (aa - a[k] + 10) % 10;
									int ans2 = (bb - b[k] + 10) % 10;
									if(ans1 == ans2) ans[aa][bb][cc][dd][ee] ++;
								}
								if(cc != c[k] && bb != b[k]){
									int ans1 = (cc - c[k] + 10) % 10;
									int ans2 = (bb - b[k] + 10) % 10;
									if(ans1 == ans2) ans[aa][bb][cc][dd][ee] ++;
								}
								if(dd != d[k] && cc != c[k]){
									int ans1 = (dd - d[k] + 10) % 10;
									int ans2 = (cc - c[k] + 10) % 10;
									if(ans1 == ans2) ans[aa][bb][cc][dd][ee] ++;
								}
								if(ee != e[k] && dd != d[k]){
									int ans1 = (ee - e[k] + 10) % 10;
									int ans2 = (dd - d[k] + 10) % 10;
									if(ans1 == ans2) ans[aa][bb][cc][dd][ee] ++;
								}
							}
						}
					}
				}
			}
		}
	}
	int aaaa = 0;
	for(int aa = 0;aa <= 9;aa ++){
		for(int bb = 0;bb <= 9;bb ++){
			for(int cc = 0;cc <= 9;cc ++){
				for(int dd = 0;dd <= 9;dd ++){
					for(int ee = 0;ee <= 9;ee ++){
						if(ans[aa][bb][cc][dd][ee] == n) aaaa ++;
					}
				}
			}
		}
	}
	cout << aaaa;
}