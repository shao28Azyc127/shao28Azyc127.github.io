#include<bits/stdc++.h>
using namespace std;

/*int read()
{
    int t = 1, x = 0;
    char c;
    c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')
            t = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return t * x;
}*/

/*void write(int x)
{
    if(x < 0) putchar('-');
    while(x > 9)
    {
        write(x / 10);
        putchar(x % 10 + '0');
    }
}*/

int a, b, c, d, e;

char A, B, C, D, E;

map<string, int> mp;

string str;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    //special: not move
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
		cin >> a >> b >> c >> d >> e;
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = ((a + j) % 10);
			A = x + '0', B = b + '0', C = c + '0', D = d + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = ((b + j) % 10);
			A = a + '0', B = x + '0', C = c + '0', D = d + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = ((c + j) % 10);
			A = a + '0', B = b + '0', C = x + '0', D = d + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = ((d + j) % 10);
			A = a + '0', B = b + '0', C = c + '0', D = x + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = ((e + j) % 10);
			A = a + '0', B = b + '0', C = c + '0', D = d + '0', E = x + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = (a + j) % 10, y = (b + j) % 10;
			A = x + '0', B = y + '0', C = c + '0', D = d + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = (b + j) % 10, y = (c + j) % 10;
			A = a + '0', B = x + '0', C = y + '0', D = d + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = (c + j) % 10, y = (d + j) % 10;
			A = a + '0', B = b + '0', C = x + '0', D = y + '0', E = e + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
		for(int j = 1; j <= 9; j++)
		{
			str = "";
			char x = (d + j) % 10, y = (e + j) % 10;
			A = a + '0', B = b + '0', C = c + '0', D = x + '0', E = y + '0';
			str += A, str += B, str += C, str += D, str += E;
			mp[str]++;
		}
	}
	int ans = 0;
	for(int i = 0; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			for(int k = 0; k <= 9; k++)
			{
				for(int p = 0; p <= 9; p++)
				{
					for(int q = 0; q <= 9; q++)
					{
						str = "";
						str += i + '0';
						str += j + '0';
						str += k + '0';
						str += p + '0';
						str += q + '0';
						if(mp[str] == n) ans ++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
