#include <bits/stdc++.h>
using namespace std;

vector<string> split(string w) {
	vector<string> res;
	string tmp;
	for (char i: w) {
		if (i == '.') {
			res.push_back(tmp);
			tmp = "";
		} else tmp += i;
	}
	if (tmp.size())
		res.push_back(tmp);
	return res;
}

struct Obj {
	map<string, Obj> attrs;
	int size;
	int fit;

	int query(const vector<string>& path, int begin) {
		
	}
};

struct Struct {
	map<string, string> attrs;
	int size, fit;

	Obj construct() {
		map<string, Obj> obj;
		for (auto i: attrs) {
			obj[i.first] = structs[i.second].construct();
		}
		return Obj({obj, size, fit})
	}
};

int n;
map<string, Struct> structs;
map<string, Obj> objs;

int main(int argc, char const *argv[])
{
	structs["byte"].size = structs["byte"].fit = 1;
	structs["short"].size = structs["short"].fit = 2;
	structs["int"].size = structs["int"].fit = 4;
	structs["long"].size = structs["long"].fit = 8;

	cin >> n;
	while (n--) {
		int op;
		cin >> op;
		if (op == 1) {
			string name;
			int num;
			cin >> name >> num;
			Struct s;
			int fit = 0, size = 0;
			while (num--) {
				string name, type;
				cin >> type >> name;
				s.attrs[name] = type;
				fit = max(fit, fits[type]);
				size += sizes[type];
			}
			structs[name] = s;
			s.fit = fit;
			s.size = size;
		} else if (op == 2) {
			string type, name;
			cin >> type >> name;
			objs[name] = structs["type"].construct();
		} else if (op == 3) {
			string w;
			cin >> w;
			vector<need> = split(w);
		}
	}
	return 0;
}
