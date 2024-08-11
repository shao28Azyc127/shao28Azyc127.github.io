#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans2=0,out=0,cur=2,t=0;
	while(out<n)
	{
		t++;
		cur=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(cur==2)
				{
					out++;
					if(i==n)
					{
						ans2=t;
					}
					a[i]=1;
					cur=0;
				}
				else
				{
					cur++;
				}				
			}
		}
	}				
	cout<<t<<" "<<ans2;
	return 0;
}
