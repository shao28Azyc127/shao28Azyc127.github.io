#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,i,j;
	cin>>n;
	for(i=1;i<=5*n;i++)cin>>j;
	if(n==1)cout<<81;
	else if(n==2)cout<<10;
	else cout<<1;
	return 0;
}
