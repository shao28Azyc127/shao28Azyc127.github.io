#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5+5, INF = 0x3f3f3f3f;
const LL MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f;
int T, M;
int a, b, c, dt, p, q, g;
int gcd(int x, int y){
	if(x < y) swap(x, y);		// ensure x >= y
	if(y == 0) return x;
	return gcd(y, x%y);
}
int simpfy(int &x, int &y){
	int k = 0;
	if(x*y > 0) k = 1;
	else if(x*y < 0) k = -1;
	x = abs(x), y = abs(y);
	int g = gcd(x, y);
	x /= g, y /= g;
	return k;
}
bool print(int p, int q){	// print (p/q) (q != 0)
	int k = simpfy(p, q);
	if(!k) return false;
	cout<<k*p;
	if(q != 1) cout<<'/'<<q;
	return true;
}
#define FILE "uqe"
int main(){
	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T>>M;
	while(T--){
		cin>>a>>b>>c;
		dt = b*b-4*a*c;
		a *= 2;
		if(dt < 0){
			cout<<"NO\n";
			continue;
		}
		else if(dt == 0){
			if(!print(0-b, a))	// (-b)/(2*a)
				cout<<0;
		}
		else{
			int sqr = sqrt(dt);
			if(sqr*sqr == dt){
				if(a < 0){
					if(!print(0-sqr-b, a))	// (-b-sqr(dt))/(2*a)
						cout<<0;
				}
				else{
					if(!print(sqr-b, a))
						cout<<0;;	// (-b+sqr(dt))/(2*a);
				}
			}
			else{
				int k = 1;
				for(int i = sqr; i > 1; i--){
					if(dt%(i*i) == 0){
						k *= i;
						dt /= i*i;
					}
				}
				if(print(0-b, a))cout<<'+';
				simpfy(k, a);
				if(k != 1) cout<<k<<'*';
				cout<<"sqrt("<<dt<<')';
				if(a != 1) cout<<'/'<<a;
			}
		}
		cout<<endl;
	}
	return 0;
}
