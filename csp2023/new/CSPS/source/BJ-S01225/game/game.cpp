#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	int n;
	int ans=0;
	
	cin>>n;
	
	char a[n];
	
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	
	while(n>1){
		for(int i=0;i<=n-1;i++){
			if(a[i]==a[i+1]){
				ans+=1;
				n-=2;
				for(int j=i;j<=n-1;j++){
					a[j]=a[j+2];
				}
			}
		}
	}
	
	ans+=1;
	
	cout<<ans;
	
	return 0;
}