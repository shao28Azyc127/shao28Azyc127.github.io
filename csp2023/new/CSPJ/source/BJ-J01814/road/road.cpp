#include<iostream>
#include<cmath>
using namespace std;
int n,v[100005],a[100005],d,ans=1;
float oil=0;
int cnt=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	float oil=0;
	while(ans<n)
	{
	    int k=a[ans];//now price
	    int aim=ans;
	    while(a[aim]>=k)//aim price
        {
            aim++;
            if(aim==n)break;
        }

        float lu=0;
        for(int i=ans;i<=aim-1;i++)
        {
			lu+=float(v[i]);
		}
		lu-=oil;
		
        int x=ceil(lu/float(d));//how much oil
        oil=x*d-lu;

        cnt+=x*a[ans];
        if(aim==n)break;
        else ans=aim;
	}
	cout<<cnt<<endl;
	return 0;
}
