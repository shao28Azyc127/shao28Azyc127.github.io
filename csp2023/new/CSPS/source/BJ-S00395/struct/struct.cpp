#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 110;
typedef pair<int, long long> P;
typedef pair<int, string> Instance;
const string ERR = "ERR";
struct Object {
	long long fit, space;
	int id;
	unordered_map<string, P> sub;
	Object() {
		fit = 0, space = 0, id = 0;
	}
};
vector<Object> pre;
unordered_map<string, int> pre_get;

vector<Instance> space;
vector<long long> stp;
unordered_map<string, int> space_get;
int cnt = 3;
//basic
long long edit(long long &cnt, long long fit) {
	cnt = fit * ((cnt + fit - 1) / fit);
	return cnt;
}
long long get_p(long long cnt, long long fit) {
	cnt = fit * ((cnt + fit - 1) / fit);
	return cnt;
}
void split(string str, vector<string>& args) {
	string cur = "";
	str = str + '.';
	for (char c : str) {
		if (c != '.') {
			cur = cur + c;
		} else {
			args.push_back(cur);
			cur = "";
		}
	}
}
void new_object(Object new_obj, string name) {
	pre.push_back(new_obj);
	pre_get[name] = pre.size() - 1;
}
int q;
int main() {
	ios::sync_with_stdio(false);
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	Object Byte, Short, Integer, Long;
	Byte.fit = 1, Byte.space = 1, Byte.id = 0;
	Short.fit = 2, Short.space = 2, Short.id = 1;
	Integer.fit = 4, Integer.space = 4, Integer.id = 2;
	Long.fit = 8, Long.space = 8, Long.id = 3;
	new_object(Byte, "byte");
	new_object(Short, "short");
	new_object(Integer, "int");
	new_object(Long, "long");
	cin >> q;
	for (int T = 1; T <= q; T++) {
		int op;
		cin >> op;
		if (op == 1) {
			string s;
			int k;
			cin >> s >> k;
			Object new_obj;
			new_obj.id = ++cnt;
			long long cur_p = 0;
			for (int i = 0; i < k; i++) {
				string t, n;
				cin >> t >> n;
				long long fit_cur = pre[pre_get[t]].fit;
				new_obj.fit = max(new_obj.fit, fit_cur);
				new_obj.sub[n] = {pre[pre_get[t]].id, edit(cur_p, fit_cur)};
				cur_p += pre[pre_get[t]].space;
			}
			new_obj.space = edit(cur_p, new_obj.fit);
			cout << new_obj.space << " " << new_obj.fit << endl;
			new_object(new_obj, s);
		} else if (op == 2) {
			Instance ins;
			string s, t;
			cin >> s >> t;
			if (stp.size() == 0) {
				stp.push_back(0);
			} else {
				stp.push_back(get_p(stp[stp.size() - 1] + pre[space[space.size() - 1].first].space, pre[pre_get[s]].fit));
			}
			cout << stp[stp.size() - 1] << endl;
			ins.first = pre_get[s];
			ins.second = t;
			space.push_back(ins);
			space_get[t] = space.size() - 1;
		} else if (op == 3) {
			string s;
			cin >> s;
			vector<string> args;
			split(s, args);
			long long p = stp[space_get[args[0]]];
			long long cur = space[space_get[args[0]]].first;
			for (int i = 1; i < args.size(); i++) {
				P tmp = pre[cur].sub[args[i]];
				p += tmp.second;
				cur = tmp.first;
			}
			cout << p << endl;
		} else {
			long long p;
			long long cur_p = 0; // d(cur_p)
			int cur = 0;
			cin >> p;
		//	cout << p << ": " << endl;
			vector<string> args;
			for (int i = 0; i < space.size(); i++) {
				if (stp[i] <= p && stp[i] + pre[space[i].first].space > p) {
					args.push_back(space[i].second);
					cur = space[i].first;
					cur_p = p - stp[i];
					break;
				}
			}
			if (args.size() == 0) {
				cout << ERR << endl;
				continue;
			}
			bool succ = true;
			while (true) {
				if (0 <= cur && cur < 4) {
					break;
				}
				bool flag = false;
				for (auto c : pre[cur].sub) {
					if (c.second.second <= cur_p && c.second.second + pre[c.second.first].space > cur_p) {
						cur = c.second.first;
						cur_p -= c.second.second;
						flag = true;
						args.push_back(c.first);
						break;/*soli*//*5106296990*/
					}
					
				}
				if (!flag) {
					cout << ERR << endl;
					succ = false;
					break;
				}
			}
			if (succ) {
				for (int i = 0; i < args.size(); i++) {
					cout << args[i];
					if (i + 1 != args.size()) {
						cout << ".";
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}