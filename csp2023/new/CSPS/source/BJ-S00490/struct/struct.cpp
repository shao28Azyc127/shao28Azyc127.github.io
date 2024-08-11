#include<bits/stdc++.h>
using namespace std;
map<string, int> ma;
int n, m, max1 = 0, cnt = 0, cnt1 = 1, cnt2 = 0, cnt3 = 0, dz, x;
struct node1{
	int big, dq;
	string name, sn, type;
} a[100010];
struct node2{
	int big, dq, nc;
	string name;
} b[100010];
int bigger(string s){
	for (auto it = ma.begin(); it != ma.end(); it++){
		if (!strcmp(s.c_str(), (it -> first).c_str())) return it -> second;
	}
	return 0;
}
void dfs(node2 *n, string type){
	for (int i = 1; i <= cnt; i++){
		if (a[i].sn == type){
			if (strcmp(a[i].type.c_str(), "byte") && strcmp(a[i].type.c_str(), "short") && strcmp(a[i].type.c_str(), "int") && strcmp(a[i].type.c_str(), "long")){
				dfs(&(b[cnt2]), a[i].type);
				continue;
			}
			n -> big = a[i].big;
			n -> dq = a[i].dq;
			n -> name = a[i].sn + "." + a[i].name;
			n -> nc = cnt3;
			cnt3 += n -> dq;
			cnt2++;
		}
	}
}
void dfs2(string type){
	for (int i = 1; i <= cnt; i++){
		if (a[i].sn == type){
			if (strcmp(a[i].type.c_str(), "byte") && strcmp(a[i].type.c_str(), "short") && strcmp(a[i].type.c_str(), "int") && strcmp(a[i].type.c_str(), "long")){
				dfs2(a[i].type);
				continue;
			}
			a[cnt1].big = bigger(a[i].type);
			a[cnt1].type = a[i].type;
			a[cnt1].dq = bigger(type);
			a[cnt1].sn = type;
			max1 = max(max1, bigger(type));
			cnt1++;
		}
	}
}
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ma["byte"] = 1;
	ma["short"] = 2;
	ma["int"] = 4;
	ma["long"] = 8;
	string name, type;
	cin >> n;
	while (n--){
		cin >> x;
		if (x == 1){
			cnt++;
			cin >> name >> m;
			max1 = 0;
			int ccnt = cnt1;
			for (int j = 1; j <= m; j++){
				cnt1++;
				cin >> type >> a[cnt1+j].name;
				if (strcmp(type.c_str(), "byte") && strcmp(type.c_str(), "short") && strcmp(type.c_str(), "int") && strcmp(type.c_str(), "long")){
					dfs2(type);
					continue;
				}
				a[cnt1].big = bigger(type);
				a[cnt1].type = type;
				max1 = max(max1, bigger(type));
			}
			cnt1 = ccnt;
			for (int j = 1; j <= m; j++){
				cnt1++;
				if (strcmp(a[cnt1].type.c_str(), "byte") && strcmp(a[cnt1].type.c_str(), "short") && strcmp(a[cnt1].type.c_str(), "int") && strcmp(a[cnt1].type.c_str(), "long")){
					continue;
				}
				a[cnt1].dq = max1;
				a[cnt1].sn = name;
			}
			cnt1 += m;
			cout << m * max1 << ' ' << max1;
			ma[name] = m * max1;
		}
		if (x == 2){
			cin >> type >> name;
			cout << cnt2;
			if (!strcmp(type.c_str(), "byte") || !strcmp(type.c_str(), "short") || !strcmp(type.c_str(), "int") || !strcmp(type.c_str(), "long")){
				b[cnt2].big = bigger(type);
				b[cnt2].name = name;
				b[cnt2].dq = b[cnt2].big;
				b[cnt2].nc = cnt3;
				cnt3 += bigger(type);
				cnt2++;
			}
			else {
				dfs(&(b[cnt2]), type);
			}
		}
		if (x == 3){
			cin >> name;
			for (int i = 0; i < cnt2; i++){
				if (b[i].name == name) cout << b[i].nc;
			}
		}
		if (x == 4){
			cin >> dz;
			for (int i = 0; i < cnt2; i++){
				if (b[i].nc + b[i].dq - 1 >= dz){
					if (b[i].nc + b[i].big - 1 >= dz) cout << b[i].name;
					else cout << "ERR";
				}
			}
		}
		cout << endl;
	}
	return 0;
}