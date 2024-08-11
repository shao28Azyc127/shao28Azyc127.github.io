#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int a[15][15];
int vis[15][15][15][15][15];
int del[15][15];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
		for(int j=1;j<=4;j++) del[i][j]=a[i][j]-a[i][j+1];
	}
	
	for(int i=1;i<=n;i++)
	{
		
			for(int x1=0;x1<=9;x1++)
			{
				if(a[i][1]!=x1) vis[x1][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
			}
			for(int x2=0;x2<=9;x2++)
			{
				if(a[i][2]!=x2) vis[a[i][1]][x2][a[i][3]][a[i][4]][a[i][5]]++;
			}
			for(int x3=0;x3<=9;x3++)
			{
				if(a[i][3]!=x3) vis[a[i][1]][a[i][2]][x3][a[i][4]][a[i][5]]++;
			}
			for(int x4=0;x4<=9;x4++)
			{
				if(a[i][4]!=x4) vis[a[i][1]][a[i][2]][a[i][3]][x4][a[i][5]]++;
			}
			for(int x5=0;x5<=9;x5++)
			{
				if(a[i][5]!=x5) vis[a[i][1]][a[i][2]][a[i][3]][a[i][4]][x5]++;
			}
			for(int y1=0;y1<=9;y1++)
			{
				if(a[i][1]!=y1) vis[y1][(10+y1-del[i][1])%10][a[i][3]][a[i][4]][a[i][5]]++;
			}
			for(int y2=0;y2<=9;y2++)
			{
				if(a[i][2]!=y2) vis[a[i][1]][y2][(10+y2-del[i][2])%10][a[i][4]][a[i][5]]++;
			}
			for(int y3=0;y3<=9;y3++)
			{
				if(a[i][3]!=y3) vis[a[i][1]][a[i][2]][y3][(10+y3-del[i][3])%10][a[i][5]]++;
			}
			for(int y4=0;y4<=9;y4++)
			{
				if(a[i][4]!=y4) vis[a[i][1]][a[i][2]][a[i][3]][y4][(10+y4-del[i][4])%10]++;
			}
	}
	for(int o1=0;o1<=9;o1++)
	for(int o2=0;o2<=9;o2++)
	for(int o3=0;o3<=9;o3++)
	for(int o4=0;o4<=9;o4++)
	for(int o5=0;o5<=9;o5++)
	if(vis[o1][o2][o3][o4][o5]==n) 
	{
		ans++;
		//printf("%d %d %d %d %d\n",o1,o2,o3,o4,o5);
		}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
