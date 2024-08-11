#include<bits/stdc++.h>
using namespace std;
char a[10000];
char b[10000][10000];
int main()
{
		//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			for(int k=1;k<=i;k++)
			{
				b[j][k]=a[k];
			}
		}
	}
	cout<<0;
	//for(int i=1;i<=n;i++)
	//{
		//for(int j=1;j<=n-i;j++)
		//{
			//for(int k=1;k<=i;k++)
			//{
				//cout<<b[j][k]<<" ";
			//}
		//}
	//}

	return 0;
}
