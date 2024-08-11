#include<iostream>
using namespace std;
const int N=2e5+5;
int a[N],v[N];
int up(int x,int y){
	if(x%y==0)	return x/y;
	return x/y+1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ds=0,ans=0;
	for(int i=1;i<=n;){
		int j=i+1,dis=0;
		for(j=i+1;j<=n;j++){
			dis+=v[j-1];
			if(a[j]<a[i])	break;
		}
		int num=up(dis-ds,d);
		ans+=a[i]*num;
		ds=num*d+ds-dis;
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}