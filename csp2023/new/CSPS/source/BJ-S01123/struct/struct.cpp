#include<bits/stdc++.h>
using namespace std;

constexpr int maxn = 117;

namespace structs
{
	map<string, int> str2id;
	string id2str[maxn];
	struct addItem
	{
		int begAdd, endAdd;
		int typId;
		string varName;
	};
	vector<addItem> typeContains[maxn];
	int typeAllAdd[maxn];
	int formTo[maxn];

	int allIds = 0;
}

namespace vars
{
	int allIds = 0;
	map<pair<int, int>, int> add;
	map<string, int> str2id;
	string id2str[maxn];
	int id2typ[maxn];
	pair<int, int> varAdd[maxn];

	int nowAddBeg = 0;
}

inline void prepare()
{
	structs::str2id["byte"] = ++structs::allIds;
	structs::id2str[structs::allIds] = "byte";
	structs::typeAllAdd[structs::allIds] = structs::formTo[structs::allIds] = 1;

	structs::str2id["short"] = ++structs::allIds;
	structs::id2str[structs::allIds] = "short";
	structs::typeAllAdd[structs::allIds] = structs::formTo[structs::allIds] = 2;

	structs::str2id["int"] = ++structs::allIds;
	structs::id2str[structs::allIds] = "int";
	structs::typeAllAdd[structs::allIds] = structs::formTo[structs::allIds] = 4;

	structs::str2id["long"] = ++structs::allIds;
	structs::id2str[structs::allIds] = "long";
	structs::typeAllAdd[structs::allIds] = structs::formTo[structs::allIds] = 8;
}

inline void createStruct()
{
	// ´´½¨struct
	int k;
	string structName;
	cin >> structName >> k;
	structs::str2id[structName] = ++structs::allIds;
	structs::id2str[structs::allIds] = structName;
	for(int i=0; i<k; ++i)
	{
		structs::addItem thi;
		string varTyp;
		cin >> varTyp >> thi.varName;
		thi.typId = structs::str2id[varTyp];
		structs::formTo[structs::allIds] = max(
			structs::formTo[structs::allIds],
			structs::formTo[thi.typId]);
		structs::typeContains[structs::allIds].push_back(thi);
	}
	int nowAddBeg = 0;
	for(int i=0; i<k; ++i)
	{
		int formTo = structs::formTo[structs::typeContains[structs::allIds][i].typId];
		auto now = structs::typeContains[structs::allIds][i];
		if(nowAddBeg % formTo == 0)
		{
			;
		}
		else
		{
			nowAddBeg = (formTo * (nowAddBeg / formTo + 1));
		}
		now.begAdd = nowAddBeg;
		now.endAdd = nowAddBeg + formTo - 1;
		nowAddBeg += formTo;
	}
	structs::typeAllAdd[structs::str2id[structName]] = nowAddBeg;
	cout << nowAddBeg << ' ' << structs::formTo[structs::allIds] << endl;
}

inline void defineVar()
{
	string typ, varName;
	cin >> typ >> varName;
	vars::str2id[typ] = ++vars::allIds;
	vars::id2str[vars::allIds] = varName;
	vars::id2typ[vars::allIds] = structs::str2id[typ];
	register int form = structs::formTo[vars::id2typ[vars::allIds]];
	if(vars::nowAddBeg % form == 0)
	{
		vars::varAdd[vars::str2id[varName]] = {vars::nowAddBeg, vars::nowAddBeg + structs::typeAllAdd[structs::str2id[typ]]-1};
		vars::nowAddBeg = vars::nowAddBeg + structs::typeAllAdd[structs::str2id[typ]];
	}
	else
	{
		vars::nowAddBeg = (form * (vars::nowAddBeg / form + 1));
		vars::varAdd[vars::str2id[varName]] = {vars::nowAddBeg, vars::nowAddBeg + structs::typeAllAdd[structs::str2id[typ]]-1};
		vars::nowAddBeg = vars::nowAddBeg + structs::typeAllAdd[structs::str2id[typ]];
	}
	vars::add[vars::varAdd[vars::str2id[varName]]] = vars::str2id[varName];
	cout << vars::varAdd[vars::str2id[varName]].first << endl;
}

inline vector<string> splitStr(string str)
{
	vector<string> res;
	string nowStr;
	for(int i=0; i<str.size(); ++i)
	{
		if(str[i] == '.')
		{
			res.push_back(nowStr);
			nowStr = "";
		}
		else nowStr += str[i];
	}
	res.push_back(nowStr);
	return res;
}

inline void findBegAdd()
{
	string all;
	cin >> all;
	auto tmp = splitStr(all);
	if(tmp.size() == 1)
	{
		cout << vars::varAdd[tmp[0]].first << endl;
	}
	else
	{
		int baseAdd = vars::varAdd[tmp[0]].first;
		for(int i=1; i<=tmp.size(); ++i)
		{
			
		}
	}
}

inline void addFindVarName()
{

}

signed main()
{
	freopen("struct.in" ,"r", stdin); freopen("struct.out", "w" , stdout);
	
	int n;
	cin >> n;
	while(n--)
	{
		int op;
		cin >> op;
		switch(op)
		{
			case 1:
				createStruct();
				break;
			case 2:
				defineVar();
				break;
			case 3:
				findBegAdd();
				break;
			case 4:
				addFindVarName();
				break;
		}
	};
	return 0;
}
