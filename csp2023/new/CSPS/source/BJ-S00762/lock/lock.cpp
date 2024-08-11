#include<iostream>
#include<cstdio>
using namespace std;
int a[15][6],cnt,am=0,ck[15],cod=0;
int n;
void check(){
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= 5;j++){
			if(a[i][j]!=a[i-1][j] &&(a[i][j]!=a[i-2][j] || i==2)){
				am++;
				ck[i]=j;
				if(a[i][j]==a[i-1][j]+1 || a[i][j]==a[i-1][j]-1){
					cod=1;
				}
			}
		}
	}
	if(am==0) cout<<81;
	if(am==1){
		if(cod==1){
			cout<<8;
		}
		else{
			cout<<8+2;
		}
	}else if(am>=2){
		for(int i = 3;i <= n;i++){
			if(ck[i]!=ck[i-1]){
				cout<<0;
				return ;
			}
		}
		cout<<10-n;
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 5;j++){
			cin>>a[i][j];
		}
		if(n==1){
			cout<<5*9+9*4;
			return 0;
		}
	}
	check();
	return 0;
}
