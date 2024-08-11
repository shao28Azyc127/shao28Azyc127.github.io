#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Min=INT_MAX,v[100005],a[100005],n,d;
ll f(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll Temp=0,sum=0;
	for(int i=1;i<=n;i++){
		if((v[i]-Temp)%d){
		sum+=Min*(((v[i]-Temp)/d)+1);
		Temp=d*(((v[i]-Temp)/d)+1)-v[i];
		}
		else{
			sum+=Min*((v[i]-Temp)/d);
			Temp=0;
		}
		if(a[i]<Min) Min=a[i];
	}
	return sum;
	}

int main(){
	cin>>n>>d;
	v[1]=0;
	for(int i=2;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<f();
	
	return 0;
}