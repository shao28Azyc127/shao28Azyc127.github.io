#include<bits/stdc++.h>
using namespace std;
int n,a[10],x,ans;
bool check(int a,int b)
{
	vector<int> wz,dif;
	for(int i=0;i<5;i++)
	{
		if(a%10!=b%10)
			wz.push_back(i),dif.push_back((a%10-b%10+10)%10);
		a/=10,b/=10;
	}
	if(wz.size()==1) return 1;
	if(wz.size()>2||wz.size()==0) return 0;
	return (abs(wz[0]-wz[1])==1&&dif[0]==dif[1]);
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>x;
			a[i]=a[i]*10+x;
		}
	}
	for(int i=0;i<1e5;i++)
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
			if(!check(i,a[j])) flag=0;
		ans+=flag;
	}
	cout<<ans;
	return 0;
}