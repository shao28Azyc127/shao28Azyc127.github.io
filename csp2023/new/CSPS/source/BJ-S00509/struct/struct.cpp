#include<bits/stdc++.h>
using namespace std;
//File Redirect
#define FILE "struct"
void redirIO() {
	if (FILE != "") {
		freopen(FILE".in", "r", stdin);
		freopen(FILE".out", "w", stdout);
	}
}
//Type Rename
typedef long long LL;
typedef unsigned long long ULL;
//Constants
int N, OPT, K;
string S, t, n;

int __ADDR__;
string type_check;

map<string, int> ram;
map<string, int> ram_costs;
map<string, int> members;
map<string, vector<string> > member_names;
map<string, vector<string> > member_types;

vector<string> vars;
vector<string> types;
vector<int> addrs;
map<string, int> raddrs;
void addVar(string type, string name, int addr, int depth) {/*
	for (int i = 1; i <= depth; i++)
		cout << " ";
	cout << type << " " << name << " " << addr << "\n";*/
	vars.push_back(name);
	types.push_back(type);
	addrs.push_back(addr);
	raddrs[name] = addr;
	if (type == "byte" || type == "short" || type == "int" || type == "long")
		return;
	int num = members[type], v_ram = 0;
	for (int i = 0; i < num; i++) {
		int ram_cost = ram_costs[member_types[type][i]];
		addVar(member_types[type][i], name + "." + member_names[type][i],
		addr + (v_ram + ram_cost - 1) / ram_cost * ram_cost, depth + 1);
		v_ram += ram[member_types[type][i]];
	}
}
//Main
int main() {
	redirIO();
	ios::sync_with_stdio(0);
	ram["byte"] = 1, ram["short"] = 2,
	ram["int"] = 4, ram["long"] = 8;
	ram_costs["byte"] = 1, ram_costs["short"] = 2,
	ram_costs["int"] = 4, ram_costs["long"] = 8;
	type_check = "byte short int long ";
	cin >> N;
	while (N--) {
		cin >> OPT;
		if (OPT == 1) {
			cin >> S >> K;
			int v_pointer = 0, ram_cost = 0;
			members[S] = K, type_check = type_check + S + " ";
			while (K--) {
				cin >> t >> n;
				int v_ram = ram[t], v_ram_cost = ram_costs[t];
				ram_cost = max(ram_cost, v_ram_cost);
				member_types[S].push_back(t);
				member_names[S].push_back(n);
				v_pointer = (v_pointer + v_ram_cost - 1) / v_ram_cost * v_ram_cost + v_ram;
			}
			v_pointer = (v_pointer + ram_cost - 1) / ram_cost * ram_cost;
			ram[S] = v_pointer;
			ram_costs[S] = ram_cost;
			cout << v_pointer << " " << ram_cost << "\n";
		}
		if (OPT == 2) {
			cin >> t >> n;
			if (type_check.find(t) == type_check.npos) {
				cout << "Type not found\n";
				continue;
			}
			((__ADDR__ += ram_costs[t] - 1) /= ram_costs[t]) *= ram_costs[t];
			addVar(t, n, __ADDR__, 0);
			cout << __ADDR__ << "\n";
			__ADDR__ += ram[t];
		}
		if (OPT == 3) {
			cin >> n;
			cout << raddrs[n] << "\n";
		}
		if (OPT == 4) {
			int req;
			cin >> req;
			int left = 0, right = vars.size() - 1;
			while (left < right - 5) {
				int mid = (left + right) / 2;
				if (addrs[mid] <= req)
					left = mid;
				else
					right = mid;
			}
			if (left > right) {
				cout << "ERR\n";
				continue;
			}
			for (; left < right && addrs[left + 1] <= req; left++);
			if (addrs[left] + ram[types[left]] > req)
				cout << vars[left] << "\n";
			else
				cout << "ERR\n";
		}
		if (OPT == 114514) {
			for (auto _ram:ram) {
				cout << _ram.first << " " << _ram.second << "\n";
			}
			cout << "\n";
		}
		if (OPT == 1919810) {
			for (int i = 0; i < (int)vars.size(); i++) {
				for (auto __c:vars[i])
					if (__c == '.')
						cout << " ";
				cout << vars[i]<< " " << types[i] << " " << addrs[i] << "\n";
			}
			cout << "\n";
		}
	}
	return 0;
}
