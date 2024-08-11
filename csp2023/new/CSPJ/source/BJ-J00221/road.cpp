#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAXN 100003
int a[MAXN],v[MAXN],n,d;
long long ans=0,now=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)	cin>>v[i];
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<n;){
		int buy=1;
		long long sum=0,cost=0;
		for(;i+buy<=n;buy++)	if(a[i]>a[i+buy])	break;
		if(i+buy>n)	buy=n-i;
		for(int j=i;j<i+buy;j++)	sum+=v[j];
		if((sum-now)%d!=0)	cost=(sum-now)/d+1;
		else	cost=(sum-now)/d;
		now+=cost*d-sum;
		ans+=cost*a[i];
		i=i+buy;
	}
	cout<<ans<<endl;
	return 0;
}
