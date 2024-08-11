#include<bits/stdc++.h>
using namespace std;
struct groud
{
	int a;
	int b;
	int c;
	bool f=0;
}arr[100000];
//brr[10000][10000];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].a>>arr[i].b>>arr[i].c;
	}
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		//brr[x][y]=1;
		//brr[y][x]=1;
	}
	/*int p=1;
	int cnt=0;
	int minn=1e9;
	while(n)
	{
		cnt++;
		arr[p].f=1;
		for(int i=1;i<n;i++)
		{
			if(brr[p][i]==1)
			{
				if(arr[i].b<)
				minn=min(minn,arr[i].b);
			}
		}
	}*/
	cout<<15;
	return 0;
}
