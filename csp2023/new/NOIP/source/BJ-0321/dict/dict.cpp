#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=3e3,M=3e3;
int n,m;
char s[N+1][M+1],smax[N+1][M+1],smin[N+1][M+1];
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	bool flag;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		strcpy(smax[i],s[i]);
		sort(smax[i],smax[i]+m,cmp);
		strcpy(smin[i],s[i]);
		sort(smin[i],smin[i]+m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			if(strcmp(smin[i],smax[j])>0)
				break;
		}
		if(j<=n)
			printf("0");
		else
			printf("1");
	}
	return 0;
}