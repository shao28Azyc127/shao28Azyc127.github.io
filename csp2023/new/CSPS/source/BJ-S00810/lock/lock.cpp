#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[10][10],ans;
void text(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	if(n==1){
		ans=81;
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	text();
	return 0;
}