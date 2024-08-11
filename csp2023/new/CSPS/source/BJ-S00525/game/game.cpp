#include <bits/stdc++.h>
using namespace std;
string s;
int n;

bool check(string x,int l,int r){
	string t=x;
	for(int i=0;i<=r-l+1;i++){
		for(int j=0;j<r-l+1;j++){
			if(t.empty()) break;
			if(t[j]==t[j-1]){
				t.erase(j-1,2);
			}
		}
	}
	if(t.empty()){
		return true;
	}else{
		return false;
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	int cnt=0;
	int l=0,r=n;
	while(l<=r&&r>0){
		r--;
		if(r-l<=0){
			r=n;
			l++;
			continue;
		}
		string x="";
		for(int i=l;i<=r;i++){
			x.push_back(s[i]);
		}
		if(check(x,l,r)){
			cnt++;
		}
		
	}
	cout<<cnt;
	return 0;
}
