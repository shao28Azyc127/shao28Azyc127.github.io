#include <bits/stdc++.h>
using namespace std;

const int N=2005;

bool can[N][N];
int a[N],b[N],olda[N],oldb[N],n,m;

bool work()
{
	if(a[1]>b[1])
	{
		memset(can,0,sizeof(can));
		can[0][0]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i]>b[j])
					can[i][j]=can[i-1][j]|can[i][j-1]|can[i-1][j-1];
		return can[n][m];
	}
	else if(a[1]<b[1])
	{

		memset(can,0,sizeof(can));
		can[0][0]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i]<b[j])
					can[i][j]=can[i-1][j]|can[i][j-1]|can[i-1][j-1];
		return can[n][m];
	}
	else
		return false;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,q;
	scanf("%d %d %d %d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&olda[i]);

	for(int i=1;i<=m;i++)
		scanf("%d",&oldb[i]);

	memcpy(a,olda,sizeof(olda));
	memcpy(b,oldb,sizeof(oldb));
	printf("%d",work());
	for(int i=1;i<=q;i++)
	{
		int kx,ky;
		scanf("%d %d",&kx,&ky);
		memcpy(a,olda,sizeof(olda));
		memcpy(b,oldb,sizeof(oldb));
		for(int i=1;i<=kx;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			a[x]=y;
		}

		for(int i=1;i<=ky;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			b[x]=y;
		}

		printf("%d",work());
	}
	printf("\n");
	return 0;
}