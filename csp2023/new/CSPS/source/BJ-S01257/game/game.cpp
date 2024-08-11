#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;

int n;
int qwq[50];
int a[N], lst[N], f[N], tot[N];

ll ans;

stack <int> s;

int check(int x) {
	while(s.size())
		s.pop();
	for(int i = x; i >= 1; i--) {
		if(s.size() && s.top() == a[i])
			s.pop();
		else
			s.push(a[i]);
		if(!s.size())
			return i;
	}
	return 0;
}

bool check(int l, int r) {
	while(s.size())
		s.pop();
	for(int i = l; i <= r; i++)
		if(s.size() && s.top() == a[i])
			s.pop();
		else
			s.push(a[i]);
	if(s.size())
		return 0;
	return 1;
}

void sol1() {
	for(int i = 1; i <= n; i++) {
		//if(!lst[i])
		//	continue;
		int k = check(i);
		//if(check(lst[i] + 1, i - 1))
		if(k)
			f[i] = f[k - 1] + 1;
		//if(f[i] != f[lst[i] - 1] + 1 && lst[i])
		//	cout << i << endl;
		//f[i] = f[lst[i] - 1] + 1;
		ans += f[i];
	}
	cout << ans;
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = c - 'a';
		lst[i] = qwq[a[i]], qwq[a[i]] = i;
	}
	if(n <= 8000) {
		sol1();
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(!lst[i])
			continue;
		if(check(lst[i] + 1, i - 1))
			f[i] = f[lst[i] - 1] + 1;
		ans += f[i];
	}
	cout << ans;
	return 0;
}
