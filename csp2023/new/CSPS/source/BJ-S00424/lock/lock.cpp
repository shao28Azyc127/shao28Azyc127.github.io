#include <bits/stdc++.h>
using namespace std;
int a[15][10],na[10],nb[10],ans=0,n;
bool isok(int n1,int n2,int n3,int n4)
{	
	if(n1<n2)
		n1=10+n1;
	if(n3<n4)
		n3=10+n3;
	return (n1-n2)==(n3-n4);
}
bool b(int n1,int n2,int n3,int n4,int n5)
{
	int cnt=0;
	na[1]=n1;na[2]=n2;na[3]=n3;na[4]=n4;na[5]=n5;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=5;j++)
			if(a[i][j]!=na[j])
				nb[++cnt]=j;
		if(cnt>2||cnt==0)
			return 0;
		if(cnt==2&&(nb[2]-nb[1]!=1||!isok(na[nb[1]],a[i][nb[1]],na[nb[2]],a[i][nb[2]])))
			return 0;
	}
	return 1;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=9;k++)
				for(int l=0;l<=9;l++)
					for(int m=0;m<=9;m++)
						if(b(i,j,k,l,m))
							ans++;
	cout<<ans;
	return 0;
}