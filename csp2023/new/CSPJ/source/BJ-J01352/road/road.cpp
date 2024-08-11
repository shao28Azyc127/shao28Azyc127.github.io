#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
long long a[100010],v[100010],n,d,i,ans=0,minn=1000000,shengyu=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld",&n,&d);
	for(i=1;i<n;i++)
	{
		scanf("%lld",&v[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		bool flagg=1;
		if(v[i]-shengyu<=0)
		{
			shengyu-=v[i];
			flagg=0;
		}
		minn=min(minn,a[i]);
		if((v[i]-shengyu)%d==0&&flagg)
		{
			ans+=(v[i]-shengyu)/d*minn;
			shengyu=0;
		}
		else if(flagg)
		{
			ans+=((v[i]-shengyu)/d+1)*minn;
			shengyu=((v[i]-shengyu)/d+1)*d+shengyu-v[i];
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
