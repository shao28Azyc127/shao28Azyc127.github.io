#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef pair<int, bool> P;//���ڹ������������bool��ʾ�Ƿ�ȡ��
const int MAXN = 100010;
int c, T;
struct Input {
	short typ, tag;
	int i, j;
};
Input input[MAXN];
int tail[MAXN];
vector<int> head[MAXN];
bool vis[MAXN];
short typ[MAXN];
short tag[MAXN];
//��ʾ��ʽ:һ��vector��ʾ��ʽȫ��Ԫ�أ�һ��bool�����ʾ�Ƿ�ȡ�棬һ��exp_vis�洢�Ѵ���Ԫ
bool exp_vis[MAXN], is_not[MAXN];

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		memset(vis, 0, sizeof vis);
		memset(typ, 0, sizeof typ);
		memset(tag, 0, sizeof tag);
		memset(tail, 0, sizeof tail);
		memset(exp_vis, 0, sizeof exp_vis);
		memset(input, 0, sizeof input);
		memset(is_not, 0, sizeof is_not);
		for (int i = 0; i < MAXN; i++) {
			head[i].clear();
		}
		//input
		for (int i = 1; i <= m; i++) {
			char c;
			cin >> c;
			cin >> input[i].i;
			if ('A' <= c && c <= 'Z') {
				input[i].typ = 0;
				switch(c) {
					case 'T': input[i].tag = 1; break;
					case 'F': input[i].tag = -1; break;
					case 'U': input[i].tag = 0;
				}
			} else {
				cin >> input[i].j;
				input[i].typ = 1;
				input[i].tag = (c == '-');
			}
		}
		//build
		for (int i = m; i >= 1; i--) {
			if (vis[input[i].i]) {
				if (head[input[i].i].size() == 0) {
					continue;
				} else {
					for (int h : head[input[i].i]) {
						if (input[i].typ == 0) {
							typ[h] = 0;
							if (tag) {
								tag[h] = -input[i].tag;
							} else {
								tag[h] = input[i].tag;
							}
						} else {
							tag[h] = input[i].tag ^ tag[i];
							tail[h] = input[i].j;
							typ[h] = 1;
							head[input[i].j].push_back(input[i].i);
						}
					}
					if (input[i].i != input[i].j) {
						head[input[i].i].clear();
					}
				}
			} else {
				vis[input[i].i] = true;
				tag[input[i].i] = input[i].tag;
				if (input[i].typ == 0) {
					typ[input[i].i] = 0;
				} else {
					typ[input[i].i] = 1;
					tail[input[i].i] = input[i].j;
					head[input[i].j].push_back(input[i].i);
				}
			}
		}
		/*
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				cout << "x_" << i << "=";
				if (typ[i]) {
					if (tag[i] == 1) {
						cout << "!";
					}
					cout << "x_" << tail[i] << endl;
				} else {
					switch(tag[i]) {
						case -1: cout << "F" << endl; break;
						case 0: cout << "U" << endl; break;
						case 1: cout << "T" << endl;
					}
				}
			}
		}
		*/
		//union
		//��ʽ��ȫ��Ԫ��ֻ��ΪU���ҽ�����iʹ��x_i=!x_i
		//��ʽ��ȫ��Ԫ�ؿ��Բ�ΪU���ҽ���������iʹ��x_i=!x_i
		//ȫ��ֱ�ӻ��Ӹ�ֵΪU����ֱ�Ӹ�ΪU��û��vis�ľ����Բ�ΪU
		/*
1 1
3 3
- 2 1
- 3 2
+ 1 3
		*/
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				continue;
			}
			if (typ[i] == 0 && tag[i] == 0) {
				exp_vis[i] = true;
				ans++;
			}
			if (!exp_vis[i]) {
				bool all_U = false;
				queue<P> q;
				q.push({i, false});
				int num = 0;
			//	cout << "x_" << i << "=";
				while (q.size()) {
					P p = q.front();
					int u = p.first;
					q.pop();
					exp_vis[u] = true;
					if (tail[u] != 0) {
						int v = tail[u];
						if (exp_vis[v]) {
							if ((p.second ^ tag[u]) != is_not[v]) {
								all_U = true;
							}
						} else {
							is_not[v] = p.second ^ tag[u];
							q.push({v, is_not[v]});
							num++;
						}
						if ((typ[v] == 0) && (tag[v] == 0) && vis[v]) {
							all_U = true;
						//	cout << "+++" << endl;
						}
					//	if (is_not[v]) {
					//		cout << "!";
					//	}
					//	cout << "x_" << v << "=";
					}
					for (int v : head[u]) {
						if (exp_vis[v]) {
							if ((p.second ^ tag[v]) != is_not[v]) {
								all_U = true;
							}
						} else {
							is_not[v] = p.second ^ tag[v];
							q.push({v, is_not[v]});
							num++;
						}
						if (typ[v] == 0 && tag[v] == 0 && vis[v]) {
							all_U = true;
					//		cout << "+++" << endl;
						}
					//	if (is_not[v]) {
					//		cout << "!";
					//	}
					//	cout << "x_" << v << "=";
					}
				}
			//	cout << endl;
				if (all_U) {
					ans += num;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}