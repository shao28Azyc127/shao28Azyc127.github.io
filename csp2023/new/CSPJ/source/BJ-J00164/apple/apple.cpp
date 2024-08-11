#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
bool a[N];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,ans2=0,ci=1;
	cin>>n;
	int rest=n;
	while(rest>0)
	{
		int j=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				
				j++;
				//cout<<i<<" "<<j<<endl;
			}
			else
			continue;
			if(j%3==1&&a[i]==0)
			{
				a[i]=1;
				rest--;
				//cout<<i<<endl;
				if(i==n)
				ans2=ci;
			}
		}
		ci++;
	}
	cout<<ci-1<<" "<<ans2;
	return 0;
}