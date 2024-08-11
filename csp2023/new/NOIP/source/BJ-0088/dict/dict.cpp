#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[3010][3010];
int mx[3010],mn[3010];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",c[i]+1);
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) mx[i]=max(mx[i],c[i][j]-'a'+1);
		for(int j=1;j<=m;j++) mn[i]=min(mn[i],c[i][j]-'a'+1);
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(mn[i]>=mx[j]) flag=0;
		}
		printf("%d",flag);
	}
	return 0;
}