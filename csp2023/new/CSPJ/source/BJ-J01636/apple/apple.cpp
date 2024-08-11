#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],ans,day,ok,j=1;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	while(ok!=n){
		day++;
		j=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				continue;
			}
			if(a[i]&&j%3==1){
				ok++;
				if(a[i]==n) ans=day;
				a[i]=0;
			}
			j++;
		}
		
	}
	cout<<day<<" "<<ans;
	

	return 0;
}

