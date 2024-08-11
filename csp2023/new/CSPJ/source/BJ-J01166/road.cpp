#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,u[1000005],a[1000005],ans;
ll s;//剩余续航里程
ll z,book,mn=1e5;
double sum,d;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(ll i=1;i<n;i++){
		scanf("%lld",&u[i]);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(mn>a[i])
			mn=a[i];
	}
	if(mn==a[1]){
		for(ll i=1;i<n;i++){
			sum+=u[i];
		}
		cout<<ceil(sum/d)*a[1];
		return 0;
	}
	
	for(ll i=1;i<=n;i++){
//		if(s<u[i]){//到不了，要加油
			for(ll j=i;j<=n;j++){//加多少
				if(a[i]>a[j]){//下一个更便宜的加油站
					for(ll k=i;k<j;k++){
						sum+=u[k];//加sum公里的油
					}
					z=j;
					book=1;
					break;
				}
			}
			
//		}
		if(s!=0){
			sum-=s;
		}
//		cout<<i<<" "<<ceil(sum/d)<<" "<<sum<<endl;
		if(sum>0){
			ans+=ceil(sum/d)*a[i];
			s+=ceil(sum/d)*d;
			s-=sum;
		}
		if(book==1){
			i=z-1;
		}
		book=0;
		sum=0;
	}
	cout<<ans;
	return 0;
}
