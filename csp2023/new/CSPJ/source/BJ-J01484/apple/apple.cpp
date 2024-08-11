#include<bits/stdc++.h>
using namespace std;
struct p
{
	//long long num;
	bool f=0;
	long long day;
}arr[10000000];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	long long u=0,h=0;
	while(cnt!=n)
	{
		u++;
		h=0;
		for(long long i=1;i<=n;i++)
		{
			if(arr[i].f==0)h++;
			if(h==4)h=1;
			if(h==1&&arr[i].f==0)
			{
				arr[i].day=u;
				arr[i].f=1;
				cnt++;
			}
			//cout<<arr[i].f<<" ";
		}
		//cout<<endl;
	}
	/*for(long long i=1;i<=n;i++)
	{
		cout<<arr[i].day<<" ";
	}
	cout<<endl;
	for(long long i=1;i<=n;i++)
	{
		cout<<arr[i].f<<" ";
	}
	cout<<endl<<cnt;*/
	cout<<u<<" "<<arr[n].day;
	return 0;
}
