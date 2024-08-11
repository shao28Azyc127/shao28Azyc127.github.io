#include<iostream>
using namespace std;
int dis[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,cheap=1e9,driven=0;
	long long ans=0;
	cin>>n>>d;
	for(int i=2;i<=n;i++)	cin>>dis[i];
	for(int i=1,x;i<n;i++)
	{
		cin>>x;
		cheap=min(cheap,x);
		int need=(dis[i+1]-driven+d-1)/d;
		need=max(need,0);
//		cout<<"buy "<<need<<" liters of oil at price "<<cheap<<endl;
		driven=driven+need*d-dis[i+1];
//		cout<<"now left:"<<driven<<endl;
		ans+=1ll*need*cheap;
	}
	cout<<ans<<endl;
}