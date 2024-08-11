#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int n,ans;
string s;
map<string,int> mp;

bool check(string s){
	if(s.size() == 2 && s[0] == s[1]) return true;
	if(mp[s] == 1) return true;
	else if(mp[s] == 2) return false;

	for(int i = 0;i < s.size() - 1;i++){
		if(s[i] == s[i + 1]){
			if(check(s.substr(0,i) + s.substr(i + 2))){
				mp[s] = 1;
				return true;
			}else{
				mp[s] = 2;
				return false;
			}
		}
	}

	mp[s] = 2;
	return false;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> s;

	for(int i = 2;i <= n;i += 2){
		for(int j = 0;i + j - 1 < n;j++){
			if(check(s.substr(j,i))){
				ans++;
			}
		}
	}
	cout << ans;
}