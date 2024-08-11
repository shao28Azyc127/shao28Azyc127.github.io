#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b == 0? a : gcd(b, a % b);
}

void sqout(int delta, int a, int b);

void ratout(int ch, int mo)
{
	int g = gcd(ch, mo);
	bool flag = true;
	if (ch == 0)
	{
		printf("0");
		return;
	}
	ch /= g;
	mo /= g;
	if (mo < 0)
	{
		mo = -mo;
		ch = -ch;
	}
	if (ch < 0)
	{
		flag = false;
	}
	if (mo == 1)
	{
		printf("%d", ch);
	}
	else
	{
		printf("%d/%d", ch, mo);
	}
}

int main()
{
	int T, M, a, b, c, fac, lr, fcnt;
	bool l, r, adb;
	int delta;
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> T >> M;
	for (int idx = 0; idx < T; idx++)
	{
		cin >> a >> b >> c;
		delta = b * b - 4 * a * c;
		if (delta < 0 || a == 0)
		{
			printf("NO\n");
			continue;
		}
		if (delta == 0)
		{
			ratout(-b, a * 2);
			putchar('\n');
			continue;
		}
		if ((int)sqrt(delta) * (int)sqrt(delta) == delta)
		{
			if (a < 0)
			{
				a = -a;
				b = -b;
			}
			delta = (int)sqrt(delta);
			delta -= b;
			ratout(delta, a * 2);
			printf("\n");
			continue;
		}
		fac = 1;
		for (int i = 2; i <= sqrt(delta); i++)
		{
			if (delta % i == 0)
			{
				fcnt = 0;
				while (delta % i == 0)
				{
					delta /= i;
					fcnt += 1;
				}
				fac *= pow(i, fcnt / 2);
				if (fcnt & 1)
					delta *= i;
			}
		}
		lr = 2 * a;
		int g = gcd(fac, 2 * a);
		fac /= g;
		lr /= g;
		if (lr < 0)
		{
			fac = -fac;
			lr = -lr;
		}
		// -b / 2a + fac * sqrt(delta) / lr
		adb = false;
		if (b != 0)
		{
			ratout(-b, a * 2);
			putchar('+');
		}
		if (fac < 0)
			fac = -fac;
		if (lr == 1)
		{
			if (fac == 1)
			{
				printf("sqrt(%d)", delta);
			}
			else
			{
				if (fac == -1)
				{
					printf("-sqrt(%d)", delta);
				}
				else
				{
					if (adb)
						putchar('+');
					printf("%d*sqrt(%d)", fac, delta);
				}
			}
		}
		else
		{
			if (fac == 1)
			{
				printf("sqrt(%d)/%d", delta, lr);
			}
			else
				if (fac == -1)
					printf("-sqrt(%d)/%d", delta, lr);
				else
				{
					printf("%d*sqrt(%d)/%d", fac, delta, lr);
				}
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
