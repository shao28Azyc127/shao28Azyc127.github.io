#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool a[100000010];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int m=n;
	int _ans=0,_day=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=1;
	}
	while(m)
	{
		int x=3;
		_day++;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				continue;
			}
			if(x==3)
			{
				m--;
				a[i]=0;
				x=0;
				if(i==n)
				{
					_ans=_day;
				}
			}
			x++;
		}
	}
	cout<<_day<<' '<<_ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
