#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, M, a, b, c, d, q;

int GCD(int x, int y)
{
	if(!y) return x;
	return GCD(y, x % y);
}

inline void print1(int x, int y, char z)
{
	if(x == 0 && z == '+') return ;
	int tmp = GCD(x, y);
	if(y / tmp < 0) tmp *= -1;
	if(tmp == y) cout << x / tmp << z;
	else cout << x / tmp << "/" << y / tmp << z;
}

inline void print2(int x, int y, int z)
{
	int tmp = GCD(x, y);
	if(x == y) cout << "sqrt(" << z << ")" << endl;
	else if(tmp == y) cout << x / tmp << "*sqrt(" << z << ")" << endl;
	else if(tmp == x) cout << "sqrt(" << z << ")/" << y / tmp << endl;
	else cout << x / tmp << "*sqrt(" << z << ")/" << y / tmp << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);

	cin >> T >> M;
	while(T--)
	{
		cin >> a >> b >> c;
		d = b * b - 4 * a * c, q = 1;
		if(d < 0) cout << "NO" << endl;
		else if(d == 0) print1(-b, 2 * a, '\n');
		else
		{
			if(a < 0) a *= -1, b *= -1;
			for(int i = 2; i <= 3 * M && d > 1; i++)
				while(d % (i * i) == 0) d /= (i * i), q *= i;
			if(d == 1) print1(-b + q, 2 * a, '\n');
			else print1(-b, 2 * a, '+'), print2(q, 2 * a, d);
		}
	}
	
	return 0;
}