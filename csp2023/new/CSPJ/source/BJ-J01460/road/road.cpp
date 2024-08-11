#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a[MAXN],v[MAXN];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,i,sum=0;
	scanf("%d%d",&n,&d);
	for(i=1;i<n;++i){
		scanf("%d",&v[i]);
		sum+=v[i];
	}
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(sum%d==0)
		cout<<(sum/d)*a[1]<<endl;
	else
		cout<<(sum/d)*a[1]+1<<endl;
	return 0;
}
