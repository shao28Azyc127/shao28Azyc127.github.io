#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, idx, len;
string name, nam;
struct ALL{
	string m[110], typ[110];
	int siz, pl, bas;
}all;
struct NOW{
	int pl, siz;
	string typ;
}a[110];
string na[110];
unordered_map<string, int> id;

int finde(char c){
	for(int i = 0; i < len; ++i)
		if(name[i] == c)
			return i + 1;
	return -1;
}

int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1, op, sys, q, res1, o; i <= n; ++i){
		scanf("%d", &op);
		if(op == 1){
			cin >> name;
			scanf("%d", &all.siz);
			res1 = 0;
			for(int j = 1; j <= all.siz; ++j){
				cin >> name >> nam;
				all.typ[j] = name, all.m[j] = nam;
				if(name == "byte") res1 = max(res1, 1);
				else if(name == "short") res1 = max(res1, 2);
				else if(name == "int") res1 = max(res1, 4);
				else if(name == "long") res1 = 8;
			}
			all.bas = res1, all.pl = res1 * all.siz;
			printf("%d %d\n", all.pl, all.bas);
		}else if(op == 2){
			cin >> name >> nam;
			a[++idx].typ = name;
			if(name == "byte") a[idx].siz = 1;
			else if(name == "short") a[idx].siz = 2;
			else if(name == "int") a[idx].siz = 4;
			else if(name == "long") a[idx].siz = 8;
			else a[idx].siz = all.pl;
			na[idx] = nam;
			 a[idx].pl = sys;
			printf("%d\n", sys);
			sys += a[idx].siz;
			id[name] = idx;
		}else if(op == 3){
			cin >> name;
			len = name.size();
			if(!finde('.')){
				printf("%d\n", a[id[name]].pl);
				continue;
			}
			nam = "";
			for(int i = 0; i < finde('.') - 1; ++i) nam += name[i];
			res1 = a[id[nam]].pl;
			nam = "";
			for(int i = finde('.'); i < len; ++i) nam += name[i];
			for(int i = 1; i <= all.siz; ++i)
				if(all.m[i] == nam) break;
				else res1 += all.bas;
			printf("%d\n", res1);
		}else{
			scanf("%d", &q);
			for(o = 1; o <= idx; ++o)
				if(a[o].pl + a[o].siz > q)
					break;
			cout << na[o];
			if((a[o].typ == "byte" || a[o].typ == "int" || a[o].typ == "short" || a[o].typ == "long")) continue;
			else{
				printf(".");
				cout << all.m[(q - a[o].pl) / all.bas + 1] << endl;
			}
		}
	}
	
	return 0;
}
