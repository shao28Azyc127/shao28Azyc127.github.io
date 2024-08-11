#include<bits/stdc++.h>

using namespace std;

int n,ans;
string s;

bool judge(int l,int r){
	string str="",str_="";
	int len=0,idx=0;
	for(int i=l;i<=r;i++){
		str+=s[i],len++;
	}
	
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<=len-1;i++){
			if(i==len-1){
				str_+=str[i],idx++;
			}else if(str[i]!=str[i+1]){
				str_+=str[i],idx++;
			}else{
				flag=true;
				i++;
			}
		}
		str=str_,len=idx;
		str_="",idx=0;
		
	}
	
	if(str!="") return false;
	return true;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n;
	getline(cin,s);
	getline(cin,s);
	for(int k=2;k<=n;k+=2){
		for(int i=0;i+k-1<n;i++){
			if(judge(i,i+k-1)) ans++;
		}
	}

	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
