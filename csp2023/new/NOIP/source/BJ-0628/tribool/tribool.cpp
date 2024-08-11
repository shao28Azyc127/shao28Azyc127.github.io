#include <bits/stdc++.h>
using namespace std;
char a[1005];
int b[10005];
int e[10005];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int n,m,k,q,i,j,c,t,cnt=0;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		if(m==3)
		for(i=1;i<=m;i++)
			cin>>a[i]>>b[i]>>e[i];
		if(m==2)
		for(i=1;i<=m;i++)
			cin>>a[i]>>b[i];
		for(i=1;i<=m;i++)
			if(a[i]=='T'&&b[i]==b[i+1]&&a[i+1]=='U')
			cnt=m-1;
	}
	for(i=1;i<=t;i++)
	cout<<0<<endl;
	return 0;
}
	
	
