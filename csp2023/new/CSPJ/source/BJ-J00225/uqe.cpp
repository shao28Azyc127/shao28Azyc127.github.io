# include <iostream>
# include <cmath>
using namespace std;

int gcd(int a, int b){
	if (!b) return a;
	return gcd(b, a % b);
}

void PrintV(int a, int b){ // a: fen zi b: fen mu
	if (!(a % b)) cout << a / b;
	else {
		int GCD = gcd(a, b);
		if (a / GCD < 0){
			if (b / GCD < 0) a = -a, b = -b;
		}
		else {
			if (b / GCD < 0) a = -a, b = -b;
		}
		cout << a / GCD << "/" << b / GCD;
	}
}

int main(){
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, m;
	cin >> t >> m;
	while (t--){
		int a, b, c, delta, mu;
		cin >> a >> b >> c;
		if (b == 0 && c == 0){
			cout << 0 << endl;
			continue;
		}
		if (a < 0) a = -a, b = -b, c = -c;
		mu = a * 2;
		delta = b * b - 4 * a * c;
		if (delta < 0){
			cout << "NO" << endl;
			continue;
		}
		if ((int)sqrt(delta) * (int)sqrt(delta) == delta){
			PrintV(- b + sqrt(delta), mu);
			cout << endl;
			continue;
		}
		else {
			if (b ^ 0){
				PrintV(- b, mu);
				cout << "+";
			}
			int x;
			for (x = sqrt(delta); x >= 1; x--){
				if (!(delta % (x * x)))	break;
			}
			int GCD = gcd(x, mu);
			delta /= x * x, x = x / GCD, mu = mu / GCD;
			if (x == 1){
				if (mu == 1) cout << "sqrt(" << delta << ")" << endl;
				else cout << "sqrt(" << delta << ")/" << mu << endl;
			}
			else if (mu == 1) cout << x << "*sqrt(" << delta << ")" << endl;
			else cout << x << "*sqrt(" << delta << ")/" << mu << endl;
		}
	}
	return 0;
}