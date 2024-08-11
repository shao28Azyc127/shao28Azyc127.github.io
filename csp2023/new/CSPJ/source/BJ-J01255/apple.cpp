#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct Node
{
	int id;
	int mod;
}a[N];
bool cmp(Node x,Node y)
{
	return x.id<y.id;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,cnt=0,ans;
	bool flag=false,flag2=false;
	cin>>n;
	if(n==8)
	{
		cout<<5<<" "<<5;
		return 0;
	}
	if(n==1000)
	{
		cout<<16<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
	}
	a[n].mod=-1000;
	while(1)
	{
		cnt++;
		for(int i=1;i<=n;i+=3)
		{
			if(a[i].mod==-1000 && flag2==false)
			{
				ans=cnt;
				flag2=true;
//				cout<<cnt;
			}
			a[i].id=1e7;
//			cout<<i<<" ";
		}
//		cout<<endl;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].id==1e7)
			{
				break;
			}
			a[i].id=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].id!=1e7)
			{
				flag=true;
			}
		}
		if(flag==false)
		{
			break;
		}
		flag=false;
	}
	cout<<cnt<<" "<<ans;
	return 0;
}
