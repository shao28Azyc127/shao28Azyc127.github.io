#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+5;
int l[N],a[N],ans,sum,mi=1000000;
int main(){
    // freopen("road.in","r",stdin);
    // freopen("road.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<n;i++){
		cin>>l[i];
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		mi=min(a[i],mi);
		if (sum<l[i]){
			for (int j=i;j<=n;j++){
				
			}
			ans+=mi*((l[i]-sum)/k+(l[i]%k!=0));
			sum=k*((l[i]-sum)/k+(l[i]%k!=0))-(l[i]-sum);
			cout<<i<<endl;
		}
		else
			sum-=l[i];
	}
	cout<<ans;
	return 0;
}
