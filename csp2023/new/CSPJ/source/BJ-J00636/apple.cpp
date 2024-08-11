#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n;
int a[N];
int sum,ans=0,tp;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	sum=n;
	for(int i=1;i<=n;i++) a[i]=1;
	while(sum>0)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0 && (flag==3 || flag==0)) 
			{
				a[i]=0;
				if(i==n) tp=ans+1;
				sum--;
				flag=1;
			}
			else if(a[i]!=0) flag++;
		}
		ans++;
	}
	cout<<ans<<" "<<tp<<endl;
	return 0;
}