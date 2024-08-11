#include <iostream>
#include <cmath>
#define int long long
using namespace std;
int t = 0;
int sym[100010];
int x[100010];
int y[100010];
int xc[100010];
int xc2[100010];
int n = 0;
int m = 0;
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
signed main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	read();
	t = read();
	while(t --){
		n = read();
		m = read();
		for(int i = 1; i <= m; i++){
			char ch = getchar();
			if(ch == '-'){
				x[i] = read();
				y[i] = read(); 
				sym[i] = -1;
			}
			if(ch == '+'){
				x[i] = read();
				y[i] = read(); 
				sym[i] = 1;
			}
			if(ch == 'T'){
				x[i] = read();
				sym[i] = 2;
			}
			if(ch == 'F'){
				x[i] = read();
				sym[i] = -2;
			}
			if(ch == 'U'){
				x[i] = read();
				sym[i] = 0;
			}
			xc[i] = i;
		}
		int cnt = 0;
		int cflg = 0;
		bool t = 0;
		while(true){
			cnt = 0;
			bool flg = 0;
			for(int j = 1; j <= m; j++){
				if(sym[j] == -1){
					xc[x[j]] = -xc[y[j]];
				}
				if(sym[j] == 1){
					xc[x[j]] = xc[y[j]];
				}
				if(sym[j] == 2){
					xc[x[j]] = 114514;
				}
				if(sym[j] == -2){
					xc[x[j]] = -114514;
				}
				if(sym[j] == 0){
					xc[x[j]] = 0;
				}
			}
			bool cc = false;
			for(int j = 1; j <= n; j++){
//				if(xc[j] != xc2[j] && xc[j] != xc3[j]){
//					flg = false;
//				}
				if(xc[j] == -xc2[j] && xc[j] != 0 || xc[j] == -j){
					cflg = 0;
					cc = true;
					xc[j] = 0;
					cnt ++;
				}
				if(!cc){
					cflg ++;
					cc = true;
				}
//				cout << xc[j] << " ";
				xc2[j] = xc[j];
				
			}
			if(cflg >= n && t){
				flg = true;
			}
//			cout << flg;
			if(!t){
				t = 1;
				cflg = 0;
			}
//			cout << endl;
			if(flg){
				break;
			}
		}
		for(int j = 1; j <= n; j++){
			if(xc[j] == 0){
				cnt ++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
//NOIP2023 RP++!!!