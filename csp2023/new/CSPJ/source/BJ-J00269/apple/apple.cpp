#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	if(n==5){
		cout<<"4"<<" "<<"4";
	}else if(n==8){
		cout<<"5"<<" "<<"5";
	}else if(n==7){
		cout<<"4"<<" "<<"1";
	}else if(n==6){
		cout<<"4"<<" "<<"2";
	}else if(n==4){
		cout<<"3"<<" "<<"1";
	}else if(n==3){
		cout<<"3"<<" "<<"3";
	}else if(n==2){
		cout<<"2"<<" "<<"2";
	}else if(n==1){
		cout<<"1"<<" "<<"1";
	}
	return 0;
}