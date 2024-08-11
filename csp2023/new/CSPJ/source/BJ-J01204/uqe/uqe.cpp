#include <bits/stdc++.h>
using namespace std;
int T , M;
int GCD(int x , int y) {
	while(x%y) {
		int t = x;
		x = y , y = t%y;
	}
	return y;
}
int Squ(int x) {
	if(x == 0)
		return 0;
	int ret = 1;
	for(int i = 2;i*i <= x;i++)
		if(x%(i*i) == 0)
			ret = max(ret , i);
	return ret;
}
void Print(int p , int q) {
	int np = p / GCD(abs(p),abs(q)) , nq = q / GCD(abs(p),abs(q));
	cout << np;
	if(nq != 1) 
		cout << "/" << nq;
}
void Root(int a , int b , int c) {
	if(c == 0 && a*b>=0) {
		cout << 0 << endl;
		return;
	}
	if(a < 0)	a = -a , b = -b , c = -c;
	
	int d = b*b-4*a*c;
	if(d<0) {
		cout << "NO" << endl;
		return;
	}

	int r = Squ(d);
	if(r*r == d)
		b = b-r;
	if(b != 0)	
		Print(-b , 2*a);
	if(r*r != d) {
		if(b != 0)
			cout << "+";
		int q2 = GCD(r,2*a);
		if(r/q2 != 1)
			cout << r/q2 << "*";
		cout << "sqrt(" << d/(r*r) << ")";
		if(2*a/q2 != 1)
			cout << "/" << 2*a/q2;
	}
	cout << endl;
}
int main() {
	freopen("uqe.in" , "r" , stdin);
	freopen("uqe.out" , "w" , stdout);
	cin >> T >> M;
	while(T--) {
		int a , b , c;
		cin >> a >> b >> c;
		Root(a , b , c);
	}
	return 0;
}