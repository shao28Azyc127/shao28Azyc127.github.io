#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("game.in", "r", stdin); freopen("game.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 0;
int n;
string s;
int f[8005][8005];
int h[20000005], mp1[30], mp2[30];
ll ans;
bool check(int st, int ed){
	//cout << st << " " << ed << " " << f[st][ed] << endl;
	if(f[st][ed]) return f[st][ed] == 1 ? true : false;
	if(st >= ed) return false;
	if((ed - st + 1) % 2) return false;
	if(check(st + 1, ed - 1)) return true;
	for(int i = st + 1; i < ed; i += 2){
		//cout << i << " " << st << " " << ed << endl;
		//cout << check(st, i) << " " << check(i + 1, ed) << " " << st << " " << ed << endl;
		bool f1 = check(st, i), f2 = check(i + 1, ed);
		//cout << f1 << " " << f2 << endl;
		if(f1 && f2) return true;
	}
	return false;
}
int main(){ File ? file() : void(); INIT();
	cin >> n >> s;
	if(n >= 8000){
		mp1[0]++;
		for(int i = 0; i < s.size(); i++){
			h[i + 1] = (h[i] * 27 % mod + int(s[i] - 'a' + 1)) % mod;
			//cout << h[i + 1] << " ";
			//if(i == 3) cout << endl << h[i + 1] << " " << mp1[h[i + 1]] << " " << mp1[0] << endl;	
			if(i % 2) ans += mp1[h[i + 1]], mp1[h[i + 1]]++;
			else ans += mp2[h[i + 1]], mp2[h[i + 1]]++;
			cout << h[i + 1] << " ";
	}else{
		for(int i = 1; i < s.size(); i++)
			if(s[i] == s[i - 1]) f[i - 1][i] = 1;
			else f[i - 1][i] = 2;
		for(int i = 0; i < s.size(); i++){
			for(int j = i + 1; j < s.size(); j++){
				if((j - i + 1) % 2) continue;
				if(check(i, j)) f[i][j] = 1;
				else f[i][j] = 2;
				cout << i << " " << j << endl;
			} 
		}
		for(int i = 0; i < s.size(); i++)
			for(int j = i + 1; j < s.size(); j++)
				ans += ((f[i][j] == 1) ? 1 : 0);
	}
	cout << ans << endl;
	return 0;
}
