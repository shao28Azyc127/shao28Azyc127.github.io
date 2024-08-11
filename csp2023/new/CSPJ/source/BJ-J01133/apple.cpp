#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5000005];
int ans2=0;
int cnt=0;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		int fk=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==-11) fk++;
			if((a[j]-fk-1)%3==0)
			{
				if(a[j]==n) ans2=cnt;
				a[j]=-11;
			}
		}
		bool z=true;
		for(int f=1;f<=n;f++)
		{
			if(a[f]!=-11)
			{
				z=false;
				break;
			}
		}
		if(z==true) break;
	}
	cout<<cnt<<" "<<ans2;
	return 0;
}
