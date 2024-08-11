#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct Node
{
	int v,m;
}a[N],b[N];
bool cmp(Node x,Node y)
{
	return x.m<y.m;
}
int func(int a,int b)
{
	if(a%b==0)return a/b;
	else return a/b+1;
}
bool flag1=true,flag2=true,flag3=false;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int sum=0;
	for(int i=1;i<n;i++)
	{
		cin>>a[i].v;
		b[i].v=a[i].v;
		if(a[i].v%d!=0)flag1=false;
	}
	cin>>a[1].m;
	int x=a[1].m;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i].m;
		b[i].m=a[i].m;
		if(a[i].m<a[1].m)flag2=false;
	}
	if(flag1)
	{
		sort(b+1,b+n+1,cmp);
		if(b[1].m==x)
		{
			int tot=0;
			for(int i=1;i<n;i++)
			{
				tot+=a[i].v;
				//cout<<"tot="<<tot<<endl<<"a["<<i<<"].v="<<a[i].v<<endl;
			}
			cout<<(tot/d)*b[1].m<<endl;
		}
		else
		{
			int id=0,l=0;
			for(int i=1;i<n;i++)
			{
				if(!flag3&&a[i].m!=b[1].m)
				{
					int dis=a[i].v/d;
					sum+=dis*a[1].m;
				}
				else
				{
					id=i;
					l+=a[i].v;
					flag3=true;
				}
			}
			cout<<sum+l*a[id].m<<endl;
		}
	}
	if(flag2)
	{
		int tot=0;
		for(int i=1;i<n;i++)
		{
			tot+=a[i].v;
			//cout<<"tot="<<tot<<endl<<"a["<<i<<"].v="<<a[i].v<<endl;
		}
		cout<<(tot/d+1)*a[1].m<<endl;
	}
	if(n<=10)
	{
		if(n==1)cout<<0<<endl;
		if(n==2)cout<<(a[1].v/d)*a[1].m<<endl;
		if(n==3)
		{
			int x=a[1].v+a[2].v;
			if(a[1].m>=a[2].m)cout<<func(a[1].v,d)*a[1].m+func(a[2].v,d)*a[2].m;
			else cout<<func(x,d)<<endl;
		}
		if(n==4)
		{
			int x=a[1].v+a[2].v+a[3].v;
			if(a[1].m<=a[2].m<=a[3].m)cout<<func(x,d)*a[1].m;
			else if(a[2].m<=a[3].m&&a[2].m<=a[1].m)cout<<func(a[1].v,d)*a[1].m+func(x-a[1].v,d)*a[2].m;
			else cout<<func(a[1].v,d)*a[1].m+func(a[2].v,d)*a[2].m+func(a[3].v,d)*a[3].m<<endl;
		}
		if(n==5)
			int x=a[1].v+a[2].v+a[3].v+a[4].v;
			if(a[1].m<=a[2].m<=a[3].m&&a[1].m<=a[4].m)cout<<func(x,d)*a[1].m;
			else if(a[2].m<=a[3].m&&a[2].m<=a[1].m&&a[2].m<=a[4].m)cout<<func(a[1].v,d)*a[1].m+func(x-a[1].v,d)*a[2].m;
			else if(a[3].m<=a[2].m&&a[3].m<=a[1].m&&a[3].m<=a[4].m)cout<<func(a[1].v,d)*a[1].m+func(a[2].v,d)*a[1].m+func(x-a[1].v-a[2].v,d)*a[3].m;
			else cout<<func(a[1].v,d)*a[1].m+func(a[2].v,d)*a[2].m+func(a[3].v,d)*a[3].m+func(a[4].v,d)*a[4].m<<endl;
	}
	return 0;
}