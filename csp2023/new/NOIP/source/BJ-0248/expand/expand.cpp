#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int c = 0;
int n = 0;
int m = 0;
int q = 0;
inline int read(){
	int x=  0;
	char ch = getchar();
	int f = 1;
	while(ch < '0'  || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int x[500010];
int y[500010];
int svx[500010];
int svy[500010];
bool dp1[3010][3010];
bool dp2[3010][3010];
inline void solve(){
	dp1[1][1] = (x[1] > y[1]);
	for(int i = 2; i <= n; i++){
		dp1[i][1] = dp1[i - 1][1] & (x[i] > y[1]);
	}
	for(int i = 2; i <= m; i++){
		dp1[1][i] = dp1[1][i - 1] & (x[1] > y[i]);
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(x[i] > y[j]){
				dp1[i][j] = dp1[i - 1][j] | dp1[i][j - 1] | dp1[i - 1][j - 1];
			}
		}
	}
	dp2[1][1] = (x[1] < y[1]);
	for(int i = 2; i <= n; i++){
		dp2[i][1] = dp2[i - 1][1] & (x[i] < y[1]);
	}
	for(int i = 2; i <= m; i++){
		dp2[1][i] = dp2[1][i - 1] & (x[1] < y[i]);
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(x[i] < y[j]){
				dp2[i][j] = dp2[i - 1][j] | dp2[i][j - 1] | dp2[i - 1][j - 1];
			}
		}
	}
}
signed main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	c = read(), n = read(), m = read(), q = read();
	for(int i = 1; i <= n; i++){
		x[i] = read();
	}
	for(int i = 1; i <= m; i++){
		y[i] = read();
	}
	solve();
	putchar((dp1[n][m] | dp2[n][m]) + '0');
	while(q --){
		int kx = read();
		int ky = read();
		for(int i = 1; i <= n; i++){
			svx[i] = x[i];
		}
		for(int i = 1; i <= m; i++){
			svy[i] = y[i];
		}
		for(int i = 1; i <= kx; i++){
			int a = read();
			int b = read();
			x[a] = b;
		}
		for(int i = 1; i <= ky; i++){
			int a = read();
			int b = read();
			y[a] = b;
		}
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		solve();
		char ans = (dp1[n][m] | dp2[n][m]) + '0';
		putchar(ans);
		for(int i = 1; i <= n; i++){
			x[i] = svx[i];
//			cout << x[i] << " ";
		}
		for(int i = 1; i <= m; i++){
			y[i] = svy[i];
//			cout << y[i] << " " ;
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << dp1[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << dp2[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	cout << (dp1[n][m] | dp2[n][m]);
	return 0;
}
//NOIP2023 RP++!!!