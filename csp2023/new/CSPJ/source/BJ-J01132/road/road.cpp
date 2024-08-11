#include<bits/stdc++.h>
using namespace std;
int fl,dst=0,n;
struct blbl{
	int p,q;
}a;
int main(){
	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	cin>>n>>a.q;
	for(int i=1;i<n;i++){
		cin>>fl;
		dst+=fl;
	}
	for(int i=1;i<=n;i++){
		cin>>fl;
		if(i==1){
			a.p=fl;
		}
	}
	if(dst%a.q==0){
		cout<<(dst/a.q)*a.p;
		return 0;
	}else{
		cout<<((dst/a.q)+1)*a.p;
		return 0;
	}
	return 0;
}
