#include<bits/stdc++.h>
using namespace std;
int op,t,c,n,m[1000010],cnt;
string a,b;
map<string,int>s;
map<int ,string>p;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==2){
			cin>>a>>b;
			s[b]=t;
			p[t]=b;
			m[++cnt]=t;
			t+=8;
		}
		if(op==3){
			cin>>a;
			cout<<s[a]<<endl;
		}
		if(op==4){
			cin>>c;
			int f=1;
			for(int i=1;i<=cnt;i++){
				if(m[i]+8-1>=c){
					cout<<p[m[i]]<<endl;
					f=0;
					break;
				}
			}
			if(f)cout<<"ERR"<<endl;
		}
	}
	return 0;
};