#include<bits/stdc++.h>
using namespace std;
int b=0;
void dfs(string s,int l){
	if(l==1) return;
	if(l==2&&s[0]==s[1]){
		b=1;
		return;
	}
	for(int i=1; i<=l-1; i++){
		if(s[i]==s[i-1]){
			string n,m,t;
			for(int j=i+1; j<=l; j++){
				n=s[j]+n;
			}
			for(int j=0; j<=i-2; j++){
				m=m+s[j];
			}
			t=m+n;
			for(int j=i-1; j<=l-3; j++){
				t[j]=t[j+1];
			}
			t[l-2]=0;
			dfs(t,l-2);
			if(b==1){
				return;
			}
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int sum=0;
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0; i<=l-1; i++){
		for(int j=i+1; j<=l-1; j++){
			string t;
			b=0;
			for(int k=i; k<=j; k++){
				t=t+s[k];
			}
			dfs(t,t.length());
			if(b==1){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}