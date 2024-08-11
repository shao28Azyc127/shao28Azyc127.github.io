#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ll in;
	int ans,ans2;
	bool flag=false;
	cin>>in;
	for(ans=1;in;ans++)
	{
		if((in-1)%3==0&&!flag)
		{
			ans2=ans;
			flag=true;
		}
		in-=(in-1)/3+1;
	}
	cout<<ans-1<<' '<<ans2<<endl;
    return 0;
}
