#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace kamisako{

string s;
int n,cnt;
const int maxn=2e5+10;
int addr[100007],addc=0;
string nam[maxn];
int siz[maxn];
int ct = 0;
int dq[maxn];
int strsz=0;
int mxz=0;
vector<int> stry;
vector<string> strnm;
vector<int> strsz;
map<string,int> mp;
string strn;

void main() {
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	// scanf("%d",&n);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cnt=4;
	siz[1]=1,siz[2]=2,siz[3]=4,siz[4]=8;
	nam[1]="byte",nam[2]="short",nam[3]="int",nam[4]="long";
	dq[1]=1,dq[2]=2,dq[3]=4,dq[4]=8;
	mp["byte"]=1,mp["short"]=2,mp["int"]=3,mp["long"]=4;
	for (int i = 1; i <= n; ++i) {
		int op;scanf("%d",&op);
		switch(op) {
			case 1: {
				string s; int k;
				cin >> s >> k;
				strn=s;
				for (int j = 1; j <= k; ++j) {
					string ty,nm;
					cin >> ty >> nm;
					strnm.push_back(nm);
					stry.push_back(mp[ty]);
					strsz.push_back(siz[mp[ty]]);
					mxz=max(mxz,siz[mp[ty]]);
				}
				strsz=k*mxz;
				// for (int j = 0; j < k; ++j) {
				// 	siz[++cnt]=strsz[j];
				// 	dq[cnt]=mxz;
				// 	nam[cnt]=s+"."+strnm[j];
				// 	mp[nam[cnt]]=cnt;
				// }
				break;
			},
			case 2: {
				string ty,nm;
				cin >> ty >> nm;
				cout << addc<<"\n";
				if (ty == strn) {

				} else {
					
					for (int i = addc; i <= addc+siz[mp[ty]]; ++i) addc[]
					addc+=siz[mp[ty]];
				}

				break;
			},
			case 3: {

				break;
			},
			case 4: {

				break;
			}
		}
	}
}



};


int main() {
	kamisako::main();
	
	return 0;
}