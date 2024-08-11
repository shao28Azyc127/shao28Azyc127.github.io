#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int t , m;
int find(int x)
{
	if (x == 0)return 0;
	for (int i = m; i >= 1; i--)
		if (x % (i * i) == 0)
			return i;
	return 0;
}
int gcd(int x , int y)
{
	if (x % y == 0)return y;
	return gcd(y , x % y);
}
void change(int &a , int &b)
{
	if (b < 0)
	{
		b = -b;
		a = -a;
	}
	if (a == 0)
	{
		b = 1;
		return;
	}
	int x = abs(a) , y = abs(b);
	int g = gcd(x , y);
	x /= g;
	y /= g;
	if (a < 0)a = -x;
	else a = x;
	if (b < 0)b = -y;
	else b = y;
}
void print(int x , int y)
{
	change(x , y);
	cout << x;
	if (y != 1)cout << "/" << y;
}
void work(int a , int b , int c)
{
	int d = b * b - 4 * a * c;
	if (d < 0)
	{
		cout << "NO\n";
		return;
	}
	int s = find(d);
	if (s * s == d)
	{
		print(-b + s , 2 * a);
		cout << endl;
		return;
	}
	if (b != 0)
	{
		print(-b , 2 * a);
		cout << "+";
	}
	int t = d , t1 = 1 , t2 = 2 * a;
	if (s > 1)
	{
		t /= s * s;
		t1 *= s;
	}
	change(t1 , t2);
	if (t1 == 1 && t2 == 1)
	{
		cout << "sqrt(" << t << ")" << endl;
		return;
	}
	if (t2 == 1)
	{
		cout << t1 << "*sqrt(" << t << ")" << endl;
		return;
	}
	if (t1 == 1)
	{
		cout << "sqrt(" << t << ")" << "/" << t2 << endl;
		return;
	}
	cout << t1 << "*sqrt(" << t << ")/" << t2 << endl;
}
int main()
{
	freopen("uqe.in" , "r" , stdin);
	freopen("uqe.out" , "w" , stdout);
	cin >> t >> m;
	for (int i = 1; i <= t; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		work(a , b , c);
	}
	return 0;
}
