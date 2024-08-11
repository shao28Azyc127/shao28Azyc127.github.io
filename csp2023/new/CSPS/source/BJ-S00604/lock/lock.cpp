#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int tkr[10];
int unt[10];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cin>>a[0][0]>>a[1][0]>>a[2][0]>>a[3][0]>>a[4][0];
		cout<<"81";
	}
	if(n==2)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i]>>a[4][i];
		}
		cout<<"10";
	}
	if(n<=8&&n>2)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i]>>a[4][i];
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<10;j++)
			{
				for(int l=0;l<8;l++)
				{
					if(a[i][l]==j)
					{
						tkr[i]++;
						break;
					}
				}
			}
		}
		cout<<(10-tkr[0])+(10-tkr[1])+(10-tkr[2])+(10-tkr[3])+(10-tkr[4]);
	}
	return 0;
}
