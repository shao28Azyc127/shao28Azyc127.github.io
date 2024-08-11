#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long v[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	long long x=1,y=1;
	long long ans=0,tmp=0,sum=0;
	while(x<n){
		y=x+1;
		while(y<=n+1){
			if(a[y]<a[x]){
				tmp=0;
				for(int i=x;i<y;i++) tmp+=v[i];
				tmp=tmp-sum;
				sum=0;
				if(tmp%d==0) ans+=(tmp/d*a[x]);
				else{
					ans+=((tmp/d+1)*a[x]);
					sum=((tmp/d+1)*d)-tmp;
				}
				x=y;
				break;
			}
			y++;
		}
	}
	cout<<ans;
	return 0;
}
