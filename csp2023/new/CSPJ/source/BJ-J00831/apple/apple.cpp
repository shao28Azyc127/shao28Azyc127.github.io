#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ll n;cin>>n;
	ll x=0,y=0;
	ll nn=n;
	while(nn)nn-=(nn+2)/3,++x;
	nn=n;
	while(nn){
		++y;
		if((nn+2)%3==0)break;
		nn-=(nn+2)/3;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}