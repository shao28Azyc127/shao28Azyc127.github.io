#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(b == 0)return a;
	else return gcd(b, a % b);
}
void print(int a, int b, int c)
{
	int dta = b * b - 4 * a * c;
	if(dta < 0)
	{
		printf("NO\n");
		return;
	}
	
	
	
	
	if(dta == (int(sqrt(dta)) * int(sqrt(dta))))
	{
		int fuhao = 0, tmp1, tmp2, k;
		dta = sqrt(dta);
		tmp1 = -b + dta;
		tmp2 = 2 * a;
		if(tmp1 < 0)
		{
			fuhao++;
			tmp1 = -tmp1;
		}
		if(tmp2 < 0)
		{
			fuhao++;
			tmp2 = -tmp2;
		}
		if(fuhao % 2 == 1)printf("-");
		if(tmp2 > tmp1)k = gcd(tmp2, tmp1);
		else k = gcd(tmp1, tmp2);
		tmp1 /= k;
		tmp2 /= k;
		if(tmp1 % tmp2 != 0)printf("%d/%d\n", tmp1, tmp2);
		else printf("%d\n", tmp1 / tmp2);
		return;
	}
	
	
	
	
	if(dta != int(sqrt(dta)) * int(sqrt(dta)))
	{
		int xishu = 1, fuhao = 0, tmp = 2 * a;
		for(int i = 2; i * i < dta; i++)
		{
			if(dta % (i * i) == 0)
			{
				xishu *= i;
				dta /= (i*i);
			}
		}//qiuxishu
		
		
		
		if(dta == 1)
		{
			int df = -b + xishu;
			if(df < 0)
			{
				fuhao++;
				df = -df;
			}
			if(tmp < 0)
			{
				fuhao++;
				tmp = -tmp;
			}
			
			int io = gcd(df, tmp);
			df /= io;
			tmp /= io;
			int pk = df / tmp;
			if(pk == 0)printf("0\n");
			else
			{
				if(fuhao % 2 == 1)printf("-");
				if(tmp % io == 0)printf("%d\n", df / tmp);
				printf("%d/%d\n", df, tmp);
			}
		}
		
		
		
		else 
		{
			if(-b < 0)
			{
				b = -b;
				fuhao++;
			}
			if(tmp < 0)
			{
				tmp = -tmp;
				fuhao++;
			}
			
			int k = gcd(-b, tmp);
			b /= k;
			tmp/= k;
			bool nm = 0;
			if(-b % tmp != 0){if(fuhao % 2 == 1)printf("-");printf("%d/%d", -b, tmp);}
			else if(-b / tmp == 0)
			{
				nm = 1;
			}
			else {if(fuhao % 2 == 1)printf("-");printf("%d", -b / tmp);}
			
			//
			fuhao = 0;
			if(xishu < 0)
			{	
				xishu = -xishu;
				fuhao++;
			}
			if(tmp < 0)
			{
				tmp = -tmp;
				fuhao++;
			}
			int p = gcd(xishu, tmp);
			xishu /= p;
			tmp/= p;
			if(xishu != 1)
			{
				if(xishu % tmp != 0)
				{
					if(fuhao % 2 == 1)printf("-");
					else if(nm == 0)printf("+");
					printf("%d*sqrt(%d)/%d\n", xishu, dta, tmp);
				}
				else 
				{
					if(xishu / tmp == 0)printf("0\n");
					else
					{
						if(fuhao % 2 == 1)printf("-");
						else if(nm == 0)printf("+");
						printf("%d*sqrt(%d)\n", -b / tmp, dta);
					}
				}
			}
			else printf("sqrt(%d)/%d\n", dta, tmp);
		}
	}
}
int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	int t, lol;
	cin >> t >> lol;
	for(int i = 1; i <= t; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		print(x, y, z);
	}
	
	return 0;
}
