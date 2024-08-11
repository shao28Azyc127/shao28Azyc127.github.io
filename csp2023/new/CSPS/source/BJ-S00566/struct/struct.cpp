#include <bits/stdc++.h>

#define ff(i, a, b) for(int i = (a); i <= (b); i++)

#define ull unsigned long long

using namespace std;

inline int Read () {
    char c = getchar();
    while (c != '-' && (c > '9' || c < '0'))  c = getchar();
    int res = 0;
    int sign = (c == '-')? -1 : 1;
    if (c != '-')
        res += c - '0', res = (res << 3) + (res << 1);
    c = getchar ();
    while (c <= '9' && c >= '0'){
        res += c - '0';
        res = (res << 3) + (res << 1);
        c = getchar ();
    }
    return res * sign / 10;
}

const int maxN = 2e6 + 10;

struct Varb {
	string name;
	string typeo;
	int space;
	int begin;
};

struct Struc {
	string name;
	int begin;
	int space;
	Varb V[105];
};

map <string, Struc> Vars;

map <string, Struc> rVars;

Struc cVars[105];
int VarsTot = 1;

int Pos = 0;

int getpoint (string s){
	for (auto i = 0; i < int(s.size()); i ++)
		if (s[i] == '.')
			return i;
	return -1;
}


int ask (string s,int pos) {
	if (~getpoint(s)){
		return rVars[s].begin;
	}
	return ask(s.substr(getpoint(s)), pos + rVars[s.substr(0, getpoint(s))].begin);
}

struct addr {
	int begin;
	int end;
};

map <string, addr> ss;

signed main () {
    
    freopen("struct1.in", "r", stdin);
    //freopen("struct.out", "w", stdout);
    
    int T;
    cin >>T;
    while (T--){
		int op;
		cin >>op;
		if (op == 1) {
			cout <<"op1:";
			string s;
			int k;
			cin >>s >>k;
			Struc Vt;
			Vt.name = s;
			int pos = 0;
			int maxl = 1;
			for (int i = 1; i <= k; i ++) {
				string t, n;
				cin >>t >>n;
				Vt.V[i].name = n;
				Vt.V[i].typeo = t;
				switch (Vt.V[i].typeo[0]){
					case 'b':	Vt.V[i].space = 1; break;
					case 's':	Vt.V[i].space = 2; break;
					case 'i':	Vt.V[i].space = 4; break;
					case 'l':	Vt.V[i].space = 8; break;
				}
				if (Vt.V[i].space == 0){
					Vt.V[i].space = Vars[Vt.V[i].typeo].space;
				}
				maxl = max(maxl, Vt.V[i].space);
			}
			Vt.V[1].begin = 0;
			for (int i = 2; i <= k; i ++) {
				pos += Vt.V[i - 1].space;
				while (pos % Vt.V[i].space)	pos ++;
				Vt.V[i].begin = pos;
			}
			pos += Vt.V[k - 1].space;
			while (pos % Vt.V[k].space)	pos ++;
			Vt.space = pos;
			Vars[s] = Vt;
			cVars[VarsTot ++] = Vt;
			cout <<Vt.space<<" " <<maxl <<endl;
		}
		if (op == 2) {
			cout <<"op2:";
			string t, n;
			cin >>t >>n;
			Struc vt = Vars[t];
			vt.begin = Pos;
			rVars[n] = vt;
			cout <<Pos <<endl;
			Pos += vt.space;
		}
		if (op == 3) {
			string s;
			cin >>s;
			cout <<ask(s, 0) <<endl;
		}
		if (op == 4) {
			int x;
			cin >>x;
			x += x % 8;
			cout <<x <<endl;
		}
 	}
    
   
    return 0;
}
