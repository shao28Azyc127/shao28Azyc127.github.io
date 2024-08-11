#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,ans=0,a=0;
	cin>>n;
	char a[100010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		if(m[a[i]]%2==0&&m[a[i-1]]%2==0)
		{
			ans++;
			a=1;
		}
	}
	if(a=1)cout<<ans+1;
	else cout<<ans;
	return 0;
}
