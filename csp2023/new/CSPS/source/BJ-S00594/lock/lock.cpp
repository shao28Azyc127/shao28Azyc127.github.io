#include<iostream>
using namespace std;

bool pos[9][100000];
struct password{
	int val[6];
}pass[10];
int connect(password p)
{
	int ret=0;
	for(int i=1;i<=5;i++)
	{	
		ret*=10;
		ret+=p.val[i];
	}
	return ret;
}
void printpass(password p)
{
	for(int i=1;i<=5;i++)
	{
		cout << p.val[i] << " ";
	}
	cout << endl;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin >> pass[i].val[j];
		}
	}
	//cout << endl;
	for(int i=1;i<=n;i++)
	{
		password tmp=pass[i];
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=9;k++)
			{
				password now=tmp;
				now.val[j]=(now.val[j]+k)%10;
				//printpass(now);
				pos[i][connect(now)]=1;
			}
		}
		for(int j=1;j<=4;j++)
		{
			for(int k=1;k<=9;k++)
			{
				password now=tmp;
				now.val[j]=(now.val[j]+k)%10;
				now.val[j+1]=(now.val[j+1]+k)%10;
				//printpass(now);
				pos[i][connect(now)]=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=99999;i++)
	{
		bool tmp=1;
		for(int j=1;j<=n;j++)
		{
			tmp&=pos[j][i];
		}
		//if(tmp)cout << i << " ";
		ans+=tmp;
	}
	cout << ans;
}
