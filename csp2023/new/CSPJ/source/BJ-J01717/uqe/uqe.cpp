#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	int r = a % b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	
	freopen("uqe.in" , "r" , stdin);
	freopen("uqe.out" , "w" , stdout);
	
	int T , M;
	cin >> T >> M;
	while(T--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int d = b * b - 4 * a * c;
		if(d < 0) cout << "NO" << endl;
		else if(d > 0)
		{
			double x1 = (-1.0 * b + 1.0 * sqrt(d)) / (2.0 * a);
			double x2 = (-1.0 * b - 1.0 * sqrt(d)) / (2.0 * a);
			double x = max(x1 , x2);
			if(x - int(x) == 0) cout << x << endl;
			else cout << endl;
		}
		else
		{
			double x = (-1.0 * b) / (2.0 * a);
			if(x - int(x) == 0) cout << x << endl;
		}
	}
	return 0;
}