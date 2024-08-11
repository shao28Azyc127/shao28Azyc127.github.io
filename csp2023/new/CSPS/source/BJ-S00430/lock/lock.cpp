#include <bits/stdc++.h>
using namespace std;

int a[20][10], now[10], pos[10], n;

int rev(int x,int y)
{
	if(x<=y)
		return y-x;
	return y-x+10;
}

bool can(int a[],int b[])
{
	int cnt=0;
	for(int i=0;i<=4;i++)
		if(a[i]!=b[i])
			pos[++cnt]=i;

	if(cnt==1)
		return true;

	if(cnt==2 && pos[1]+1==pos[2] && rev(a[pos[1]],b[pos[1]])==rev(a[pos[2]],b[pos[2]]))
		return true;

	return false;
}

bool check(int S)
{
	for(int i=0;i<=4;i++)
	{
		now[i]=S%10;
		S /= 10;
	}

	for(int i=1;i<=n;i++)
		if(!can(now,a[i]))
			return false;
	
	return true;
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);

	int ans=0;
	for(int i=0;i<=99999;i++)
		if(check(i))
			ans++;

	printf("%d\n",ans);
	return 0;
}