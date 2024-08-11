#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int op,s1,s2,s3,s4,cnt=0;
string ss1,ss2;
map<string,int>sz,mp;
string ad[500020];
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	sz["byte"]=1,sz["short"]=2,sz["int"]=4,sz["long"]=8;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cout<<"Nope, I am done with this.\n";
			break;
		}
		if(op==2){
			cin>>ss1>>ss2;
			cout<<cnt<<"\n";
			for(int i=cnt;i<cnt+sz[ss1];i++) ad[i]=ss2;
			mp[ss2]=cnt;
			cnt+=sz[ss1];
		}
		if(op==3){
			cin>>ss1;
			cout<<mp[ss1]<<"\n";
		}
		if(op==4){
			cin>>s1;
			if(s1>500000) cout<<"ERR\n";
			else if(ad[s1].length()>0) cout<<ad[s1]<<"\n";
			else cout<<"ERR\n";
		}
	}
	return 0;
}
/*
 * similar to last year
 * 
 * maybe you can output lots of ERR in this one
 * 
 * sir none of your structs work
 * 
 * every address is destroyed by cosmic rays!
 */
