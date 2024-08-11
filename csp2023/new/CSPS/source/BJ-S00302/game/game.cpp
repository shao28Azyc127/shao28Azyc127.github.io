#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

#define fi first
#define se second
#define mk make_pair

const int MX = 2000005;

int n;
char str[MX];

bool vis[30];
stack <pair<int, char> > st;

int ans;
int dycnt[30];

void work(int beg) {
	int nowcnt = 0;
	stack <pair<int, char> > st;
	stack <char> dyst[30];
	for(int i = 0; i < 26; i++)
		vis[i] = false;
	for(int i = beg; i <= n; i++) {
		for(int j = 0; j < 26; j++) {
			if(!vis[j]) continue;
			if(!dyst[j].empty() && dyst[j].top() == str[i]) dyst[j].pop();
			else dyst[j].push(str[i]);
			if(dyst[j].empty()) {
				dycnt[j]++;
				ans += dycnt[j];
			}
		}
		if(!st.empty() && st.top().se == str[i]) {
			nowcnt = st.top().fi + 1;
			ans += nowcnt;
			st.pop();
			vis[str[i] - 'a'] = true;
			if(!dyst[str[i] - 'a'].empty()) dycnt[str[i] - 'a'] = 0;
			while(!dyst[str[i] - 'a'].empty()) dyst[str[i] - 'a'].pop();
			dyst[str[i] - 'a'].push(str[i]);
			continue;
		}
		st.push(mk(nowcnt, str[i]));
		nowcnt = 0;
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	getchar();
	for(int i = 1; i <= n; i++)
		str[i] = getchar();
	work(1);
	cout << ans;
	return 0;
}
