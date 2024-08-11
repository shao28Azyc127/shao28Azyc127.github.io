#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
int s[15][15][15][15][15];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		s[a][b][c][d][e]=-inf;
		for(int i=0;i<10;i++)
		{
			s[i][b][c][d][e]++;
			s[a][i][c][d][e]++;
			s[a][b][i][d][e]++;
			s[a][b][c][i][e]++;
			s[a][b][c][d][i]++;
		}
		for(int i=0;i<10;i++)
		{
			s[(a+i)%10][(b+i)%10][c][d][e]++;
			s[a][(b+i)%10][(c+i)%10][d][e]++;
			s[a][b][(c+i)%10][(d+i)%10][e]++;
			s[a][b][c][(d+i)%10][(e+i)%10]++;
		}
	}
	int ans=0;
	for(int i=0;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++) for(int l=0;l<10;l++) for(int r=0;r<10;r++)
	{
		if(s[i][j][k][l][r]==n) ans++;
	}
	printf("%d\n",ans);
	return 0;
}