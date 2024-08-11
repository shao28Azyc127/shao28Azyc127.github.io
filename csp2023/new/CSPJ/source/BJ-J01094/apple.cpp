#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int ans,a;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
//	printf("%d",n);
//	q.push(1);
//	printf("%d",n);
	for (int i=1;i<=n;i++)
	{
		q.push(i);
	}
//	cout<<1;
//	return 0;
	while (!q.empty())
	{
		a++;/*
		for (int i=1;i<=int(q.size());i++)
		{
			cout<<q.front()<<' ';
			q.push(q.front());
			q.pop();
		}
		cout<<endl;*/
		int x=q.size();
		for (int i=1;i<=x;i++)
		{
			int c=q.front();
			q.pop();
			if (i%3!=1)
			{
				q.push(c);
			}
			else if (c==n)
			{
				ans=a;
			}
		}
	}
	printf("%d %d",a,ans);
	return 0;
}
