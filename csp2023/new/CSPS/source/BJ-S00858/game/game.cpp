#include <bits/stdc++.h>
using namespace std;
string ins;
int n;
long long ans = 0;
bool Del(string str) {
	string nxt = "";
	for(int i = 0;i < str.size();i++) {
		if(str[i+1] != str[i]) {
			nxt = nxt + str[i];
			continue;
		}
		while(str[i+1] == str[i])	++i;
	}
	if(!nxt.size()) 
		return true;
	else if(nxt.size() == str.size())
		return false;
	else
		return Del(nxt);
}
int main() { 
	freopen("game.in" , "r" , stdin);
	freopen("game.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin >> n >> ins;
	for(int len = 2;len <= n;len+=2) {
		for(int i = 0;i <= n-len;i++) {
			string tmp;
			for(int j = i;j <= i+len-1;j++)
				tmp = tmp + ins[j];
//cout << tmp << endl;
			if(Del(tmp))
				ans++;
//cout << Del(tmp) << endl;
		}
	}
	cout << ans << endl;
	return 0;
}