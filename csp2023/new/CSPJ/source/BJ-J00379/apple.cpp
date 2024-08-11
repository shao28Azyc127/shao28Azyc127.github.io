#include<bits/stdc++.h>
using namespace std;

int n,ans=1,m,num=1;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	m=n;
	while(n>1){
		n=n*2/3;
		ans++;
	}
	cout<<ans<<" ";
	while(m%3!=1){
		m=m*2/3;
		num++;
	}
	cout<<num;
}
