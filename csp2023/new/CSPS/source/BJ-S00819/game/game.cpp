#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(int l,int r){
	stack<char>a;
	char t='-';
	for(int i=l;i<r;i++){
		a.push(s[i]);
		if(a.top()==t){
			a.pop();
			a.pop();
		}
		if(a.empty()) t='-';
		else t=a.top();
	}
	return a.empty();
}
void print(int l,int r){
	for(int i=l;i<r;i++){
		cout<<s[i];
	}
	cout<<endl;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	if(n>8000){
		cout<<0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(j-i,j)){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
