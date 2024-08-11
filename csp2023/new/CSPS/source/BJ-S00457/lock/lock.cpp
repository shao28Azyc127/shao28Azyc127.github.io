#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[11][11],t=1,m=1,k=0,ans=0;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,x;
	cin >>n;
	while(t<=n){
		for(int i=1;i<=5;i++){
			cin >>x;
			a[t][i]=x;
		}
		t++;
	}
	if(n==1){
		cout<<81;
	}
	else if(n==2){
		for(int i=1;i<=5;i++){
			//cout<<a[1][i]<<" "<<a[2][i]<<endl;
			if(a[1][i]!=a[2][i]){
				//cout<<i<<endl;
				if(abs(a[1][i]-a[1][i+1])==abs(a[2][i]-a[2][i+1])){
					cout<<8;
				}
				else if(i==1||i==5){
					cout<<10;
				}
				else{
					cout<<12;
				}
			}
		}
	}
	else{
		for(int i=1;i<=5;i++){
			k=0;
			for(int j=2;j<=n;j++){
				if((a[j][i]==a[1][i])||(abs(a[j][i]-a[j][i+1])==abs(a[1][i]-a[1][i+1]))||(abs(a[j][i]-a[j][i-1])==abs(a[1][i]-a[1][i-1]))){
					k++;
					break;
				}
			}
			for(int j=3;j<=n;j++){
				if((a[j][i]==a[2][i])||(abs(a[j][i]-a[j][i+1])==abs(a[2][i]-a[2][i+1]))||(abs(a[j][i]-a[j][i-1])==abs(a[2][i]-a[2][i-1]))){
					k++;
					break;
				}
			}
			if(k==0){
				cout<<10-n;
				ans=1;
				break;
			}
		}
		if(ans==0){
			cout<<1;
		}
	}
	return 0;
}
