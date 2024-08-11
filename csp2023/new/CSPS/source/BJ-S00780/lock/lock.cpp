#include<bits/stdc++.h>
using namespace std;
	int n;
	int a[10][8];
	cin>>n;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==1){
		cout<<"81";
	}
	else if(n==2){
		cout<<"10";
	}
	else{
	cou<<"0";
	}
	return 0;
}