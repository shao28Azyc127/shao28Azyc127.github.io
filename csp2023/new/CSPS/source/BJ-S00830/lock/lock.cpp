#include<iostream>
using namespace std;
bool ok[15][1000005];
inline void setok(int i,int a,int b,int c,int d,int e){ok[i][(a%10)*10000+(b%10)*1000+(c%10)*100+(d%10)*10+(e%10)]=1;}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		for(int del=1;del<10;del++)
		{
			setok(i,a+del,b,c,d,e);
			setok(i,a,b+del,c,d,e);
			setok(i,a,b,c+del,d,e);
			setok(i,a,b,c,d+del,e);
			setok(i,a,b,c,d,e+del);
			setok(i,a+del,b+del,c,d,e);
			setok(i,a,b+del,c+del,d,e);
			setok(i,a,b,c+del,d+del,e);
			setok(i,a,b,c,d+del,e+del);
		}
	}
	for(int i=0;i<=99999;i++)
	{
		bool flag=1;
		for(int j=0;j<n && flag;j++)
			flag&=ok[j][i];
		if(flag)
//			printf("%05d\n",i),
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}