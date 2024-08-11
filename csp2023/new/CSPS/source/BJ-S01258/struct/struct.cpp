/*flower*/
#include <bits/stdc++.h>
using i64 = long long;
std::map<std::string, int> id;
struct node {
	i64 max, size;
	std::vector<std::string> name;
	std::vector<std::string> type;
	std::vector<i64> pos;
	node(i64 max, i64 size, std::vector<std::string> name, std::vector<std::string> type, std::vector<i64> pos) :
		max(max), size(size), name(name), type(type), pos(pos) {}
};
inline i64 ceil(i64 k, i64 b) {
	return (k + b - 1) / b * b;
}
int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int n;
	std::vector<node> vec;
	vec.emplace_back(node(1, 1, {}, {}, {}));
	vec.emplace_back(node(2, 2, {}, {}, {}));
	vec.emplace_back(node(4, 4, {}, {}, {}));
	vec.emplace_back(node(8, 8, {}, {}, {}));
	id["byte"] = 0;
	id["short"] = 1;
	id["int"] = 2;
	id["long"] = 3;
	vec.emplace_back(node(-1, -1, {}, {}, {}));
	std::cin >> n;	
	for(int i = 0; i < n; i ++) {
		int o;
		std::cin >> o;
		if(o == 1) {
			int k;
			std::string str;
			std::cin >> str >> k;
			id[str] = vec.size();
			std::vector<std::string> name(k), type(k);
			i64 max = 0, size = 0;
			std::vector<i64> pos(k);
			for(int i = 0; i < k; i ++) {
				std::cin >> type[i] >> name[i];
				int ord = id[type[i]];
				max = std::max(vec[ord].max, max);
				size = ceil(size, vec[ord].max);
				pos[i] = size;
				size += vec[ord].size;
			}
			size = ceil(size, max);
			vec.emplace_back(max, size, name, type, pos);
			std::cout << size << ' ' << max << '\n';
		} else if(o == 2) {
			std::string type, name;
			std::cin >> type >> name;
			auto &now = vec[4];
			if(now.pos.empty()) {
				now.pos.emplace_back(0);
			} else {
				int last = id[now.type.back()], ord = id[type];
				now.pos.emplace_back(ceil(now.pos.back() + vec[last].size, vec[ord].max));
			}
			now.type.emplace_back(type);
			now.name.emplace_back(name);
			std::cout << now.pos.back() << '\n';
		} else if(o == 3) {
			std::string str;
			std::cin >> str;
			str += '.';
			std::vector<std::string> path;
			std::string cur;
			for(int i = 0; i < str.size(); i ++) {
				if(str[i] == '.') {
					path.emplace_back(cur);
					cur.clear();
				} else {
					cur += str[i];
				}
			}
			int u = 4;
			i64 ans = 0;
			for(auto name : path) {
				for(int i = 0; i < vec[u].name.size(); i ++) {
					if(vec[u].name[i] == name) {
						ans += vec[u].pos[i];
						u = id[vec[u].type[i]];
						break;
					}
				}
			}
			std::cout << ans << '\n';
		} else if(o == 4) {
			i64 pos;
			std::cin >> pos;
			int u = 4;
			std::string output;
			while(u >= 4) {
				int ok = 0;
				for(int i = 0; i < vec[u].name.size(); i ++) {
					if(pos >= vec[u].pos[i] && pos < vec[u].pos[i] + vec[id[vec[u].type[i]]].size) {
						output += vec[u].name[i];
						output += '.';
						pos -= vec[u].pos[i];
						u = id[vec[u].type[i]];
						ok = 1;
						break;
					}
				}
				if(!ok) {
					std::cout << "ERR\n";
					u = -1;
				}
			}
			if(u >= 0) {
				output.pop_back();
				std::cout << output << '\n';
			}
		}
	}
	return 0;
}