#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vint> vvint;

ll read() {
	ll a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const int N = 100005;
vint e[N];
ll a[N], b[N], c[N];
int n, d[N], du[N];
__int128 qry(ll b, ll c, ll m) {
	if (c >= 0) return (b + c + b + c * m) * __int128(m) / 2;
	ll v = (1 - b) / c;
	v = min(v, m);
	return (b + c + b + c * v) * __int128(v) / 2 + (m - v);
}

struct dat {
	int i;
	dat(int a = 0) { i = a; }
};
bool operator < (dat a, dat b) { return d[a.i] < d[b.i]; }
bool chk() {
	priority_queue<dat> q;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == -1) return 0;
		d[i] = min(d[i], n);
		du[i] = e[i].size();
		if (du[i] == 1) q.push(i);
	}
	d[1] = 1;
	for (int i = n; i >= 1; --i) {
		int u = q.top().i; q.pop();
		if (d[u] < i) return 0;
		for (int v : e[u]) if (--du[v] == 1) q.push(v);
	}
	return 1;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = read(), c[i] = read();
	for (int i = 1; i < n; ++i) { int u = read(), v = read(); e[u].push_back(v), e[v].push_back(u); }
	ll l = 1, r = 1.1e9, mid, ans = 2e9;
	while (l <= r) {
		mid = (l + r) / 2;
		for (int i = 1; i <= n; ++i) {
			__int128 qwq = qry(b[i], c[i], mid) - a[i];
			if (qwq < 0) { d[i] = -1; break; }
			if (qwq >= qry(b[i], c[i], n - 1)) { d[i] = n; continue; }
			ll l = 1, r = n, m;
			while (l <= r) {
				m = (l + r) / 2;
				if (qwq >= qry(b[i], c[i], m - 1)) d[i] = m, l = m + 1;
				else r = m - 1;
			}
		}
		//cerr << " : " << mid << endl;
		if (chk()) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}


/*
好像又 AK 了。不过没有对拍阿，反正挂了也无所谓。
不知道 T4 __int128 和 log ^ 2 会不会被卡常。感觉应该不会，大样例 0.5s。被卡常就伤心了。
其实主要还是不想硬算二次不等式。

对题目进行一个瑞平：垃圾。
阿现在是 17:08，比上次 AK 快好多。
其实不到 1h 就都会了。T3 写了比较久但是基本上一遍写对很爽。

好好好继续瑞平。
T1 什么垃圾模拟题，这也敢放 CSP-S T1？对比一下之前的。难度完全不一样吧。
T2 大概是最好的题了。当然可能这是套路就不好了。
做法大概是，考虑判定：设一个栈，相同则弹，不同则入。
扫右端点，维护所有左端点的栈。把栈看成串，上面在前。
把串入trie，考虑trie变化：把一个点转到根。然后直接维护。
感觉有点高妙的。
T3 什么垃圾模拟题。不过代码不长。
T4 感觉神秘也有点垃圾。
考虑二分答案，然后求出每个点至少要在哪个时刻之前种树。这个可以二分（虽然有那么亿点点慢）。
然后有点高妙的，正着做好像不太能单 log，然后你反着做，删叶子，堆维护就行。
O(n log ^ 2 n) 的。
代码也不长。
甚至四个题按我的代码风格加起来没 5k。

*/
