#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,d,v[100005],a[100005],mnwz,mn=1e9,sum;
double y[100005],sy;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>a[i];
		if(mn>a[i]){
			mn=a[i];
			mnwz=i;
		}
		y[mnwz]+=(double)v[i]/(double)d;
	}
	for(int i=1;i<=n-1;i++){
		double t=min(y[i]-sy,y[i]);
		sum+=ceil(t)*a[i];
		sy=sy-(y[i]-t)+(ceil(t)-t);
	}
	cout<<sum;
	return 0;
}
