#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;

struct node{
	string type,name;
	int l,r;
};

map<int,node>va;
map<int,bool>vis;
int cur=0;

int siz(string type){
	if(type=="byte")return 1;
	if(type=="short")return 2;
	if(type=="int")return 4;
	if(type=="long")return 8;
	return 114514;
}

int findmod(int x,int mod){
	if(!x)return x;
	int m=x%mod;
	if(!m)return x;
	return x+mod-m;
}

void ins(int i,string type,string name,int l,int r){
	va[i].type=type,
	va[i].name=name,
	va[i].l=l,va[i].r=r;
	for(int i=l;i<=r;i++)vis[i]=true;
}

signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	ins(0,"string","",-1,-1);
	while(n--){
		int op;
		cin>>op;
		if(op==1){
			cout<<""<<endl;
			//Getfa Getfa Getfa Getfa Getfa Getfa Getfa
		}else
		if(op==2){
			string t,n;
			cin>>t>>n;
			int l;
			bool can=true;
			for(int i=0;;i+=siz(t)){
				if(!vis[i]){
					can=true;
					for(int j=i;j<=i+siz(t)-1;j++)
						if(vis[j]){
							can=false;
							break;
						}
					if(can){
						l=i;
						break;
					}
				}
			}
			cur++,ins(cur,t,n,l,l+siz(t)-1);
			cout<<l<<endl;
		}else
		if(op==3){
			string s;
			cin>>s;
			for(int i=1;i<=cur;i++)
				if(va[i].name==s){
					cout<<va[i].l<<endl;
					break;
				}
		}else
		if(op==4){
			int addr;
			cin>>addr;
			bool done=false;
			for(int i=1;i<=cur;i++){
				if(va[i].l<=addr&&va[i].r>=addr){
					cout<<va[i].name<<endl,done=true;
					break;
				}
			}
			if(!done)cout<<"ERR"<<endl;
		}
	}
	return 0;
}