#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,ans=0;
queue<int>a;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++)
	{
		a.push(i);
	}
	while(!a.empty())
	{
		int o=0;
		cnt++;
		for(int i=1;i<=m;i++)
		{
			if(i%3==1)
			{
				o++;
				if(a.front()==n)
				{
					ans=cnt;
				}
			}
			else
			{
				a.push(a.front());
			}
			a.pop();
		}
		m-=o;
	}
	cout<<cnt<<' '<<ans;
	return 0;
}