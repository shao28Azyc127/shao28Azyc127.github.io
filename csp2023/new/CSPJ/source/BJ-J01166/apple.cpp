#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,num,sam=1,ans,a[10000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	k=n;
	while(k>0){
		for(ll i=1;i<=n;i++){
			if(a[i]==0){
				num++;
				if(num%3==1){
					a[i]=1;
					k--;
					if(i==n){
						ans=sam;
					}
				}
			}
		}
		num=0;
		sam++;
	}
	cout<<sam-1<<" "<<ans;
	return 0;
}