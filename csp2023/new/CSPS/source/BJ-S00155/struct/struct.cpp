# include <iostream>
# include <vector>
using namespace std;

const int N = 105;
int typelen, relen;
long long readdr;
vector <string> Type;
vector <long long> TypeSize;

struct Element {
	long long st, ed;
	string type, name;
} re[N * N];

struct Struct {
	int slen;
	string name;
	Element e[N];
} str[N];

int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	Type.push_back("byte");
	Type.push_back("short");
	Type.push_back("int");
	Type.push_back("long");
	TypeSize.push_back(1);
	TypeSize.push_back(2);
	TypeSize.push_back(4);
	TypeSize.push_back(8);
	int n;
	cin >> n;
	while (n--){
		int op;
		cin >> op;
		switch (op){
			case 1: {
				int k;
				long long dq = 0, addrlen = 0;
				cin >> str[++typelen].name >> k;
				for (int i = 1; i <= k; i++){
					cin >> str[typelen].e[++str[typelen].slen].type >> str[typelen].e[str[typelen].slen].name;
					for (int j = 0; j < Type.size(); j++){
						if (Type[j] == str[typelen].e[str[typelen].slen].type) dq = max(dq, TypeSize[j]);
					}
				}
				for (int i = 1; i <= k; i++){
					str[typelen].e[i].st = addrlen, str[typelen].e[i].ed = addrlen + dq - 1;
					addrlen += dq;
				}
				Type.push_back(str[typelen].name);
				TypeSize.push_back(str[typelen].e[str[typelen].slen].ed - str[typelen].e[1].st + 1);
				cout << TypeSize[TypeSize.size() - 1] << " " << dq << endl;
				break;
			}
			case 2: {
				cin >> re[++relen].type >> re[relen].name;
				for (int i = 0; i < Type.size(); i++){
					if (Type[i] == re[relen].type){
						if (readdr % TypeSize[i]) re[relen].st = readdr + TypeSize[i] - readdr % TypeSize[i];
						else re[relen].st = readdr;
						re[relen].ed = re[relen].st + TypeSize[i] - 1;
						readdr = re[relen].ed + 1;
						break;
					}
				}
				cout << re[relen].st << endl;
				break;
			}
			case 3: {
				bool flag = 1, abt;
				int ele, ret = 0;
				string s, now = "", nowtype;
				cin >> s;
				for (int i = 0; i < s.size(); i++){
					if (s[i] == '.'){
						if (flag){
							for (int j = 1; j <= relen; j++){
								if (re[j].name == now){
									ret = re[j].st;
									flag = 0, ele = j;
									break;
								}
							}
							if (re[ele].type == "byte" || re[ele].type == "short" || re[ele].type == "int" || re[ele].type == "long"){
								cout << ret << endl;
								break;
							}
						}
						else {
							abt = 0;
							nowtype = "";
							for (int j = 1; j <= typelen; j++){
								for (int k = 1; k <= str[j].slen; k++){
									if (str[j].e[k].name == now){
										ret += str[j].e[k].st;
										nowtype = str[j].e[k].type;
										abt = 1;
										break;
									}
								}
								if (abt) break;
							}
						}
						now = "";
					}
					else now += s[i];
				}
				abt = 0, nowtype = "";
				for (int j = 1; j <= typelen; j++){
					for (int k = 1; k <= str[j].slen; k++){
						if (str[j].e[k].name == now){
							ret += str[j].e[k].st;
							nowtype = str[j].e[k].type;
							cout << ret << endl;
							abt = 1;
							break;
						}
					}
					if (abt) break;
				}
				break;
			}
			default: break;
		}
	}
	return 0;
}