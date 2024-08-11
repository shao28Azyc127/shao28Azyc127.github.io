#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;

int t, cnt, tot, now;

char c[N], d[15], e[15];

struct Node {
	char s[15], ss[N][15];
	int k, num, cst;
	int b[N];
} a[N];

struct AA {
	int x, beg;
	char s[15], nam[15];
} b[N];

int to() {
	if(c[1] == 'b')
		return 1;
	if(c[1] == 's')
		return 2;
	if(c[1] == 'i')
		return 4;
	if(c[1] == 'l')
		return 8;
}

bool check(char qwq[15], char qaq[15]) {
	int l1 = strlen(qaq + 1), l2 = strlen(qwq + 1);
//	cout << "?" << (qaq + 1) << " " << (qwq + 1) << endl;
	if(l1 != l2)
		return 0;
	for(int i = 1; i <= l1; i++)
		if(qaq[i] != qwq[i])
			return 0;
	return 1;
}

void gets() {
	int l = strlen(c + 1);
	int i = 1;
	for(; i <= l; i++) 
		if(c[i] == '.')
			break;
		else
			d[i] = c[i];
	for(int j = i + 1; j <= l; j++)
		e[j - i] = c[j];
}

int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--) {
		int op, x;
		cin >> op;
		if(op == 1) {
			cnt++;
			cin >> (a[cnt].s + 1) >> a[cnt].k;
			for(int i = 1; i <= a[cnt].k; i++) {
				cin >> (c + 1) >> (a[cnt].ss[i] + 1);
				a[cnt].b[i] = to();
				a[cnt].num = max(a[cnt].num, a[cnt].b[i]);
			}
			a[cnt].cst = a[cnt].num * a[cnt].k;
			cout << a[cnt].cst << "\n";
		}
		if(op == 2) {
			tot++;
			cin >> (b[tot].s + 1) >> (b[tot].nam + 1);
			for(int i = 1; i <= cnt; i++) {
				if(check(b[tot].s, a[cnt].s)) {
					b[tot].x = i;
					b[tot].beg = now, now += a[cnt].cst;
					cout << b[tot].beg << "\n";
					break;
				}
			}
		}
		if(op == 3) {
			cin >> (c + 1);
			gets();
		//	cout << "!" << (d + 1) << " " << (b[1].nam + 1) << check(d + 1, b[1].nam + 1) << endl;
			for(int i = 1; i <= tot; i++) {
				if(!check(d, b[i].nam))
					continue;
				x = b[i].x;
				for(int j = 1; j <= a[x].k; j++) {
					if(!check(e , a[x].ss[j]))
						continue;
					cout << b[i].beg + a[x].num * (j - 1) << "\n";
				}
				break;
			}
		}
		if(op == 4) {
			cin >> x;
			for(int i = 1; i <= tot; i++) {
				if(b[i].beg + a[b[i].x].cst <= x)
					continue;
				int qaq = b[i].x;
				x -= b[i].beg;
				for(int j = 1; j <= a[qaq].k; j++) {
					if(x < a[qaq].num) {
						if(x < a[qaq].b[j])
							cout << (b[i].nam + 1) << "." << (a[qaq].ss[j] + 1) << "\n";
						else
							cout << "ERR\n";
						break;
					}
					x -= a[qaq].num;
				}
				break;
			}
		}
	}
	return 0;
}
				
			
