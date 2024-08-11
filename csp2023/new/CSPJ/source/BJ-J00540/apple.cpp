#include <iostream>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,m,ans=0,answ=0,cnt;
	cin>>n;
	m=n;
	while(n>0){
		ans++;
		n-=1;
		n-=n/3;
	}
	n=m;
	while(n>0){
		answ++;
		if(n%3==1){
			break;
		}
		n-=1;
		n-=n/3;
	}
	cnt=answ;
	cout<<ans<<" "<<cnt;
	return 0;
}
