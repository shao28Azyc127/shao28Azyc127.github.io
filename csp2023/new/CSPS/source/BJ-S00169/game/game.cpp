#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j+=2)
		{
			queue<char> q;
			for(int k=i;k<=j;k++)
			{
				q.push(s[k]);
			}
			int cnt=0;
			while((!q.empty())&&(cnt<=(j-i+1)*(j-i+1)/4))
			{
				cnt++;
				int a=q.front();
				q.pop();
				if(a==q.front())
				{
					q.pop();
				}
				else
				{
					q.push(a);
				}
			}
			if(q.empty())
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
