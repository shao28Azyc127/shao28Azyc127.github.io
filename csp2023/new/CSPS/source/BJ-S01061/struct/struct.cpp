#include <iostream>
#include <map>
#include <vector>

#define ONLINE

using namespace std;

inline int end_prog()
{
	cout.flush();
	fclose(stdout);
	return 0;
}

static map<string, int> ALIGN_OR_SIZE {
	{ "short", 2 },
	{ "byte", 1 },
	{ "int", 4 },
	{ "long", 8 },
};

int main()
{
#ifdef ONLINE
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
#endif

	int t;
	vector<pair<string, pair<int, int>>> mem;

	cin >> t;

	while (t-- > 0) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			int n;
			string s;

			cin >> s >> n;

			while (n-- > 0)
				cin >> s;
		} else if (cmd == 2) {
			string type, name;
			cin >> type >> name;

			int addr = mem.back().second.second + 1;

			while (addr % ALIGN_OR_SIZE[type] > 0)
				++addr;

			mem.emplace_back(name, make_pair(addr, addr + ALIGN_OR_SIZE[type] - 1));
			cout << addr << '\n';
		} else if (cmd == 3) {
			string name;
			cin >> name;

			for (const auto& elem : mem) {
				if (elem.first == name) {
					cout << elem.second.first << '\n';
					break;
				}
			}
		} else if (cmd == 4) {
			int addr;
			cin >> addr;

			bool found = false;

			for (const auto& elem : mem) {
				if (addr >= elem.second.first && addr <= elem.second.second) {
					cout << elem.first << '\n';
					found = true;
					break;
				}
			}

			if (!found)
				cout << "ERR" << '\n';
		}
	}

	return end_prog();
}