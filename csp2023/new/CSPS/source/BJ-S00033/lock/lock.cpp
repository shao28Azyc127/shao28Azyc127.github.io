#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull get_hash(vector<int> numvec) {
	int res = 0;
	for (int i: numvec) {
        res *= 10;
        res += i;
	}
	return res;
}

void rotate(int& from) {
	from += 1;
	from %= 10;
}

set<ull> rotate(vector<int> state) {
	vector<int> ans;
	set<ull> res;
	// 转一个
	for (int i = 0; i < 5; i++) {
		ans = state;
		for (int j = 0; j < 9; j++) {
			rotate(ans[i]);
			res.insert(get_hash(ans));
		}
	}
	// 转两个
	for (int i = 0; i < 4; i++) {
		ans = state;
		for (int j = 0; j < 9; j++) {
			rotate(ans[i]);
			rotate(ans[i + 1]);
			res.insert(get_hash(ans));
		}
	}
	return res;
}

const int MAXN = 10;

int n;
vector<int> states[MAXN];

int main(int argc, char const *argv[])
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int tmp;
            cin >> tmp;
            states[i].push_back(tmp);
        }
	}
	set<ull> _res(rotate(states[0]));
	vector<ull> res(_res.begin(), _res.end());
	for (int i = 1; i < n; i++) {
        set<ull> tmp = rotate(states[i]);
        vector<ull> n;
      	// res.begin() = set_union(res.begin(), res.end(), tmp.begin(), tmp.end(), n.begin());
      	for (ull i: res) {
      		if (tmp.count(i)) {
      			n.push_back(i);
      		}
      	}
      	res = n;
	}
	/*for (ull i: res) {
		cout << i << endl;
	}*/
	cout << res.size() << endl;
	return 0;
}
