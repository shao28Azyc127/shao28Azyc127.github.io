#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int vis[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	int n,cnt=0,ans1=0,ans2=0;
	cin>>n;
	while(cnt!=n){
		ans1++;
		int cur=0,i=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]) cur++;
			if(cur==1 && !vis[j]){
				if(j==n) ans2=ans1;
				cnt++;
				vis[j]=1;
			}
			cur%=3;
		}

	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
