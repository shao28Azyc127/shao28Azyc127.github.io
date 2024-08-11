#include <bits/stdc++.h>
using namespace std;
int a[10][7], n;
bool t11(){
	bool t=0;
	for(int i = 1; i <= 5; i++){
		bool tx=0;
		for(int j = 2; j <= n; j++){	
			if(a[j][i]!=a[j-1][i]){
				tx=1;
			}
		}
		if(tx&&t){
		//	cout<<i<<endl;
			return 0;
		}
		if(tx){
			//cout<<i<<endl;
			t=1;
		}
	}
	return t;
}
bool t22(){
	bool t=0;
	for(int i = 1; i <= 4; i++){
		bool tx=0;
		int x=a[1][i]-a[1][i+1];
		if(a[1][i+1]==0){
			x=a[1][i]-10;
		}
		for(int j = 2; j <= n; j++){
			bool t2=0;
			int x2=a[j][i]-a[j][i+1], x3=10;
			if(a[j][i+1]==0){
				x2=(a[j][i]-1)-9;
				x3=(a[j][i]+1)%10-1;
			}
			if(a[j][i]!=a[j-1][i]&&a[j][i+1]!=a[j-1][i+1]){
				if(x2==x||x3==x){
					tx=1;
				}
				else{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		if(tx&&t){
			cout<<i<<endl;
			return 0;
		}
		if(tx){
			t=1;
		}
	}
	return t;
}
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin>>n;
	if(n==1){
		cout<<81;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 5; j++){
			cin>>a[i][j];
		}
	}
	bool t1=t11(), t2=t22();
	if(!t1&&!t2){
		cout<<0;
	}
	else{
		cout<<10-n;
	}
return 0;
}