#include <iostream>
using namespace std;
const int N=10;
int n,ans,cnt;
int a[N][10];
bool flag[10];
void clean(bool array[],int length)
{
	for(int i=1;i<=length;i++)
	{
		array[i]=false;
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	if(n==1) cout<<"81"<<endl;
	else
	{
		for(int i=1;i<=5;i++)
		{
			int max_x=0,min_x=11;
			int cnt=0;
			clean(flag,10);
			for(int j=1;j<=n;j++)
			{
				max_x=max(max_x,a[j][i]);
				min_x=min(min_x,a[j][i]);
				if(flag[a[j][i]]==false)
				{
					flag[a[j][i]]=true;
					cnt++;
				}
			}
			if(max_x!=min_x)
			{
				ans+=10-cnt;
				if(i==5 || i==1) ans+=2;
				else ans+=4;
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}
