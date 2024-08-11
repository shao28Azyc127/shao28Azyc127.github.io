#include<iostream>
using namespace std;
bool f[1000000001];	int n;
bool check(){
	for(int i=1;i<=n;i++){
		if(!f[i]) return true;
	}
	return false;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int ans1,ans2;
	ans1=ans2=0;
	cin>>n;
	while(check()){
		int cnt=2;
		for(int i=1;i<=n;i++){ 
			if(cnt==2&&!f[i]){
				f[i]=true;
				cnt=0;
				if(i==n){
					ans2=ans1+1;
				}
			}
			else if(!f[i]){
				cnt++;
			}
		}
		ans1++;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
