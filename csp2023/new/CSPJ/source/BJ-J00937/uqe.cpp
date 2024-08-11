#include<bits/stdc++.h>
using namespace std;
int w[100005],r[100005];
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int n,m,a,b,c,ans1,ans2,ans;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a>>b>>c;
		if(b == 0)
		{
			for(int i = -m;i <= m;i++)
			{
				ans = a * i * i + c;
				if(ans == 0)
				{
					ans1 = a;
					ans2 = c;
				}	
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
