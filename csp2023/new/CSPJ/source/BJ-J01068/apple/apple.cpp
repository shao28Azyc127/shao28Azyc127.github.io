#include<iostream>
#include<list>
using namespace std;
#define ll long long
ll n;
list<ll> q;
ll ans;
ll cnt=0;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		q.push_back(i);
	}
	while(!q.empty())
	{
		cnt++;
		for(list<ll>::iterator it=q.begin();it!=q.end();)
		{
			if((*it)==n)
			{
				ans=cnt;
			}
			it=q.erase(it);
			if(it!=q.end())
			{
				it++;
			}
			else
			{
				break;
			}
			if(it!=q.end())
			{
				it++;
			}
			else
			{
				break;
			}
		}
	}
	cout<<cnt<<' '<<ans;
	return 0;
}
