#include<bits/stdc++.h>
using namespace std;
const int NR=1e4+5;
int n;
int now;
struct node{int siz,dq;};
map<string,int>val;
map<string,node>st;
string vis[NR];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		int op;cin>>op;
		if(op==1){
			string s;cin>>s;
			int k;cin>>k;
			int w=0,num=0;
			for(int j=1;j<=k;++j){
				string t,x;
				cin>>t>>x;
				if(t=="byte")w=max(w,1),num++;
				else if(t=="short"){
					if(num%2)num+=num%2;
					num+=2;
					w=max(w,2);
				}
				else if(t=="int"){
					if(num%4)num+=num%4;
					num+=4;
					w=max(w,4);
				}
				else if(t=="long"){
					if(num%8)num+=num%8;
					num+=8;
					w=max(w,8);
				}else{
					if(num%st[t].dq)num+=num%st[t].dq;
					num+=st[t].siz;
					w=max(w,st[t].dq);
				}
			}
			if(now%w)now+=now%w;
			now+=num;
			st[s]={num,w};
			cout<<num<<" "<<w<<endl;
		}
		if(op==2){
			string t,x;
			cin>>t>>x;
			if(t=="byte"){
				cout<<now<<endl;
				vis[now]=x;
				val[x]=now;
				now++;
			}else if(t=="short"){
				if(now%2)now+=now%2;
				cout<<now<<endl;
				vis[now]=vis[now+1]=x;
				val[x]=now;
				now+=2;
			}else if(t=="int"){
				if(now%4)now+=now%4;
				for(int j=now;j<now+4;++j)
					vis[j]=x;
				cout<<now<<endl;
				val[x]=now;
				now+=4;
			}else if(t=="long"){
				if(now%8)now+=now%8;
				for(int j=now;j<now+8;++j)
					vis[j]=x;
				cout<<now<<endl;
				val[x]=now;
				now+=8;
			}
		}
		if(op==3){
			string s;
			cin>>s;
			cout<<val[s]<<endl;
		}
		if(op==4){
			int addr;cin>>addr;
			if(vis[addr].size()){
				cout<<vis[addr];
			}else cout<<"ERR"<<endl;
		}
	}
	return 0;
}