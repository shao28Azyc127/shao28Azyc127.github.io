#include<bits/stdc++.h>
using namespace std;
int a[100005];//¾àÀë
int b[100005];//ÓÍ¼Û
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,i,min=0,ans;
	cin>>n>>d;
	ans=0;
	for(i=1;i<=n-1;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	min=b[1];
	for(i=1;i<=n;i++){
		if(b[i]<min)
			min=b[i];
		if(a[i]%d==0)
			ans+=(a[i]/d)*min;
		else
			ans+=((a[i]/d)+1)*min;
	}
	cout<<ans;
	return 0;
}
