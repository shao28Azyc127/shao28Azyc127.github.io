#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
int ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;n;i++){
		if(n%3==1&&!ans)ans=i;
		int take=(n+2)/3;
		n-=take;
		cnt++;
	}
	cout<<cnt<<" "<<ans<<endl;
}