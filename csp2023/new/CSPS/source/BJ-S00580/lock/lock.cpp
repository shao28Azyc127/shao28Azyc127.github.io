#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("lock.in", "r", stdin); freopen("lock.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
int n, a[10][7], cnt[7][10], c[10][7];
ll ans;
int main(){ File ? file() : void(); INIT();
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin >> a[i][j];
			cnt[j][a[i][j]]++;
			if(j >= 2) c[i][j] = a[i][j] - a[i][j - 1];
		}
	}
	for(int i = 1; i <= 5; i++){
		bool fl = true;
		for(int j = 1; j <= 5; j++){
			if(i == j) continue;
			if(cnt[j][a[1][j]] != n){fl = false; break;}
		}
		/*int tmp = 0;
		for(int j = 0; j <= 9; j++) tmp += cnt[i][j];*/
		if(fl) ans += (10 - (n == 1));
	}
	for(int i = 2; i <= 5; i++){
		bool fl = true;
		for(int j = 2; j <= n; j++){
			if(c[j][i] == c[j - 1][i] || c[j][i] + c[j - 1][i] == 10) continue;
			fl = false; break;
		}
		for(int j = 1; j <= 5; j++){
			if(i == j || i - 1 == j) continue;
			if(cnt[j][a[1][j]] != n){fl = false; break;}
		}
		/*int tmp = 0;
		unordered_map<int, int> mp;
		for(int j = 1; j <= n; j++){
			int num = a[j][i - 1] * 10 + a[j][i];
			if(!mp.count(num)) mp[num] = 1, tmp++;
		}*/
		if(fl) ans += (10 - (n == 1));
	}
	cout << ans << endl;
	return 0;
}