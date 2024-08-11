#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,now=-1,op,ad;
string name,type;
map<string,int> mp;
map<int,string> mp2;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==2){
			cin>>type>>name;
			int res=0;
			if(type=="byte") res=1;
			else if(type=="short") res=2;
			else if(type=="int") res=4;
			else res=8;
			now++;
			int st;
			if(now%res==0) st=now;
			else st=(now/res+1)*res;
			mp[name]=st;
			for(int j=st;j<=st+res-1;j++) mp2[j]=name;
			now+=st-1;
			cout<<st<<endl;
		}else if(op==3){
			cin>>name;
			cout<<mp[name]<<endl;
		}else{
			cin>>ad;
			cout<<mp2[ad]<<endl;
		}
	}
    return 0;
}
