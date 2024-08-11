#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
string s[3005];
int c[3005][3005];
int cbin[30];
int cmin[3005][3005],cmax[3005][3005];
int n,m;
int flag[3005];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=26;j++)cbin[j]=0;
		
		for(int j=0;j<m;j++)
		{
			c[i][j+1]=s[i][j]-'a'+1;
			cbin[c[i][j+1]]++;
		}
		int cnt=0;
		for(int j=1;j<=26;j++)
		{
			for(int k=1;k<=cbin[j];k++)
			{
				cnt++;
				cmin[i][cnt]=j;
			}
		}
		cnt=0;
		for(int j=26;j>=1;j--)
		{
			for(int k=1;k<=cbin[j];k++)
			{
				cnt++;
				cmax[i][cnt]=j;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		flag[i]=1;
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			
			for(int k=1;k<=m;k++)
			{
				if(cmin[i][k]<cmax[j][k])
				{
					break;
				}
				else if(cmin[i][k]>cmax[j][k])
				{
					flag[i]=0;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		printf("%d",flag[i]);
	}
	
	return 0;
}
