#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n, op, K, v, _size[110], dq[110], nn, last, current, _sum, index;
string s, t, name, answer;
map<string, int> id, id_name[110];
vector<int> g[110], start[110];
vector<string> nameg[110];
inline int ceil_div(int a, int b) {
	if (a % b == 0) {
		return a / b;
	} else {
		return a / b + 1;
	}
}
signed main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	scanf("%lld", &n);
	id["byte"] = ++ nn;
	_size[nn] = dq[nn] = 1;
	id["short"] = ++ nn;
	_size[nn] = dq[nn] = 2;
	id["int"] = ++ nn;
	_size[nn] = dq[nn] = 4;
	id["long"] = ++ nn;
	_size[nn] = dq[nn] = 8;
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &op);
		if (op == 1) {
			cin >> s;
			scanf("%lld", &K);
			id[s] = ++ nn;
			for (int i = 1; i <= K; i ++) {
				cin >> t >> name;
				id_name[nn][name] = g[nn].size();
				g[nn].push_back(id[t]);
				dq[nn] = max(dq[nn], dq[id[t]]);
				start[nn].push_back(ceil_div(_size[nn], dq[id[t]]) * dq[id[t]]);
				nameg[nn].push_back(name);
				_size[nn] = start[nn][start[nn].size() - 1] + _size[id[t]];
			}
			_size[nn] = ceil_div(_size[nn], dq[nn]) * dq[nn];
			printf("%lld %lld\n", _size[nn], dq[nn]);
		} else if (op == 2) {
			cin >> t >> name;
			id_name[0][name] = g[0].size();
			g[0].push_back(id[t]);
			dq[0] = max(dq[0], dq[id[t]]);
			start[0].push_back(ceil_div(_size[0], dq[id[t]]) * dq[id[t]]);
			nameg[0].push_back(name);
			_size[0] = start[0][start[0].size() - 1] + _size[id[t]];
			printf("%lld\n", start[0][start[0].size() - 1]);
		} else if (op == 3) {
			cin >> s;
			s += '.';
			last = current = _sum = 0;
			for (int i = 0; i < s.size(); i ++) {
				if (s[i] == '.') {
					name = s.substr(last, i - last);
					_sum += start[current][id_name[current][name]];
					current = g[current][id_name[current][name]];
					last = i + 1;
				}
			}
			printf("%lld\n", _sum);
		} else {
			scanf("%lld", &v);
			current = _sum = 0;
			answer = "";
			while (! start[current].empty()) {
				index = upper_bound(start[current].begin(), start[current].end(), v) - start[current].begin() - 1;
				v -= start[current][index];
				answer += nameg[current][index];
				answer += '.';
				current = g[current][index];
			}
			if (v < _size[current]) {
				answer.pop_back();
				printf("%s\n", answer.c_str());
			} else {
				printf("ERR\n");
			}
		}
	}
	return 0;
}
