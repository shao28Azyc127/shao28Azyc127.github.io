#include <iostream>
#include <cmath>
using namespace std;

long long T,M;

long long gcd(long long a,long long b){
	if(b == 0) return a;
	return gcd(b,a % b);
}

long long last(long long d){
	for(long long i = sqrt(d);i > 0;i--){
		if(d % (i * i) == 0) d /= (i * i);
	}

	return d;
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);

	cin >> T >> M;
	while(T--){
		long long a,b,c,dota,r;
		cin >> a >> b >> c;
		dota = b * b - 4 * a * c;
		r = sqrt(dota);
		if(dota < 0){
			cout << "NO" << endl;
			continue;
		}

		if(r * r == dota){
			if((-1 * b + r) / gcd(-1 * b + r,2 * a) > (-1 * b - r) / gcd(-1 * b - r,2 * a)){
				if(2 * a / gcd(-1 * b + r,2 * a) < 0) cout << -1 * (-1 * b + r) / gcd(-1 * b + r,2 * a);
				else cout << (-1 * b + r) / gcd(-1 * b + r,2 * a);
			}else{
				if(2 * a / gcd(-1 * b - r,2 * a) < 0) cout << -1 * (-1 * b - r) / gcd(-1 * b - r,2 * a);
				else cout << (-1 * b - r) / gcd(-1 * b - r,2 * a);
			}

			if(abs(2 * a / gcd(-1 * b + r,2 * a)) != 1) cout << '/' << abs(2 * a / gcd(-1 * b + r,2 * a));
			cout << endl;
			continue;
		}

		if(b != 0){
			if(2 * a / gcd(-1 * b,2 * a) > 0) cout << -1 * b / gcd(-1 * b,2 * a);
			else cout << b / gcd(-1 * b,2 * a);

			if(abs(2 * a / gcd(-1 * b,2 * a)) != 1) cout << '/' << abs(2 * a / gcd(-1 * b,2 * a));
			cout << '+';
		}

		r = last(dota);
		if(abs(sqrt(dota / r) / gcd(sqrt(dota / r),2 * a)) != 1) cout << abs(sqrt(dota / r) / gcd(sqrt(dota / r),2 * a)) << '*';
		cout << "sqrt(" << r << ')';
		if(abs(2 * a / gcd(sqrt(dota / r),2 * a)) != 1) cout << '/' << abs(2 * a / gcd(sqrt(dota / r),2 * a));
		cout << endl;
	}
}