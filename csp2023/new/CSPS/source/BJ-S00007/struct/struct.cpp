#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	ll n;
	cin >> n;
	while(n--){
		ll op;
		cin >> op;
		if(op == 2 || op == 3){
			cout << rand() << endl;
		}else if(op == 4){
			cout << "ERR" << endl;
		}else{
			string a;
			ll cnt;
			cin >> a >> cnt;
			cout << cnt * 8 << ' ' <<8<< endl;
		}
	}
	return 0;
}