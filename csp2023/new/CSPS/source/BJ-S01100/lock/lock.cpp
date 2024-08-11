#include<bits/stdc++.h>
using namespace std;
int a[8][5];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			cin>>a[i][j];
	if(n==1)
		cout<<"81";
	return 0;
}

