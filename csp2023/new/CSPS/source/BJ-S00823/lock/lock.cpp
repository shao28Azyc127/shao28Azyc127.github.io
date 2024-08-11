#include <bits/stdc++.h>
using namespace std;
int a[10][10],b[10],ans,n;
bool check(int c1,int c2,int c3,int c4,int c5)
{
	for(int i=2;i<=n;i++)
	{
		bool f1=(a[i][1]!=c1),f2=(a[i][2]!=c2),f3=(a[i][3]!=c3),f4=(a[i][4]!=c4),f5=(a[i][5]!=c5);
		int x1=(c1-a[i][1]+10)%10,x2=(c2-a[i][2]+10)%10,x3=(c3-a[i][3]+10)%10,x4=(c4-a[i][4]+10)%10,x5=(c5-a[i][5]+10)%10;
		bool f6=f1&&f2&&(x1==x2),f7=f2&&f3&&(x2==x3),f8=f3&&f4&&(x3==x4),f9=f4&&f5&&(x4==x5);
		if((f1+f2+f3+f4+f5)>2)
			return false;
		if((f1+f2+f3+f4+f5)==2&&(!(f6||f7||f8||f9)))
			return false;
		if((f1+f2+f3+f4+f5)==0)
			return false;
	}
	return true;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	for(i=1;i<=5;i++)
	{
		b[1]=a[1][1];
		b[2]=a[1][2];
		b[3]=a[1][3];
		b[4]=a[1][4];
		b[5]=a[1][5];
		for(j=1;j<=9;j++)
		{
			b[i]=(b[i]+1)%10;
			if(check(b[1],b[2],b[3],b[4],b[5]))
				ans++;
		}
	}
	for(i=1;i<5;i++)
	{
		b[1]=a[1][1];
		b[2]=a[1][2];
		b[3]=a[1][3];
		b[4]=a[1][4];
		b[5]=a[1][5];
		for(j=1;j<=9;j++)
		{
			b[i]=(b[i]+1)%10;
			b[i+1]=(b[i+1]+1)%10;
			if(check(b[1],b[2],b[3],b[4],b[5]))
				ans++;
		}
	}
	cout<<ans;
	return 0;
}
