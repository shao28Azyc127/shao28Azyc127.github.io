/*
一个字符串是可消除的，当且仅当它由多个可消除字符串组成或它的中间部分可消除且两边合在一起可消除
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt;
queue<pair<int, int>> q;
set<pair<int, int>> res;
map<int, vector<int>> eq_begin, eq_end;

int main(int argc, char const *argv[])
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			q.push(make_pair(i, i+1));
			res.insert(make_pair(i, i+1));
			eq_begin[i].push_back(i+1);
			eq_end[i+1].push_back(i);
		}
	}
	while (!q.empty()) {
		auto cur = q.front();
		int begin = cur.first - 1, end = cur.second + 1;
		// printf("%d %d\n", begin + 1, end - 1);
		q.pop();
		if (begin + 1 >= 0 && eq_begin.count(end)) {
			/*cout << "Hello!" << end << endl;
			for (int i: eq_begin[end]) cout << i << " ";
			cout << endl;*/
			for (int i: eq_begin[end]) if (!res.count(make_pair(begin + 1, i))) {
				res.insert(make_pair(begin + 1, i));
				q.push(make_pair(begin + 1, i));
				eq_begin[begin+1].push_back(i);
				eq_end[i].push_back(begin + 1);
			}
		}
		if (end - 1 < n && eq_end.count(begin)) {
			/*cout << "Hello!" << begin << endl;
			for (int i: eq_end[begin]) cout << i << " ";
			cout << endl;*/
			for (int i: eq_end[begin]) if (!res.count(make_pair(i, end - 1))) {
				res.insert(make_pair(i, end - 1));
				q.push(make_pair(i, end - 1));
				eq_begin[i].push_back(end - 1);
				eq_end[end-1].push_back(i);
			}
		}
		while (begin >= 0 && end < n) {
			if (s[begin] == s[end] && !res.count(make_pair(begin, end))) {
				q.push(make_pair(begin, end));
				res.insert(make_pair(begin, end));
				eq_begin[begin].push_back(end);
				eq_end[end].push_back(begin);
				begin--;
				end++;
			} else break;
		}
	}
	cout << res.size() << endl;
	return 0;
}
