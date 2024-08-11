#include<bits/stdc++.h>
using namespace std;
int n;
int d;
int a[100005];
int v[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int sy=0;
	for(int i=1;i<=n;i++){
		int l=0;
		int i2=0;
		bool f=true;
		for(int j=i;j<=n;j++){
			if(a[i]<=a[j] || f==true){
				l+=v[i];
			}
			else{
				i2=j;
				f=false;
			}
		}
		if(i2>i){
			i=i2;
		}
		else if(f==true){
			i=n;
		}
		if((l-sy)%d==0){
			ans+=(l-sy)/d*a[i];
			sy=0;
		}
		else{
			ans+=((l-sy)/d+1)*a[i];
			sy=(l-sy)%d;
			}
	}
	cout<<ans;
	return 0;
}
