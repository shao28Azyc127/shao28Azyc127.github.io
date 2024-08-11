#include<bits/stdc++.h>
using namespace std;

struct nd{
	int b;
	int s;
};
nd a[1000000005];
bool cmp(nd x,nd y)
{
	if(x.s!=y.s)
	{
		return x.s>y.s;
	}
	else
	{
		return x.b<y.b;
	}
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<" "<<"1";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].b=i;
		a[i].s=1;
	}
	int cnt=0;
	int ans=100000;
    int k;
	while(a[1].s>0)
	{
	    if((n-1)%3==0)
        {
            ans=1;
        }
	    cnt++;
		for(int i=1;i<=n;i+=3)
		{
			a[i].s=0;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].b==n)
			{
				if(a[i].s==0)
				{
					ans=min(ans,cnt);
					a[i].s=-1;
				}
			}
		}

	}
	cout<<cnt<<" "<<ans;
	return 0;
}