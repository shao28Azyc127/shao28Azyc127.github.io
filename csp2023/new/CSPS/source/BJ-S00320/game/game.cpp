#include <bits/stdc++.h>
using namespace std;
string s,t,p;
int n,sum,j,po;
bool check(){
	int len,cnt,flag=0;
	string str;
	cnt=t.length();
	while(1){
		str=t;
		len=str.length();
		t.erase();
		flag=0;
		for(int i=0;i<len-1;i++){
			if(str[i]=='7')  continue;
			if(str[i]==str[i+1]){
				cnt-=2;
				flag=1;
				str[i]=str[i+1]='7';
			}
		}
		for(int i=0;i<len;i++){
			if(str[i]!='7'){
				t+=str[i];
			}
		}
		if(cnt==0)  return true;
		if(cnt>0&&flag==0)  return false;
	}
}	
void dfs(int deep){
	t+=s[j+deep-1];
	if(deep==n-j){
		if(deep%2==0){
			p=t;
			if(check()){
				sum++;
			}
			t=p;
		}
		return;
	}
	if(deep%2==0){
		p=t;
		if(check()){
			sum++;
		}
		t=p;
		dfs(deep+1);
	}
	else{
		dfs(deep+1);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1])  po=i;
	}
	for(j=0;j<=po;j++){
		t.erase();
		dfs(1);
	}
	cout<<sum;
	return 0;
}
