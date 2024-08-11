#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long anns;
long long kk,k,q;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int k=n;
	for(int i=1;;i++){
		if(k<=3){
			ans+=k;
			if(q==0)kk+=k;
			break;
		}
		if(k%3==0){
			k-=k/3;
			ans+=1;
			if(q==0)kk++;
		}
		if(k%3==1){
			k-=k/3+1;
			ans+=1;
			if(q==0)kk++;
			q=1;
		}
		if(k%3==2){
			k-=k/3+1;
			ans+=1;
			if(q==0)kk++;
		}
	}
	cout<<ans<<" "<<kk;
	return 0;
}