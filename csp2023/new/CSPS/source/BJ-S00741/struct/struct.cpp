//各个结构体间成一棵树（基本元素，结构体）
#include <iostream>
using namespace std;
const int maxn = 1e3;

int n,cnt = 0;
string a,b;
string neicun[maxn * 8 + 5];

int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin >> n;
	while(n--){
		int op;
		cin >> op;
		if(op == 2){
			cin >> a >> b;
			int tmp = cnt;
			cout << cnt << endl;
			if(a == "byte") for(;cnt < tmp + 1; cnt++) neicun[cnt] = b;
			if(a == "short") for(;cnt < tmp + 2; cnt++) neicun[cnt] = b;
			if(a == "int") for(;cnt < tmp + 4; cnt++) neicun[cnt] = b;
			if(a == "long") for(;cnt < tmp + 1; cnt++) neicun[cnt] = b;
		}
		if(op == 3){
			cin >> a;
			for(int i = 1;i <= cnt; i++) if(neicun[i] == a){
				cout << i << endl;
				break;
			}
		}
		if(op == 4){
			int add;
			cin >> add;
			if(neicun[add] != "")cout << neicun[add] << endl;
			else cout << "ERR" << endl;
		}
	}
	
	
	return 0;
}
//先搞特殊性质A