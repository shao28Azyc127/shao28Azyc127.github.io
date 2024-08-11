//CSP2023 RP++ !!!!
#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int n = 0;
string str = "";
bool mp[8010][8010];
int nxt[200010];
char ch;
int ans = 0;
signed main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	memset(nxt, 0x3f, sizeof(nxt));
	cin >> n;
	ch = getchar();
	while(ch < 'a' || ch > 'z'){
		ch = getchar();
	}
	while(ch >= 'a' && ch <= 'z'){
		str += ch;
		ch = getchar();
	}
	for(register int i = 0; i < n; i++){
		if(str[i] == str[i + 1]){
			for(register int j = 0; i - j >= 0 && i + 1 + j < n && str[i - j] == str[i + 1 + j]; j++){
//				if(str[i - j] != str[i + 1 + j]){
//					break;
//				}
				nxt[i - j] = min(nxt[i - j], i + 1 + j);
				mp[i - j][i + 1 + j] = 1;
//				cout << i - j << " " << i + 1 + j << endl;
			}
			
		}
	}
	for(register int i = n - 1; i >= 0; i--){
		for(register int j = i + 1; j < n; j++){
			if(mp[i][j]){
				ans ++;
			//	cout << i << " " << j << endl;
			}
			if(i > 0 && j < n - 1 && mp[i - 1][j + 1] == 0 && mp[i][j] == 1 && str[i - 1] == str[j + 1]){
				for(register int k = 1; i - k >= 0 && j + k < n && str[i - k] == str[j + k]; k++){
//					if(str[i - k] != str[j + k]){
//						break;
//					}
					nxt[i - k] = min(nxt[i - k], j + k);
					mp[i - k][j + k] = 1;
				}
			}		
			if(nxt[j + 1] <= 2e6 && mp[i][j]){
				mp[i][nxt[j + 1]] = 1;
//				cout << i << " " << j  << " " << nxt[j + 1] << endl;
			}
		}
	}
//	for(int i = 0; i < n; i++){
//		for(int j = i + 1; j < n; j++){
//			ans += mp[i][j];
//		}
//	}
	cout << ans;
	return 0;
}
//CSP2023 RP++ !!!!