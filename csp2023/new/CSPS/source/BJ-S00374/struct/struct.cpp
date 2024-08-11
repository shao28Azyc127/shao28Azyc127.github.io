#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int cnt = 0, f = 1;
	char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') {
		f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		cnt = (cnt << 1) + (cnt << 3) + (c ^ 48);
		c = getchar();
	}
	return cnt * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x < 10) {
		putchar(x ^ 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 ^ 48);
}
int num = 4;
struct node {
	int num_chengyuan;
	int siz,max_siz;
	int TY_chengyuan[105];
	string name_chengyuan[105];
	int add_chengyuan[105];
}P[155];
map<string, int> mp;
vector <string> vec;

int calc(int now, int nd);
void add(int cp6, int T, string name);
void solve_string(string s);
string add_string();
int get_id_by_name(int T, string name);
int get_id_by_add(int T, int add);
int get_add();
bool get_str(int T, int add);

signed main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	mp["byte"] = 1;
	mp["short"] = 2;
	mp["int"] = 3;
	mp["long"] = 4;
	P[0].num_chengyuan=0;
	P[0].siz=0;
	P[1].siz=P[1].max_siz=1;
	P[2].siz=P[2].max_siz=2;
	P[3].siz=P[3].max_siz=4;
	P[4].siz=P[4].max_siz=8;
	int n;
	cin >> n;
	while (n--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			string s;
			int k;
			num++;
			cin >> s >> k;
			mp[s]=num;
			for (int i = 1; i <= k; i++) {
				string TY, name;
				cin >> TY >> name;
				int T = mp[TY];
				add(num, T, name);
			}
			cout << calc(P[num].siz, P[num].max_siz) << ' ' << P[num].max_siz << '\n';
		}
		else if (opt == 2) {
			string TY, name;
			cin >> TY >> name;
			int T=mp[TY];
			add(0, T, name);
			cout << P[0].add_chengyuan[P[0].num_chengyuan] << '\n';
		}
		else if (opt == 3) {
			string ss;
			cin >> ss;
			solve_string(ss);
			cout << get_add() << '\n';
		}
		else {
			int x;
			cin >> x;
			vec.clear();
			if (get_str(0, x)) cout << add_string() << '\n';
			else cout << "ERR\n";
		}
	}
	return 0;
}

int calc(int now, int nd) {
	while (now % nd) now++;
	return now;
}
void add(int cp6, int T, string name) {
	P[cp6].num_chengyuan++;
	P[cp6].TY_chengyuan[P[cp6].num_chengyuan]=T;
	P[cp6].name_chengyuan[P[cp6].num_chengyuan]=name;
	P[cp6].add_chengyuan[P[cp6].num_chengyuan]=calc(P[cp6].siz, P[T].max_siz);
	P[cp6].siz=calc(P[cp6].add_chengyuan[P[cp6].num_chengyuan]+P[T].siz, P[T].max_siz);
	P[cp6].max_siz=max(P[cp6].max_siz,P[T].max_siz);
}
void solve_string(string s) {
	vec.clear();
	string ss;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			vec.push_back(ss);
			ss="";
		}
		else ss=ss+s[i];
	}
	if (ss != "") vec.push_back(ss);
}
string add_string() {
	string ss=vec[0];
	for (int i=1; i < vec.size(); i++) {
		ss=ss+"."+vec[i];
	}
	return ss;
}
int get_id_by_name(int T, string name) {
	for (int i = 1; i <= P[T].num_chengyuan; i++) {
		if (P[T].name_chengyuan[i] == name) return i;
	}
	return -1;
}
int get_id_by_add(int T, int add) {
	for (int i = P[T].num_chengyuan; i >= 1; i--) {
		if(P[T].add_chengyuan[i]<=add)return i;
	}
	return -1;
}
int get_add() {
	int x = 0, siz = 0;
	for (int i = 0; i < vec.size(); i++) {
		int id = get_id_by_name(x, vec[i]);
		siz+=P[x].add_chengyuan[id];
		x=P[x].TY_chengyuan[id];
	}
	return siz;
}
bool get_str(int T, int add) {
	if (P[T].siz<=add) return false;
	if (T>=1&&T<=4) return true;
	int id = get_id_by_add(T, add);
	vec.push_back(P[T].name_chengyuan[id]);
	return get_str(P[T].TY_chengyuan[id], add - P[T].add_chengyuan[id]);
}