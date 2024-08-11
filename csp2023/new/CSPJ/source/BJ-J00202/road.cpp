#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],s[N],x[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,minn=1e9,ans=0;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<minn||i==n){
			minn=a[i];
			k++;
			x[k]=i;
		}
	}int kkm=0;
	for(int i=1;i<k;i++){
		ans+=(s[x[i+1]-1]-s[x[i]-1]-kkm+d-1)/d*a[x[i]];
		kkm=(s[x[i+1]-1]-s[x[i]-1]-kkm)%d;
	}cout<<ans;
	return 0;
}
