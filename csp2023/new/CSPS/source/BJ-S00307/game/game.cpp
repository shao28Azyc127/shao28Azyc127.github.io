#include <bits/stdc++.h>
using namespace std;
string f[1000005],s;
stack<char> p;
int n,cnt,k;
bool check(string s){
	while(p.size()!=0){
		p.pop();
	}
	p.push(s[0]);
	if(s[1]==p.top()){
		p.pop();
	}else{
		p.push(s[1]);
	}
	int len=s.size();
	for(int i=2;i<len;i++){
		if(p.size()!=0 && s[i]==p.top()){
			p.pop();
		}else{
			p.push(s[i]);
		}
	}
	if(p.size()==0) return true;
	else return false;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	cin>>s;
	for(int i=0;i<n;i++){
		string a="";
		for(int j=i;j<n;j++){
			a+=s[j];
			if(a.size()%2==1) continue;
			f[++k]=a;
		}
	}
	for(int i=1;i<=k;i++){
		if(check(f[i])){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
