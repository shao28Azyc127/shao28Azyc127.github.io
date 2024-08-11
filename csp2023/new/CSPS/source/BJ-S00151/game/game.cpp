#include <iostream>
#include <string>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int pre(int i,const string& s,const string& s2){while(i>=0&&s2[i]=='0')i--;return i;}
bool chk(const string& s,string& s2){
	while(1){
		bool flag=false;
		for(int i=pre(s.size()-1,s,s2);pre(i-1,s,s2)>=0;i=pre(i-1,s,s2)){
			int j=pre(i-1,s,s2);
			if(j>=0&&s[i]==s[j]){flag=true;s2[i]=s2[j]='0';}
		}
		if(!flag)break;
	}
	for(int i=0;i<s.size();i++)	if(s2[i]=='1')	return false;
	return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,cnt=0;
	string str;
	cin>>n>>str;
	string s1=".",s2="1";
	for(int i=1;i<=str.size()+1;i++){
		if(i<=str.size())s1+=str[i-1];
		else	s1+='.';
		s2+='1';
		chk(s1,s2);
		if(s2[i]=='0')	cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
