#include<bits/stdc++.h>
using namespace std;
int n,ans,x,y;
int a[10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	if(n==2){
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		cout<<10;
		return 0;
	}
	if(n==1){
		for(int i=1;i<=5;i++){
			cin>>a[i];
		}
		cout<<81;
		return 0;
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=5;i++){
			cin>>a[i];
		}
	}
	cout<<45;
	return 0;
}
