#include<bits/stdc++.h>
using namespace std;
int s[100010];
struct node
{
	int jl,v,id;
}a[100010];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)
	{
		a[i].id=i;
		cin>>a[i].jl;
		s[i]=s[i-1]+a[i].jl;
	}
	a[n].id=n,a[n].jl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v;
	}
	//sort(a+1,a+n,cmp);
	
	
	long long ans=1e9,sum,ans2=0;;
	int tmp,op=1,op2;
	while(sum<=n)
	{
		op=op2;
		for(int i=op+1;i<=n-1;i++)
		{
			int qian =0;
			if(a[i].v<a[1].v)
			{
				if(s[i]%d==0) tmp=s[i]/d;//xu yao de you
				else tmp=s[i]/d+1;
				qian+=tmp*a[1].v;//hua de qian
				if(ans>qian)
				{
					sum+=tmp*d;//yi zou de lu cheng
					op2=i;//dao na li 
					ans=qian;
				}
				
			}
		}
		ans2+=ans;
	}
	cout<<ans2;
	return 0;
}
