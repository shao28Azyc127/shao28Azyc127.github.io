#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
bool flag;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>=1){
		cnt++;
		if(n%3==1&&!flag){
			ans=cnt;
			flag=true;	
		}
		if(n%3==0)
			n=n-n/3;
		else
			n=n-(n/3+1);
	}
	cout<<cnt<<" "<<ans<<endl;
	return 0;
}