#include <bits/stdc++.h>
using namespace std;

const int N=3005;

int cnt[N][30],id[N],n,m;
char s[N],t[N];

bool cmp(int x,int y)
{
	for(int i=25;i>=0;i--)
		if(cnt[x][i]!=cnt[y][i])
			return cnt[x][i]<cnt[y][i];

	return x<y;
}

bool sma()
{
	for(int i=1;i<=m;i++)
	{
		if(t[i]<s[i])
			return true;
		if(s[i]<t[i])
			return false;
	}
	return false;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	if(n==1)
	{
		printf("1\n");
		return 0;
	}

	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			cnt[i][s[j]-'a']++;
	}

	for(int i=1;i<=n;i++)
		id[i]=i;

	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x;
		if(id[1]==i)
			x=id[2];
		else
			x=id[1];

		int lens=0;
		for(int j=25;j>=0;j--)
		{
			for(int k=1;k<=cnt[x][j];k++)
				s[++lens]=j+'a';
		}

		int lent=0;
		for(int j=0;j<=25;j++)
		{
			for(int k=1;k<=cnt[i][j];k++)
				t[++lent]=j+'a';
		}

		if(sma())
			printf("1");
		else
			printf("0");
	}
	return 0;
}