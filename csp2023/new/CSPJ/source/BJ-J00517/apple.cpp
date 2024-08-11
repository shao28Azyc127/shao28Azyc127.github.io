#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,z,ans;
bool p=true;
inline int tf(int n){
	double k=n;
	k/=3.0;
	return ceil(k);
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>0){
		ans++;
		if(n%3==1 && p){
			z=ans;
			p=false;
		}
		n-=tf(n);
	}
	cout<<ans<<" "<<z;
	return 0;
}