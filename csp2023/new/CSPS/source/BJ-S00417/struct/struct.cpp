#include <bits/stdc++.h>

inline void file () {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
}

using i64 = long long;

struct Type {
	i64 s, a;
	std::vector <std::string> type, name;
	std::vector <i64> sv, av, ov;
	void clear () {
		type.clear(), name.clear();
		sv.clear(), av.clear(), ov.clear();
	}
	void build (int x) {
		s = a = x;
	}
} All, temp;

std::map <std::string, Type> mp;

void Push (Type &T, std::string tp, std::string nm) {
	const Type S = mp[tp];
	const int sz = T.type.size();
	if (!sz) {
		T.s = S.s, T.a = S.a;
		T.type = {tp}, T.name = {nm};
		T.sv = {S.s}, T.av = {S.a}, T.ov = {0LL};
	} else {
		T.a = std::max(T.a, S.a);
		T.type.push_back(tp), T.name.push_back(nm);
		
		i64 o = T.ov.back() + T.sv.back();
		while (o % S.a) { o ++ ; }
		T.ov.push_back(o);
		T.sv.push_back(S.s), T.av.push_back(S.a); 
		
		T.s = T.ov.back() + T.sv.back();
		while (T.s % T.a) { T.s ++ ; }
	}
}

i64 Query (std::string str) {
	i64 ans = 0LL;
	Type cur = All;
	for (int i = 0; i < str.size(); ) {
		std::string nm = "";
		for (; i < str.size() && str[i] != '.'; ++ i) {
			nm += str[i];
		}
		i ++ ;
		
		for (int j = 0; j < cur.type.size(); ++ j) {
			if (cur.name[j] == nm) {
				ans += cur.ov[j];
				cur = mp[cur.type[j]];
				break;
			}
		}
	}
	
	return ans;
}

std::string Query (i64 addr) {
	std::string ans;
	Type cur = All;
	bool flg = 0, neg = 1;
	while (1) {
		if (flg) {
			ans += ".";
		}
		flg = 1;
		
		bool brk = 1;
		for (int i = 0; i < cur.type.size(); ++ i) {
			if (i + 1 == cur.type.size() || cur.ov[i + 1] > addr) {
				ans += cur.name[i];
				addr -= cur.ov[i];
				if (cur.type[i] == "byte") {
					neg = (addr >= 1);
				} else if (cur.type[i] == "short") {
					neg = (addr >= 2);
				} else if (cur.type[i] == "int") {
					neg = (addr >= 4);
				} else if (cur.type[i] == "long") {
					neg = (addr >= 8);
				} else {
					brk = 0;
					cur = mp[cur.type[i]];
				}
				break;
			}
		}
		
		if (brk) {
			break;
		}
	}
	
	return (neg ? "ERR" : ans);
}

int main () {
	
	file();
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	
	temp.build(1), mp["byte"] = temp;
	temp.build(2), mp["short"] = temp;
	temp.build(4), mp["int"] = temp;
	temp.build(8), mp["long"] = temp;
	
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++ i) {
		int op, k;
		std::cin >> op;
//		if (i == 82) {
//			std::cerr << "op = " << op << "\n";
//		}
		if (op == 1) {
			std::string ns;
			std::cin >> ns >> k;
			temp.clear();
			while (k -- ) {
				std::string type, name;
				std::cin >> type >> name;
				Push(temp, type, name);
			}
			mp[ns] = temp;
			std::cout << temp.s << " " << temp.a << "\n";
		} else if (op == 2) {
			std::string type, name;
			std::cin >> type >> name;
			Push(All, type, name);
			std::cout << All.ov.back() << "\n";
		} else if (op == 3) {
			std::string str;
			std::cin >> str;
			std::cout << Query(str) << "\n";
		} else {
			i64 addr;
			std::cin >> addr;
			std::cout << Query(addr) << "\n";
		}
	}
	
	return 0;
}