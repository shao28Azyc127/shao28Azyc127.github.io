#include <iostream>
#include <cmath>
using namespace std;

int t,m,a,b,c;

int gcd(int p,int q){
	return q ? gcd(q,p % q) : p;
}

void output_frac(int p,int q){
	int s = p / gcd(p,q),r = q / gcd(p,q);
	if(r < 0) s = -s,r = -r;
	if(r != 1) cout << s << "/" << r;
	else cout << p/gcd(p,q);
}

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> t >> m;
	while(t--){
		cin >> a >> b >> c;
		int del = b * b - 4 * a * c;
		if(del < 0) cout << "NO" << endl;
		else{
			int sq = sqrt(del);
			if(del == sq * sq){
				int p = sq-b,q = 2*a;
				if(q < 0) p = -sq - b;
				output_frac(p,q);
				cout << endl;
			}
			else{
				if(b){
					output_frac(-b,2*a);
					cout << "+";
				}
				int mul = 1;
				for(int i = 2;i <= sq; i++)
					while(del % (i * i) == 0) mul *= i,del /= i * i;
				int p = mul,q = 2 * a;
				p = p / gcd(mul,2 * a);
				q = q / gcd(mul,2 * a);
				if(2 * a < 0) p *= -1;
				if(q < 0) p *= -1,q *= -1;
				if(p == 1){
					if(q == 1) cout << "sqrt(" << del << ")";
					else cout << "sqrt(" << del << ")/" << q;
				}
				else if(q == 1) cout << p << "*sqrt(" << del << ")";
				else cout << p << "*sqrt(" << del << ")/" << q;
				cout << endl;
			}
		}
	}
	
	return 0;
}//1 5 4
//d = 9