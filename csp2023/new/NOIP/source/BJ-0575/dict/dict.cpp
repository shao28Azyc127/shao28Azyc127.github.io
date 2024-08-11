#include <bits/stdc++.h>
using namespace std;

const int NR=3000;
int n,m;
string s[NR+5];
int maxx[NR+5][NR+5],minn[NR+5][NR+5];
string mas[NR+5],mis[NR+5];
int h[30];

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			maxx[i][j]=s[i][j-1];
			minn[i][j]=s[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			h[s[i][j]-'a']++;
		int tmp=0;
		for(int j=25;j>=0;j--)
			while(h[j]>0)
			{
				maxx[i][++tmp]=j;
				h[j]--;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			h[s[i][j]-'a']++;
		int tmp=0;
		for(int j=0;j<=25;j++)
			while(h[j])
			{
				minn[i][++tmp]=j;
				h[j]--;
			}
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		bool vis[NR+5]={};
		vis[i]=true;
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(minn[i][j]>maxx[k][j]&&vis[k]==false)
				{
					flag=false;
					break;
				}
				if(minn[i][j]<maxx[k][j])
					vis[k]=true;
			}
			if(!flag)
				break;
		}
		printf("%d",flag);
	}
	puts("");
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
