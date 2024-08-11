#include <bits/stdc++.h>
using namespace std;

string s[101];
int k[101];
string t,ni[101][101];
int ti[101][101];

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n,op;
	cin >> n;
	for(int p = 1;p <= n;p++)
	{
		cin >> op;
		if(op == 1)
		{
			int m,sum = 0,f = 1;
			cin >> s[p] >> k[p];
			for(int i = 1;i <= k[p];i++)
			{
				cin >> t >> ni[p][i];
				if(t == "byte")
				{
					ti[p][i] = 1;
				}
				else if(t == "short")
				{
					ti[p][i] = 2;
				}
				else if(t == "int")
				{
					ti[p][i] = 4;
				}
				else if(t == "long")
				{
					ti[p][i] = 8;
				}
				m = max(ti[p][i],ti[p][i-1]);
				sum += ti[p][i];
			}
			while(m*f < sum)
			{
				f++;
			}
			sum = m*f;
			cout << sum << " " << m << endl;
		}
		if(op == 2)
		{
			string t,n1;
			cin >> t >> n1;
			for(int i = 1;i <= p;i++)
			{
				if(t == s[p])
				{
					
				}
			}
		}
	}
	return 0;
}
