#include<bits/stdc++.h>
using namespace std;
string s;
bool chk(int l,int r){
	string t=s.substr(l,r-l+1);
	while(t.size()){
		bool f=1;
		for(int i=0; i<(int)t.size()-1; i++){
			if(t[i]==t[i+1]){
				t.erase(i,2); f=0; break;
			}
		}
		if(f) return 0;
	}
	return 1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,ans=0;
	cin>>n>>s;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(chk(i,j)) ans++;
		}
	}
	cout<<ans;
	return 0;
}
