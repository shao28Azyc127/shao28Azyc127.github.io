#include<bits/stdc++.h>
using namespace std;
int a,f,s,t;
string s;
int main(){
	freopen("game.in"."r",stdin);
	freopen("game.out","w",stdout);
	cin>>a>>s;
	for(int i=0;i<s.size()-1;i++){
		if(i>t)f=0;
		if(!f && a[i+1]==a[i]){
			s++;
			f=1;
			t=i+1;
		}
	}
	cout<<s;
	return 0;
}