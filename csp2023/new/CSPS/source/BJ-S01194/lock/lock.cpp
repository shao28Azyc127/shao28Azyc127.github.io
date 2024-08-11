#include<bits/stdc++.h>
using namespace std;
int a[15][10];
int num=1,num1,k;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=5;j++)
			cin>>a[i][j];
	if(n==1)
	cout<<81;
		return 0;
}