#include <bits/stdc++.h>
#define maxn 2000005
using namespace std;

char a[maxn];

int dfs(int n,int i,int j)
{
	if(i == j-1 && a[i] == a[j])
	{
		return 1;
	}
	if(j <= i)
	{
		return 0;
	}
	if((j-i)%2 == 1 && a[i] == a[j])
	{
		return dfs(n,i+1,j)+dfs(n,i,j-1);
	}
	return dfs(n,i+1,j)-dfs(n,i+1,j-1)+dfs(n,i,j-1);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << dfs(n,1,n)+1;
	return 0;
}
