#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
ll a, b, c;

ll Tiqu(ll dt, ll &r){
	for(ll i = 2; i * i <= dt; ++i){
		while(dt % (i * i) == 0){
			dt /= (i * i);
			r *= i;
		}
	}
	return dt;
}

void Huajian(ll &q1, ll &q2){
	ll op = 0;
	if(q1 < 0 && q2 < 0){
		q1 = -q1; q2 = -q2;
	}else if(q2 < 0){
		q2 = -q2;
		op = 1;
	}else if(q1 < 0){
		q1 = -q1;
		op = 1;
	}
	for(ll i = 2; i <= min(q1, q2); ++i){
		while(q1 % i == 0 && q2 % i == 0){
			q1 /= i;
			q2 /= i;
		}
	}
	if(op == 1){
		q1 = -q1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int T, M;
	cin >> T >> M;
	while(T--){
		cin >> a >> b >> c;
		if(b * b - ll(4) * a * c < 0){
			cout << "NO" << endl;
			continue;
		}
		ll dt, r;
		if(a > 0){
			dt = b * b - ll(4) * a * c; r = 1;
		}else{
			dt = b * b - ll(4) * a * c; r = -1;
		}
		dt = Tiqu(dt, r);
		if(dt == 1 || dt == 0){
			ll q2, q1;
			if(dt == 1){
				q2 = ll(2) * a; q1 = -b + r;
			}else{
				q2 = ll(2) * a; q1 = -b;
			}
			if(q1 % q2 == 0){
				cout << q1 / q2 << endl;
			}else{
				Huajian(q1, q2);
				cout << q1 << "/" << q2 << endl;
			}
			continue;
		}else{
			ll q2 = ll(2) * a, q1 = -b;
			if(q1 == 0){
			}else if(q1 % q2 == 0){
				cout << q1 / q2 << "+";
			}else{
				Huajian(q1, q2);
				cout << q1 << "/" << q2 << "+";
			}
			q1 = r; q2 = ll(2) * a;
			if(q1 % q2 == 0){
				if(q1 / q2 == 1){
					cout << "sqrt(" << dt << ")" << endl;
				}else{
					cout << q1 / q2 << "*sqrt(" << dt << ")" << endl;
				}
			}else{
				Huajian(q1, q2);
				if(q1 == 1){
					cout << "sqrt(" << dt << ")/" << q2 << endl;
				}else if(q1 == -1){
					cout << "sqrt(" << dt << ")/" << -q2 << endl;
				}else{
					cout << q1 << "*sqrt(" << dt << ")/" << q2 << endl;
				}
			}
		}
	}
	return 0;
}