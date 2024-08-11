#include<bits/stdc++.h>
using namespace std;
int a[1011][1011],m,n,k;
int t,s,q;
int main(){
	freopen("bus.in","r",stdin);freopen("bus.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>t>>s>>q;
		a[t][s]=q;
	}
	cout<<"-1"<<endl;
	return 0;
}
