#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int a[100005];
int v[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,w=1,ans=0,need;
	double d,left=0;
	cin>>n>>d;
	v[1]=0;
	for(i=2;i<=n;i++){
		cin>>v[i];
		v[i]=v[i]+v[i-1];
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	while(w!=n){
		for(i=w+1;i<=n;i++){
			if(i==n){
				ans+=a[w]*ceil((v[i]-v[w])/d-left);
				w=i;
				break;
			}
			if(a[i]<a[w]){
				ans+=a[w]*ceil((v[i]-v[w])/d-left);
				left=ceil((v[i]-v[w])/d-left)-((v[i]-v[w])/d-left);
				w=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

