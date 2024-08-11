#include <bits/stdc++.h>
using namespace std;
queue<int> q;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int m=n;
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}
	int day=1;
	int j,i=1;
	int sum=0;
	while(!q.empty())
	{
		if((i-1)%3==0)
		{
			if(q.front()==m) j=day;
			//cout<<sum<<" "<<day<<" "<<i<<endl;
			q.pop();
			sum++;
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		if(i>=n)
		{
			day++;
			i=0;
			n-=sum;
			sum=0;
		}
		i++;
	}
	cout<<day-1<<" "<<j;
	return 0;
}
