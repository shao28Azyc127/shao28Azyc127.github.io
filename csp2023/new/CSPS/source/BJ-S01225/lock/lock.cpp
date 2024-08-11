#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	int n;
	int diff=0;
	
	cin>>n;
	
	int a[n][5];
	
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=4;j++){
			cin>>a[i][j];
		}
	}
	
	if(n==2){
		for(int i=0;i<=4;i++){
			if(a[0][i]!=a[1][i]){
				diff+=1;
			}
		}
	}

	if(n==1){
		cout<<81;
		return 0;
	}
	if(n==2&&diff==1){
		cout<<10;
		return 0;
	}
}