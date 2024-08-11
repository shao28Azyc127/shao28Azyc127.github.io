#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
queue<int> q;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,day=0,k=0;
	cin>>n;
	for(int i=1;i<=n;i++) q.push(i);
	while(!q.empty())
	{
		k++;
		int m=q.size();
		for(int i=1;i<=m;++i)
		{
			if(i%3!=1)
				q.push(q.front());
			else
				if(q.front()==n)
					day=k;
			q.pop();
		}
	}
	cout<<k<<" "<<day;
	return 0;
}