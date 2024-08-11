#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
char dic[N][N];
int temp[N][26];
int mindic[N],maxdic[N];
int getn(char c)
{
	return c-'a';
}
int n,l;
int ans[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++)
	scanf("%s",dic[i]+1);
	if(n==1)
	{
		printf("1");
		return 0;
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=l;j++)
			temp[i][getn(dic[i][j])]++;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=25;j++)
		{
			if(temp[i][j])
			{
				mindic[i]=j;
				break;
			}
		}
		for(int j=25;j>=0;j--)
		{
			if(temp[i][j])
			{
				maxdic[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			if(mindic[i]>=maxdic[j]&&temp[i][mindic[i]]<=temp[j][maxdic[j]])
			{
				if(mindic[i]==maxdic[j]&&mindic[j]==maxdic[i])
				continue;
				ans[i]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d",ans[i]);
	
	return 0;
}
