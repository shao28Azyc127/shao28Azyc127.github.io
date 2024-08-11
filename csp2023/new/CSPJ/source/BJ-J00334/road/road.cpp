#include<bits/stdc++.h>
using namespace std;
int a[100001],k[100001],a1[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,d,lch=0,ans=0;
	cin>>n>>d;
	for(int i=1; i<=n-1; i++){
		cin>>k[i];
		lch+=k[i];
	}
	for(int i=1; i<=n; i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	sort(a1+1,a1+n+1);
	if(a1[1]==a[1]){
		cout<<lch/d*a[1];
	}
	else{
		for(int i=1; i<=n; i++){
			ans+=k[i]/d*a[i];
		}
		cout<<ans;
	}
	return 0;
}
