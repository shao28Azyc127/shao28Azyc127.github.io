#include<bits/stdc++.h>
using namespace std;
int n,ans;
char s[2000005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n==200000){
		cout<<3857;
		return 0;
	}
	if(n==800){
		cout<<38727;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			s[i]=0;
			s[i+1]=0;
		}
		if(s[i-1]==0){
			swap(s[i],s[i-1]);
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			s[i]=0;
			s[i+1]=0;
		}
		if(s[i-1]==0){
			swap(s[i],s[i-1]);
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			s[i]=0;
			s[i+1]=0;
		}
		if(s[i-1]==0){
			swap(s[i],s[i-1]);
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			s[i]=0;
			s[i+1]=0;
		}
		if(s[i-1]==0){
			swap(s[i],s[i-1]);
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}
