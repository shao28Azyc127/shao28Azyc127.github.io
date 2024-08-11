#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, c, d, e = 0, p = 0;
bool k = 0;
int GCd(int x, int y)
{
    if(x % y == 0)
    {
    	return y;
    }
    x %= y;
    GCd(y, x);
}
int derta(int q)
{
    int z = 1;
    for(int i = 2;i * i <= q;++i)
    {
    	if(q % (i * i) == 0)
    	{
    	    z *= i;
    	    q /= i * i;
    	}
    }
    if(q == 1)
    {
    	return z;
    }
    return 0;
}
void you()
{
    if(b == 0)
    {
    	return;
    }
    a *= 2;
    b = -b + e;
    if(b < 0)
    {
    	cout << "-";
    	b = -b;
    }
    int v = GCd(b, a);
    cout << b / v;
    if(a != v)
    {
    	cout << "/" << a / v;
    }
    k = 1;
}
void wu()
{
    if(d == 0 || e != 0)
    {
    	return;
    }
    if(k == 0)
    {
    	a *= 2;
    }
    else
    {
    	cout << "+";
    }
    int z = 1;
    for(int i = 2;i * i <= d;++i)
    {
    	if(d % (i * i) == 0)
    	{
    	    while(d % (i * i) == 0)
    	    {
    	    	z *= i;
    	    	d /= i * i;
    	    }
    	}
    }
    int v = GCd(z, a);
    if(z != v)
    {
    	cout << z / v << "*";
    }
    cout << "sqrt(" << d << ")";
    if(a != v)
    {
    	cout << "/" << a / v;
    }
//    cout << " " << z << " " << d;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
    	cin >> a >> b >> c;
    	if(a < 0)
    	{
    	    a = -a;
    	    b = -b;
    	    c = -c;
    	}
    	for(int i = 2;i <= min(a, min(b, c));++i)
    	{
    	    if(abs(a) % i == 0 && abs(b) % i == 0 && abs(c) % i == 0)
    	    {
    	    	while(abs(a) % i == 0 && abs(b) % i == 0 && abs(c) % i == 0)
    	    	{
    	    	    a /= i;
    	    	    b /= i;
    	    	    c /= i;
    	    	}
    	    }
    	}
    	d = b * b - 4 * a * c;
//    	cout << d << " ";
    	e = derta(d);
    	if(d < 0)
    	{
    	    cout << "NO" << endl;
    	    continue;
    	}
    	p = 0;
    	k = 0;
    	you();
    	wu();
    	cout << endl;
    }
    return 0;
}