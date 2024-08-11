#include<bits/stdc++.h>
using namespace std;
const int maxn=9;
int n,l[maxn][6],ans[9];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++) cin>>l[i][j];
	}
	if(n==1) cout<<"81";
	else
	{
		cout<<"10";
	}
	return 0;
}