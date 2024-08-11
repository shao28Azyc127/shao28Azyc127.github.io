#include <bits/stdc++.h>
using namespace std;
const int N=105;
long long store[N],ff[N];
string gg[N];
int n,op,addr=0;
int x=1;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==2){
			string t,s;
			int h;
			cin>>t>>s;
			if(t=="byte") h=1;
			else if(t=="short") h=2;
			else if(t=="int") h=4;
			else if(t=="long") h=8;
			if(addr%h!=0) addr=(addr/h+1)*h;
			cout<<addr<<endl;
			store[x]=addr;
			gg[x]=s;
			ff[x]=addr+h-1;
			x++;
			addr+=h;
		}else if(op==3){
			string t;
			cin>>t;
			bool f=0;
			for(int i=1;i<=N;i++){
				if(gg[i]==t){
					cout<<store[i]<<endl;
					f=1;
				}
			}
			if(!f) cout<<"ERR"<<endl;
		}else if(op==4){
			int t;
			cin>>t;
			bool f=0;
			for(int i=1;i<=N;i++){
				if(f==1) continue;
				if(store[i]<=t && ff[i]>=t){
					cout<<gg[i]<<endl;
					f=1;
				}
			}
			if(!f) cout<<"ERR"<<endl;
		}
	}
}