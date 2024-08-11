#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
}a[100001],r[100001];
int main()
{
	freopen("tree.in","w",stdin);
	freopen("tree.out","r",stdout);
	int n,m,ans=0,cnt=0,num;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		cnt=0;
		num=0;
		while(num<a[i].x)
		{
			num+=max(a[i].y+a[i].z*cnt,1);
			cnt++;
		}
		ans=max(cnt,ans);
	}
	for(int i=1;i<n;i++)
	{
		cin>>r[i].x>>r[i].y;
	}
	cout<<ans;
	return 0;
}