#include<bits/stdc++.h>
using namespace std;
int x[1000000],y[10000000],z[10000000];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out,"w",stdout);
	cin>>n;
	while(n&&++i){
		if(n&3==1&&!p){
			p=i;
		}
		n-=(n+2)/3;
	}
	cout<<i<<" "<<p<<endl;
	return 0;
}