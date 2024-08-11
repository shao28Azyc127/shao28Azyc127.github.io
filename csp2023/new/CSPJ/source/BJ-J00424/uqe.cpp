#include<bits/stdc++.h>
using namespace std;
bool isp(int x)
{
	if(x == 0 || x == 1) return 0;
	for(int i = 2;i * i <= x;i++)
		if(x % i == 0) return 0;
	return 1;
}
string tostring(int x)
{
	string s = "";
	while(x > 0)
	{
		s = char(x % 10 + '0') + s;
		x /= 10;
	}
	return s;
}
string yls(double x)
{
	if(x == 1.0 * int(x))
	{
		string s = tostring(int(x));
		return s;
	}
	return "114514";
}
bool checkpf(int x)
{
	int s = 1.0 * sqrt(1.0 * x);
	return(s * s == x);
}
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,m;
	scanf("%d%d",&T,&m);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int delta = b * b - 4 * a * c;
		if(delta < 0)
		{
			cout << "NO" << endl;
			continue;
		}
		if(checkpf(delta))
		{
			int fz1 = (-b) + int(sqrt(1.0 * delta));
			int fm1 = 2 * a;
			int gcd = __gcd(fz1,fm1);
			fz1 /= gcd; fm1 /= gcd;
			if(fm1 < 0) fm1 = -fm1,fz1 = -fz1;
			
			int fz2 = (-b) - int(sqrt(1.0 * delta));
			int fm2 = 2 * a;
			gcd = __gcd(fz2,fm2);
			fz2 /= gcd; fm2 /= gcd;
			if(fm2 < 0) fm2 = -fm2,fz2 = -fz2;
			double f1 = 1.0 * fz1 / fm1,f2 = 1.0 * fz2 / fm2;
			if(f1 > f2)
			{
				if(fz1 % fm1 == 0) 
				{
					cout << fz1 / fm1 << endl;
					continue;
				}
				else 
				{
					cout << fz1 << "/" << fm1 << endl;
					continue;
				}
			}
			else
			{
				if(fz2 % fm2 == 0) cout << fz2 / fm2 << endl;
				else cout << fz2 << "/" << fm2 << endl;
			}
			continue;
		}
		int q1 = 0,q2 = 1,ndelta = delta;
		double qq1 = 0,qq2 = 0;
		//cout << ndelta << endl;
		
		for(int i = 2;i * i <= m;i++)
		{
			if(isp(i))
			{
				while(ndelta % (i * i) == 0) 
				{
					q2 *= i;
					ndelta /= (i * i);
				}
			}
		}
		int q1fz = (-b);
		int q1fm = 2 * a;
		//cout << q1fz << "/" << q1fm << endl;
		int q2fz = q2;
		int q2fm = 2 * a;
		//cout << q2fz << "/" << q2fm << endl;
		
		int gcd = __gcd(q1fz,q1fm);
		q1fz /= gcd,q1fm /= gcd;
		if(q1fz % q1fm == 0) q1 = q1fz / q1fm;
		else 
		{
			if(q1fm < 0) q1fz = -q1fz,q1fm = -q1fm;
			qq1 = 1.0 * q1fz / q1fm;
		}
		int gcd2 = __gcd(q2fz,q2fm);
		q2fz /= gcd2,q2fm /= gcd2;
		if(q2fz % q2fm == 0) q2 = q2fz / q2fm;
		else 
		{
			if(q2fm < 0) q2fz = -q2fz,q2fm = -q2fm;
			qq2 = 1.0 * q2fz / q2fm;
		}
		//cout << q2fz << "/" << q2fm << endl;
		
		if(q1 != 0) cout << q1 << "+";
		else if(qq1 != 0) cout << q1fz << "/" << q1fm << "+";
		else cout << "";
		
		if(abs(q2) == 1 && qq2 == 0)
		{
			cout << "sqrt(" << ndelta << ")" << endl;
		}
		else if(q2 && qq2 == 0)
		{
			cout << abs(q2) << "*" << "sqrt(" << ndelta << ")" << endl;
		}
		else if(1.0 / qq2 == 1.0 * int(1.0 / qq2))
		{
			cout << "sqrt(" << ndelta << ")/" << abs(int(1.0 / qq2)) << endl; 
		}
		else
		{
			if(q2fz == 1) cout << "sqrt(" << ndelta << ")/" << abs(q2fm) << endl;
			else cout << abs(q2fz) << "*" << "sqrt(" << ndelta << ")/" << abs(q2fm) << endl;
		}
	}
	return 0;
}
