#include <iostream>
using namespace std;
int n,d;
int w[100005];
int v[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	w[n]=0;
	for(int i=1;i<n;i++)
	{
		 cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	int minx=1e9;
	long long cost=0;
	long long re=0;
	long long temp;
	for(int i=1;i<n;i++)
	{
		minx=min(minx,v[i]);
		if(re>=w[i])
		{
			re-=w[i];
		}
		else
		{
			temp=(w[i]-re+(d-1))/d;
			cost+=temp*minx;
			re=(re+temp*d)-w[i];
		}
	}
	cout<<cost<<endl;
	return 0;
}
