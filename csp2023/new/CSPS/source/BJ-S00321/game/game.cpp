#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ans=0;
string game;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>game;
	for(int i=0;i<n-1;i++){
		string s;
		for(int j=i+2;j<=n;j+=2){
			s+=game[j-2]; s+=game[j-1];
			stack<char> t;
			for(int k=0;k<j-i;k++){
				if(!t.empty()&&t.top()==s[k]) t.pop();
				else t.push(s[k]);
			}
			ans+=t.empty();
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
