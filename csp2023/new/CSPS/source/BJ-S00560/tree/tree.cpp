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
������ AK �ˡ�����û�ж��İ�����������Ҳ����ν��
��֪�� T4 __int128 �� log ^ 2 �᲻�ᱻ�������о�Ӧ�ò��ᣬ������ 0.5s���������������ˡ�
��ʵ��Ҫ���ǲ���Ӳ����β���ʽ��

����Ŀ����һ����ƽ��������
�������� 17:08�����ϴ� AK ��öࡣ
��ʵ���� 1h �Ͷ����ˡ�T3 д�˱ȽϾõ��ǻ�����һ��д�Ժ�ˬ��

�úúü�����ƽ��
T1 ʲô����ģ���⣬��Ҳ�ҷ� CSP-S T1���Ա�һ��֮ǰ�ġ��Ѷ���ȫ��һ���ɡ�
T2 �������õ����ˡ���Ȼ����������·�Ͳ����ˡ�
��������ǣ������ж�����һ��ջ����ͬ�򵯣���ͬ���롣
ɨ�Ҷ˵㣬ά��������˵��ջ����ջ���ɴ���������ǰ��
�Ѵ���trie������trie�仯����һ����ת������Ȼ��ֱ��ά����
�о��е����ġ�
T3 ʲô����ģ���⡣�������벻����
T4 �о�����Ҳ�е�������
���Ƕ��ִ𰸣�Ȼ�����ÿ��������Ҫ���ĸ�ʱ��֮ǰ������������Զ��֣���Ȼ����ô�ڵ��������
Ȼ���е����ģ�����������̫�ܵ� log��Ȼ���㷴������ɾҶ�ӣ���ά�����С�
O(n log ^ 2 n) �ġ�
����Ҳ������
�����ĸ��ⰴ�ҵĴ����������û 5k��

*/
