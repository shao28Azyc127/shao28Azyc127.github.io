#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void text(){
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		if(op==1){
			string s;
			int k;
			cin>>s>>k;
			while(k--){
				string a,b;
				cin>>a>>b;
			}
			cout<<0<<" "<<0<<endl;
		}
		else if(op==2){
			string a,b;
			cin>>a>>b;
			cout<<0<<endl;
		}
		else if(op==3){
			string s;
			cin>>s;
			cout<<0<<endl;
		}
		else if(op==4){
			int addr;
			cin>>addr;
			cout<<"ERR"<<endl;
		}
	}
	return;
}
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	text();
	return 0;
}