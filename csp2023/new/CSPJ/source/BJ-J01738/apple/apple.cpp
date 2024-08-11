#include <bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long n,ans,num,x;
struct node{
	int id;
	bool flag;
}a[N];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	num=n;
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		a[i].flag=true;
	}
	while(num!=0)
	{
		int tool=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i].flag==true)
			{
				tool++;
				if(tool==3)
				{
					a[i].flag=false;
					if(a[i].id==n) x=ans+1;
					num--;
					tool=0;
				}
			}
		}
		ans++;
	}
	cout<<ans<<" "<<x<<endl;
	return 0;
}
