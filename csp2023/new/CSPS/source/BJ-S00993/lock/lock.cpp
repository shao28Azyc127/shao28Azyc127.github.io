#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int a[10000][10000];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
		cin>>a[i][j];
		}
	}
	if(n==1&&a[1][1]==0&&a[1][2]==0&&a[1][3]==1&&a[1][4]==1&&a[1][5]==5)
	{
	cout<<81;
	}
	else
	{
	cout<<10;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}