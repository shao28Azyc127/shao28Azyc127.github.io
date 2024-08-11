#include<iostream>
#include<cmath>
using namespace std;
int t, m;
struct frac{
	bool fu;
	int up, down;
};
inline int abs(int a){
	return (a < 0 ? -a : a);
}
inline int gcd(int a, int b){
	a = abs(a);
	b = abs(b);
	if(a && b) while((a %= b) && (b %= a));
	return a | b;
}
inline int lcm(int a, int b){
	int g = gcd(a, b);
	if(g == 0){
		return 0;
	}else{
		return a * b / g;
	}
}
inline frac ch(frac a){
	bool b = (a.up < 0) ^ (a.down < 0);
	a.up = abs(a.up);
	a.down = abs(a.down);
	int g = gcd(a.up, a.down);
	a.up /= g;
	a.down /= g;
	a.fu ^= b;
	if(a.up == 0){
		a.down = 1;
		a.fu = 0;
	}
	return a;
}
inline frac max(frac a, frac b){
	a = ch(a);
	b = ch(b);
	int g = gcd(a.down, b.down);
	int x = b.down / g;
	int y = a.down / g;
	return ((a.up * x * (a.fu == 1 ? -1 : 1) >= b.up * y * (b.fu == 1 ? -1 : 1)) ? a : b);
}
int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> t >> m;
	for(int i = 1; i <= t; i++){
		int a, b, c;
		cin >> a >> b >> c;
		int san = b * b - 4 * a * c;
		if(san < 0){
			cout << "NO" << endl;
			continue;
		}
		if(san != 0){
			int x = 1, y = san;
			for(int i = 2; i * i <= y; i++){
				while(y % i == 0 && y / i % i == 0){
					x *= i;
					y /= i * i;
				}
			}
			if(y == 1){
				frac f = max(ch((frac){false, x - b, a * 2}), ch((frac){false, -x - b, a * 2}));
				if(f.up){
					if(f.fu){
						cout << '-';
					}
					if(f.down == 1){
						cout << f.up << endl;
					}else{
						cout << f.up << '/' << f.down << endl;
					}
				}else{
					cout << 0 << endl;
				}
			}else{
				frac f = ch((frac){false, -b, a * 2});
				frac f2 = ch((frac){false, x, a * 2});
				if(f.up){
					if(f.fu){
						cout << '-';
					}
					if(f.down == 1){
						cout << f.up;
					}else{
						cout << f.up << '/' << f.down;
					}
					cout << '+';
				}
				if(f2.up != 1){
					cout << f2.up << '*';
				}
				cout << "sqrt(" << y << ')';
				if(f2.down != 1){
					cout << '/' << f2.down;
				}
				cout << endl;
			}
		}else{
			frac f = ch((frac){false, -b, a * 2});
			if(f.fu){
				cout << '-';
			}
			if(f.down == 1){
				cout << f.up << endl;
			}else{
				cout << f.up << '/' << f.down << endl;
			}
		}
	}
}
/*
(      -b +_ sqrt(b ^ 2 -  4ac)  )  /  2a
*/