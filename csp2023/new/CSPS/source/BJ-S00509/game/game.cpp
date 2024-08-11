#include<bits/stdc++.h>
using namespace std;
//File Redirect
#define FILE "game"
void redirIO() {
	if (FILE != "") {
		freopen(FILE".in", "r", stdin);
		freopen(FILE".out", "w", stdout);
	}
}
//Type Rename
typedef long long LL;
typedef unsigned long long ULL;
//Constants
const int N = 2e6 + 5;
//Variables
int n, tot;
string s;

int play(string &obj) {
	int res = 0;
	for (int i = 0; i < (int)obj.size() - 1; i++) {
		int cur = 0;
		while (i < (int)obj.size() - 1 && obj[i] == obj[i + 1]) {
			obj.erase(i, 2);
			cur++;
		}
		res += (cur * cur + cur) / 2;
	}
	return res;
}
//Main
int main() {
	redirIO();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	int played = play(s);
	while (played) {
		tot += played, played = play(s);
	}
	cout << tot;
	return 0;
}
