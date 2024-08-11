#include<iostream>
using namespace std;
int n,a[10][6],num[6],ans=0,q=0;
int flag,M;
bool flag2=0;
void solve()
{
	for(int i=0;i<=99999;i++)
	{
		num[1]=i/10000;
		num[2]=(i/1000)%10;
		num[3]=(i/100)%10;
		num[4]=(i/10)%10;
		num[5]=i%10;
		//cout<<"circles"<<num[1]<<num[2]<<num[3]<<num[4]<<num[5]<<" "<<ans<<endl;
		flag=0,flag2=0,M=3,q=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=5;k++)
			{
				if(a[j][k]!=num[k])flag++;
				if(flag>=M)break;
				if(k>1)
				{
					if(a[j][k-1]!=num[k-1]&&a[j][k]==num[k])M--;
					if(a[j][k-1]!=num[k-1]&&a[j][k]!=num[k])
					{
						if(a[j][k]==a[j][k-1])flag2=1;
					}
				}
			}
			if(flag>=M)break;
			if(flag2||flag<=1)q++;
			flag=0,M=3,flag2=0;
		}
		//cout<<flag<<" "<<flag2<<" "<<M<<" "<<q<<endl;
		if(flag>=M)continue;
		//cout<<q<<endl;
		if(q==n)ans++;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("r","lock.in",stdin);
	freopen("w","lock.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	}
	if(n==1)
	{
		cout<<81;
	}
	else
	{
		solve();
	}
	return 0;
}
