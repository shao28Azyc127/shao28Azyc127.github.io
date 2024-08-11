#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],q =0;
bool fl = true;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	int cnt = 1;
	memset(a,-1,sizeof a);
	int l = n,t = 0;
	while(1)
	{
		cnt = 0;
		t++;
		int p = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == -1)
			{
				p++;
				if(p % 3 == 1)
				{
					a[i] = 0;
					cnt++;
				}
			}
		}
		l -= cnt;
		if(l == 0)
		{
			cout << t <<" ";
			break;
		}
		if(a[n] == 0 && fl == true)
		{
			q = t;
			fl = false;
		}
	}
	cout << q;
	return 0;
}