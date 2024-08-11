#include<bits/stdc++.h>
using namespace std;
queue<int> s;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i,cnt=0,x,ans;
	bool f=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s.push(i);
	}
	while(f==0)
	{
		x=s.front();
		for(i=x;i<=n;i+=3)
		{
			if(s.front()==n)
			{
				ans=cnt;
			}
			s.pop();
			if(s.empty()==1)
			{
				f=1;
			}
		}
		cnt++;
	}
	cout<<cnt<<" "<<ans+1;
	return 0;
}	
