#include <bits/stdc++.h>
using namespace std;

int n;
//int a[1000003];

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int ans=3;
	if(n<=3)
	{
        cout<<n<<" "<<n;
        return 0;
	}
	//a[1]=1,a[2]=2,a[3]=3;
	int j=3;
	for(int i=5;i<=n;i+=j)
	{
         ans++;
         j++;
	}
	cout<<ans;
    if((n-1)%3==0)
    {
        cout<<" 1";
        return 0;
    }
	return 0;
}
