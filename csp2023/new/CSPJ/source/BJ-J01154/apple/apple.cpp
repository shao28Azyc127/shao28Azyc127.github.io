#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.ans","w",stdout);
	long long n;cin>>n;
	int visit[n+10];
	for(int i=1;i<=n+10;i++) visit[i]=0;
	long long t=0,day=0,D=0;
	long long cnt=0;
	while(cnt!=n)
	{
		t=0;
		day++;
		for(int i=1;i<=n;i++)
		{
			if(!visit[i]) t++;
			if(!visit[i] && t%3==1) 
			{
				visit[i]=1;
				if(i==n) D=day;
				cnt++;
			}
		}	
	}
	cout<<day<<" "<<D<<endl;
	return 0;
}
