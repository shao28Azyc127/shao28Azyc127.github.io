#include<iostream>
using namespace std;
int n,ans;
string s;
int dg(string s){
	if(s==""){
		return 1;
	}
	if(s.size()&1){
		return 0;
	}
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=s[i+1]){
			continue;
		}
		string t;
		for(int j=0;j<s.size();j++){
			if(j!=i&&j!=i+1){
				t+=s[j];
			}
		}
		if(dg(t)){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=s.size()-i+1;j++){
			ans+=dg(s.substr(i-1,j));
		}
	}
	cout<<ans;
	return 0;
}
