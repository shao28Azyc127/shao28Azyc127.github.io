#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef long double ld;
using namespace std;
ll t, m;
ll a, b, c, d, e;
ll p, q;
bool flag;

void printX(ld x){
	p = -114, q = -514;
	for(ll i = 1; i <= m; ++i){
		ll j = i / x;
		if(i * 1.0 / j != x){
			continue;
		}
		ll ii = i;
		ii /= __gcd(i, j);
		j /= __gcd(i, j);
		p = ii, q = j;
		break;
	}
	if(p * 1.0 / q != x || p == -114 || q == -514){
		flag = true;
		return ;
	}
	if(q == 1){
		cout << p;
	}else{
		if(q <= 0){
			cout << '-' << p << '/' << -q << endl;
		}else{
			cout << p << '/' << q << endl;
		}
	}
	return ;
}

bool checkQ2(ld x){
	d = -1, e = -1;
	for(ll i = 1; i <= m; ++i){
		ll j = i / x;
		if(i * 1.0 / j != x){
			continue;
		}
		ll ii = i;
		ii /= __gcd(i, j);
		j /= __gcd(i, j);
		d = ii, e = j;
		break;
	}
	if(d * 1.0 / e != x || d == -1 || e == -1){
		return false;
	}else{
		return true;
	}
}

ll solveR(ll r){
	ll chu = sqrt(r);
	while(chu * chu == r){
		r = chu;
		chu = sqrt(r);
	}
	return r;
}

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	while(t--){
		cin >> a >> b >> c;
		ll delta = b * b - 4 * a * c;
		if(delta < 0){
			cout << "NO" << endl;
			continue;
		}
		ld x = (-b + sqrt(delta)) / (2 * a);
		flag = false;
		printX(x);
		if(!flag){ // you li shu
			cout << endl;
			continue;
		}
		// wu li shu
		ld q1 = -b / (2 * a), q2 = 1.0 / (2 * a);
		ld r = solveR(delta);
		cout << r << " <-r" << endl;
		ld q3 = int(1.0 / q2);
		if(q1 != 0){
			printX(q1);
			cout << "+";
		}else if(q2 == 1){
			cout << "sqrt(" << r << ")";
		}else if(q2 == 1 / q3){
			cout << "sqrt(" << r << ")/" << q3;
		}else if(checkQ2(q2)){
			cout << d << "*" << "sqrt(" << r << ")/" << e;
		}
		cout << endl;
	}
	return 0;
}
