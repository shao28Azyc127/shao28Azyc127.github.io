#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pll pair<long long,long long >
#define fir first
#define sec second
const int MX = 1005;

struct Type{
	string name;
	int shift;
	ll sz;
	vector<string > itemType,itemName;
	vector<ll > itemLpos,itemRpos;
	void print(){
		cerr << "struct name = " << name << '\n';
		cerr << "shift = " << shift << '\n';
		cerr << "sz = " << sz << '\n';
		for(int i = 0;i < itemType.size();i++){
			cerr << itemType[i] << ' ' << itemName[i] << '\n';
			cerr << "memory pos : " << itemLpos[i] << ' ' << itemRpos[i] << '\n';
		}
	}
}st[MX];
int id = 0;

int tot = 3;
map<string,int > nameTable;

void init(){
	nameTable["byte"] = 0;
	nameTable["short"] = 1;
	nameTable["int"] = 2;
	nameTable["long"] = 3;
	st[0].name = "byte";
	st[1].name = "short";
	st[2].name = "int";
	st[3].name = "long";
	st[0].shift = 1,st[0].sz = 1;
	st[1].shift = 2,st[1].sz = 2;
	st[2].shift = 4,st[2].sz = 4;
	st[3].shift = 8,st[3].sz = 8;
}

void opt1(){
	string name;int k,maxshift = 0;ll sz = 0;
	cin >> name >> k;
	vector<string > itTypes,itNames;
	for(int i = 1;i <= k;i++){
		string itType,itName;
		cin >> itType >> itName;
		itTypes.push_back(itType);
		itNames.push_back(itName);
		int id = nameTable[itType];
		maxshift = max(maxshift,st[id].shift);
	}
	int cur = ++tot;ll L = 0,lasSz = 0;
	for(int i = 0;i < k;i++){
		string itType = itTypes[i],itName = itNames[i];
		int id = nameTable[itType];
		if(i != 0){
			L += lasSz;
			while(L % st[id].shift != 0)L++;
		}
		st[cur].itemType.push_back(itType);
		st[cur].itemName.push_back(itName);
		st[cur].itemLpos.push_back(L);
		st[cur].itemRpos.push_back(L + st[id].sz - 1);
		lasSz = st[id].sz;
	}
	L += lasSz;
	while(L % maxshift != 0)L++;
	st[cur].shift = maxshift;st[cur].sz = L;
	nameTable[name] = cur;
	st[cur].name = name;
	cout << L << ' ' << maxshift << '\n';
}

struct mem{
	ll L,R;
	string type,name;
	bool operator < (const mem b)const{
		return L < b.L;
	}
};

mem memBox[MX];
int lasMem = 0,memcnt = 0;

void opt2(){
	string type,name;
	cin >> type >> name;
	int id = nameTable[type];
	if(lasMem != 0){
		while(lasMem % st[id].shift != 0)lasMem++;
	}
	cout << lasMem << '\n';
	mem newE;
	newE.L = lasMem;newE.R = lasMem + st[id].sz - 1;
	lasMem = newE.R + 1;
	newE.type = type;newE.name = name;
	memBox[++memcnt] = newE;
}

void opt3(string ele){
	vector<string > div;string tmp = "";
	for(int i = 0;i < ele.size();i++){
		if(ele[i] == '.'){
			div.push_back(tmp);
			tmp = "";
		}
		else tmp += ele[i];
	}
	div.push_back(tmp);
	tmp = "";
	int pos = 0,typeId = 0;
	for(int i = 1;i <= memcnt;i++){
		if(memBox[i].name == div[0]){
			pos = i;
			typeId = nameTable[memBox[i].type];
		}
	}
	//pos = ele pos
	ll dx = memBox[pos].L;
	for(int i = 1;i < div.size();i++){
		for(int j = 0;j < st[typeId].itemType.size();j++)
			if(st[typeId].itemName[j] == div[i]){
				dx += st[typeId].itemLpos[j];
				typeId = nameTable[st[typeId].itemType[j]];
				break;
			}
	}
	cout << dx << '\n';
}

void opt4(){
	ll addr,tmpd;
	cin >> addr;
	tmpd = addr;
	int typeId = 0;bool find = false;
	vector<string > output;
	for(int i = 1;i <= memcnt;i++)
		if(memBox[i].L <= addr && addr <= memBox[i].R){
			typeId = nameTable[memBox[i].type];
			output.push_back(memBox[i].name);
			addr -= memBox[i].L;
			find = true;
		}
	if(!find){
		cout << "ERR\n";
		return;
	}
	bool flag = true;
	for(;;){
		if(typeId < 4)break;
		bool ok = false;
		for(int j = 0;j < st[typeId].itemType.size();j++){
			if(st[typeId].itemLpos[j] <= addr && addr <= st[typeId].itemRpos[j]){
				addr -= st[typeId].itemLpos[j];
				output.push_back(st[typeId].itemName[j]);
				typeId = nameTable[st[typeId].itemType[j]];
				ok = true;
				break;
			}
		}
		if(!ok){
			flag = false;
			break;
		}
	}
	if(!flag)cout << "ERR\n";
	else{
		for(int i = 0;i < output.size();i++){
			if(i != 0)cout << ".";
			cout << output[i];
		}
		cout << '\n';
	}
	
}

signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	init();
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int opt;
		cin >> opt;
		if(opt == 1)opt1();
		if(opt == 2)opt2();
		if(opt == 3){
			string tmp;
			cin >> tmp;
			opt3(tmp);
		}
		if(opt == 4)opt4();
	}
	//for(int i = 4;i <= tot;i++)st[i].print();
	return 0;
}