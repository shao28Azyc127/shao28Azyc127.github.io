#include <bits/stdc++.h>
using namespace std;
void file() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
}
int ans, n;
vector <char > g, g2;
bool ck(string s) {
	int cnt = 0;
	while(1) {
		string str = "";
		int ag = 0;
	    for(int i = 0; i < s.size(); ++i) {
		    if(s[i] == s[i + 1]) s.erase(i, 2), ag = 1;;
		    if(s == "") return 1;
		    
	    }
	    if(s == "") return 1;
	    if(!ag) return 0;
	}	
}
int main() {
	file();
	cin >> n;
	string s; cin >> s;
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 1; i + j - 1 < n; ++j) {
			string str = s.substr(i, j);
			cout << str << endl;
			if(ck(str)) ++ans;
		}
    }
    cout << ans;
}
