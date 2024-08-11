#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n'
mt19937 rnd((unsigned long long)new char);
void file(){freopen("uqe.in", "r", stdin); freopen("uqe.out", "w", stdout);}
void INIT(){ios::sync_with_stdio(false);}
const bool File = 1;
int T, m;
int a, b, c, delta;
bool is_sqrt(int a){
	double b = a * 1.0;
	int sqt = sqrt(b);
	if(sqt * sqt == a) return true;
	return false;
}
int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
int main(){ File ? file() : void(); INIT(); cin >> T >> m; while(T--){
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if(delta < 0){cout << "NO" << endl; continue;}
	if(is_sqrt(delta)){
		//cout << delta << endl;
		int a1 = -b + sqrt(delta), a2 = 2 * a;
		if(a2 < 0) a1 = a1 - 2 * sqrt(delta);
		int g = gcd(a1, a2);
		a1 /= g, a2 /= g;
		if(a2 < 0 && a1 > 0) a1 = -a1, a2 = -a2;
		if(a2 == 1) cout << a1 << endl;
		else cout << a1 << "/" << a2 << endl;
	}else{
		int num = 1;
		for(int i = sqrt(delta); i >= 1; i--)
			if(delta % (i * i) == 0){num = i, delta /= (i * i); break;}
		if(b != 0){
			int a1 = -b, a2 = 2 * a;
			int g = gcd(a1, a2);
			a1 /= g, a2 /= g;
			if(a2 < 0 && a1 > 0) a1 = -a1, a2 = -a2;
			if(a2 == 1) cout << a1 << "+";
			else cout << a1 << "/" << a2 << "+";
		}
		int a1 = num, a2 = 2 * a;
		if(a2 < 0) a1 = -a1;
		if(a1 == a2) cout << "sqrt(" << delta << ")" << endl;
		else if(a1 % a2 == 0) cout << a1 / a2 << "*sqrt(" << delta << ")" << endl;
		else{
			int g = gcd(a1, a2);
			if(a1 != g) cout << a1 / g << "*";
			cout << "sqrt(" << delta << ")/" << a2 / g << endl;
		}
	}
}
	return 0;
}