#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
char cmp[3010][3010];
char crev[3010][3010];
string mp[3010];
string rev[3010];
int n = 0 ;
int m  =0;
signed main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char ch = getchar();
			while(ch < 'a' || ch > 'z'){
				ch = getchar();
			}
			cmp[i][j] = ch;
		}
		sort(cmp[i] + 1, cmp[i] + 1 + m);
		for(int j = m; j >= 1; j--){
			crev[i][m - j + 1] = cmp[i][j];
		}
		cmp[i][0] = ' ';
		crev[i][0] = ' ';
		for(int j = 1; j <= m; j++){
			mp[i] += cmp[i][j];
			rev[i] += crev[i][j];
		}
	}
//	for(int i = 1; i <= n; i++){
//		bool flg = true;
//		for(int j = 1; j <= n; j++){
//			
//		}
//	}
//	cout << (string(mp[4] ) < string(rev[3] )) << '\n'; 
//	cout << mp[4] << '\n'; 
//	cout << rev[3] << '\n'; 
	for(int i = 1; i <= n; i++){
		bool flg = true;
		for(int j = 1;j <= n; j++){
			if(j == i){
				continue;
			}
			if((mp[i]) > (rev[j])){
				flg = false;
				break;
			}
		}
		if(flg){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	return 0;
}
//NOIP2023 RP++!!!