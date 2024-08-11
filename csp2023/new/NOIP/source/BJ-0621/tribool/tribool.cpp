#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==3||c==4){
		for(int i=0;i<=t-1;i++){
			int n,m;
			cin>>n>>m;
			int a[n];
			for(int j=0;j<=n-1;j++){
				a[j]=0;
			}
			int ans=0;
			for(int j=0;j<=m-1;j++){
				char o;
				int aim;
				cin>>o>>aim;
				if(o=='T'){
					a[aim-1]=1;
				}
				if(o=='F'){
					a[aim-1]=0;
				}
				if(o=='U'){
					a[aim-1]=2;
				}
			}
			for(int j=0;j<=n-1;j++){
				if(a[j]==2){
					ans+=1;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	return 0;
}