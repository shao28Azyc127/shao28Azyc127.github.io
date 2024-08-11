#include<bits/stdc++.h>
using namespace std;
int n,d,l,r,R,po=1,you;
long long ans;
int v[100005],a[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		l+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(r!=l){
		R=r;
		for(int i=po;i<=n;i++){
			r+=v[i-1];
			if(a[i]>=a[po]&&i!=n)continue;
			int now=you;
			you=0;
			if((r-R-now)%d==0) ans+=(r-R-now)/d*a[po];
			else {
				//((r-R)/d+1)*d-(r-R)
				you+=((r-R-now)/d+1)*d-(r-R-now);
				ans+=((r-R-now)/d+1)*a[po];
				//cout<<now<<" "<<po<<" "<<r-R-now<<" "<<(r-R-now)/d+1<<"R"<<endl;
			}
			po=i;
			R=r;
		}
	}
	cout<<ans<<endl;
	return 0;
}