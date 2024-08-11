#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	ll n;
	cin >> n;
	ll n1 = n;
	ll d1 = 0, d2 = 114514;
	while(n1 != 0){
		if(n1 % 3 == 1){
			d2 = min(d2, d1 + 1);
		}
		if(n1 % 3 == 0) {
			n1 -= n1 / 3;
		} else {
			n1 -= n1 / 3 + 1;
		}
		d1++;
	}
	cout << d1 << " " << d2;
	return 0;
}
