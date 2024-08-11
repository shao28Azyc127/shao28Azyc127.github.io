//CSP2023 RP++ !!!!
#include <iostream>
#include <map>
#define int long long
using namespace std;
int n = 0;
map <string, int> mp;//struct dui ying bian hao
map <string, int> siz;
map <string, int> len;
map <string, int> nm_dz;
struct zz{
	string nm;
	int id;
};
zz lst[110][110];
int cnt = 0;
string nc[1000010];
int ncnt = 0;
signed main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n --){
		int op = 0;
		cin >> op;
		if(op == 1){
			string nm = "";
			int k = 0;
			cin >> nm;
			cnt ++;
			mp[nm] = cnt;
//			cout << "TS:" << mp[nm] << '\n';
			cin >> k;
			len[nm] = k;
			int maxsiz = 0;
			for(int i = 1; i <= k; i++){
				string bl, snm;
				cin >> bl >> snm;
				if(bl == "byte"){
					lst[cnt][i].id = 1;
					maxsiz = max(maxsiz, 1ll);
				}
				if(bl == "short"){
					lst[cnt][i].id = 2;
					maxsiz = max(maxsiz, 2ll);
				}
				if(bl == "int"){
					lst[cnt][i].id = 4;
					maxsiz = max(maxsiz, 4ll);
				}
				if(bl == "long"){
					lst[cnt][i].id = 8;
					maxsiz = max(maxsiz, 8ll);
				}
				lst[cnt][i].nm = snm;
			}
			siz[nm] = maxsiz;
			cout << k * siz[nm] << " " << siz[nm] << '\n';
			
		}
		if(op == 2){
			string lx, nm;
			cin >> lx >> nm;
			nm_dz[nm] = ncnt;
			int ans = ncnt;
			if(lx == "byte"){
				nc[ncnt] = nm;
//				cout << "TS " << nc[ncnt] << '\n';
				ncnt ++;
			}
			else if(lx == "short"){
				nc[ncnt] = nm;ncnt ++;
				nc[ncnt] = nm;ncnt ++;
			}
			else if(lx == "int"){
				nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;
				nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;
			}
			else if(lx == "long"){
				nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;
				nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;nc[ncnt] = nm;ncnt ++;
			}
			else{
				int g = mp[lx];
				int sz = siz[lx];
				int lenth = len[lx];
				for(int i = 1; i <= lenth; i++){
					nm_dz[nm + '.' +lst[g][i].nm] = ncnt;
					for(int j=  0; j < lst[g][i].id; j++){
						nc[ncnt + j] = nm + '.' +lst[g][i].nm;
					}
					ncnt += sz;
				}
//				cout << lenth << " ";
				}
//			cout << ans << " " << ncnt  << '\n';
			cout << ans << '\n';
		}
		if(op == 3){
			string nm;
			cin >> nm;
			cout << nm_dz[nm] << '\n';
		}
		if(op == 4){
			int addr = 0;
			cin >> addr;
			string nm = nc[addr];
			bool flg = true;
			for(int i = 0; i < nm.size(); i++){
				if(nm[i] == '.'){
					flg = false;
					break;
				}
			}
			if(flg){
				cout << nm << '\n';
			}
			else{
				cout << "ERR\n";
			}
		}
	}
	return 0;
}
//CSP2023 RP++ !!!!