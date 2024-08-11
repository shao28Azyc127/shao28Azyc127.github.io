#include<bits/stdc++.h>
using namespace std;
long long a[10000002],b[10000002],ki[10000002]={0};
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	bool flag=true;
	long long n,k,s=0,c=0,cnt=0,kl=0,fd;
	cin>>n;
	k=n;
	while(flag)
	{
		ki[10000002]={0};
		kl=0;
		c=0;
		cnt++;
		fd=1;
		while(fd<=n)
		{
			ki[fd]=1;
			if(k==fd&&fd<=n)
			{
				k=-1;
				s=cnt;
			}
			fd=fd+3;
		}
		for(int i=1;i<=n;i++)
		{
			if(ki[i]==1)
				c+=0;
			else
			{
				c++;
				b[c]=a[i];
			}

		}
		if(k!=-1)
			k=c;
		n=c;
		for(int i=1;i<=n;i++)
			a[i]=b[i];
		if(n==0)
			flag=false;
	}
	cout<<cnt<<" "<<s<<endl;
	return 0;
}