#include<bits/stdc++.h>
using namespace std;
char a[2000005];
stack<char> sta;
inline bool chk(int l,int r){
	while(!sta.empty()) sta.pop();
	for(int i=l;i<=r;i++){
		if(sta.empty()) sta.push(a[i]);
		else{
			if(a[i]==sta.top()) sta.pop();
			else sta.push(a[i]);
		}
	}
	if(!sta.empty()) return 0;
	else return 1;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>8000){
		long long ans=0;
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
				if(i>=2&&i<=n-2){
					if(a[i-1]==a[i+2]) ans++;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	long long ans=0;
	for(int l=1;l<n;l++){
		for(int r=l+1;r<=n;r++){
			if(r==l+1&&a[l]==a[r]) ans++;
			else if(chk(l,r)) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

