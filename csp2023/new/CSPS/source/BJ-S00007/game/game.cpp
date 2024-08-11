/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans = 0;
string str;
queue<char> Q;

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	cin >> str;
	for(ll i = 0; i < (ll)str.length(); ++i){
		if(Q.front() == str[i]){
			Q.pop();
			ans++;
		}else{
			Q.push(str[i]);
		}
	}
	ll cnt = 0;
	while(Q.size() >= 2){
		char c = Q.front();
		Q.pop();
		if(c == Q.front()){
			ans++;
			cnt++;
		}
	}
	if(Q.empty()){
		ans++;
	}
	cout << ans + cnt << endl;
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans = 0;
string str;

bool check(string s){
	stack<char> S;
	for(ll i = 0; i < (ll)s.length(); ++i){
		if(S.empty()){
			S.push(s[i]);
		}else if(S.top() == s[i] && !S.empty()){
			S.pop();
		}else{
			S.push(s[i]);
		}
	}
	return S.empty();
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ll ans = 0;
	cin >> n;
	cin >> str;
	for(ll i = 2; i <= n; ++i){
		for(ll j = 0; j < n - i + 1; ++j){
			string tmp = str.substr(j, i);
			if(check(tmp)){
				ans++;
				//cout << tmp << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
