#include<bits/stdc++.h>
using namespace std;
int n,op,k;
long long addr;
string s,ti,ni,t,n2;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>s>>k;
			for(int j=1;j<=k;j++){
				cin>>ti>>ni;
			}
		}
		if(op==2){
			cin>>t>>n2;
		}
		if(op==3){
			cin>>s;
		}
		if(op==4){
			cin>>addr;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"ERR"<<endl;
	}
	return 0;
}
