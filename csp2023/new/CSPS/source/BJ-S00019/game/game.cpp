#include<bits/stdc++.h>
using namespace std;
string str;int cnt;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stout);
	cin>>str;
for(int i=0;i<str.size();i++){
	if(str[i]==str[i+1])cnt++;
}
	if(str.size()==4){
		for(int i=0;i<1;i++){
				if(str[0]!=str[1]&&str[1]==str[2]&&str[0]==str[3]&&str[2]!=str[3])cnt+=2;
				if(str[0]==str[1]&&str[2]==str[3])cnt++;
			}
		}
		
	if(str.size()==5){
		for(int i=0;i<1;i++){
			if(str[2]==str[3]&&str[1]==str[4])cnt+=2;
			if(str[0]==str[1]&&str[2]==str[3])cnt++;
				if(str[0]==str[3]&&str[1]==str[2])cnt+=2;
				if(str[1]==str[2]&&str[3]==str[4])cnt++;
		}
	}	
	if(str.size()==6){
		for(int i=0;i<1;i++){
			if(str[2]==str[3]&&str[1]==str[4])cnt+=2;
			if(str[0]==str[1]&&str[2]==str[3])cnt++;
				if(str[0]==str[3]&&str[1]==str[2])cnt+=2;
				if(str[1]==str[2]&&str[3]==str[4])cnt++;
				if(str[0]==str[1]&&str[2]==str[3]&&str[4]==str[5])cnt++;
				if(str[2]==str[3]&&str[4]==str[5])cnt++;
				if(str[0]==str[5]&&str[1]==str[2]&&str[3]==str[4])cnt++;
				if(str[2]==str[5]&&str[3]==str[4])cnt+=2;
				if(str[0]==str[1]&&str[2]==str[5]&&str[3]==str[4])cnt++;
				if(str[0]==str[3]&&str[1]==str[2]&&str[4]==str[5])cnt++;
				if(str[0]==str[5]&&str[1]==str[2]&&str[3]==str[4])cnt++;
		}
	}	
	cout<<cnt;
	return 0;
}