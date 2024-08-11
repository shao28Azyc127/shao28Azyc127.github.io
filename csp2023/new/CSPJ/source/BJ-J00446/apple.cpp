#include<bits/stdc++.h>
using namespace std;
int n,m,ans,i;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	m=n;
	while(m>0){
		i++;
		if(ans==0&&m%3==1)ans=i;
		m-=(m-1)/3+1;
	}
	cout<<i<<' '<<ans;
	return 0;
}
