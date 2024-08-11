#include<bits/stdc++.h>
using namespace std;
int n,ans1=1,ans2,cnt=1,t=2;
queue<int> q;
bool f=1,b=0;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		q.push(i);
	}
	while(!q.empty())
	{
		if(q.front()==t)
		{
			if(f==0)
			{
				ans1++;
				cnt=1;
			}
			else f=0;
		}
		if(cnt%3==1)
		{
			if(q.front()==n)ans2=ans1;
			if(q.front()==t)
			{
				q.pop();
				t=q.front();
				f=1;
			}
			else q.pop();
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}
	printf("%d %d",ans1,ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
