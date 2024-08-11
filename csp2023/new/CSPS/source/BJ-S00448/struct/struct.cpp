#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n,opt,k,now,x;
string s,t,na;
map<string,int> dq,st;
map<int,string> zj;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout); 
	cin>>n;
	dq["byte"]=1;
	dq["long"]=8;
	dq["int"]=4;
	dq["short"]=2;
	while(n--){
		cin>>opt;
		if(opt==2){
			cin>>t>>na;
			now=(now/dq[t]+(now%dq[t]!=0))*dq[t];
			st[na]=now;
			for(int i=now;i<=now+dq[t]-1;i++){
				zj[i]=na;
			}
			now=now+dq[t];
		}
		if(opt==3){
			cin>>na;
			cout<<st[na]<<endl;
		}
		if(opt==4){
			cin>>x;
			if(zj[x]==""){
				cout<<"ERR"<<endl;
				continue;
			}
			cout<<zj[x]<<endl;
		}
	}
	return 0;
}
