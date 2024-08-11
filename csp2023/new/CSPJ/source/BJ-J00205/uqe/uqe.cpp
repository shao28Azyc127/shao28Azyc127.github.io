#include<bits/stdc++.h>
using namespace std;
int a,b,c,t,m;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		if(a>1){
			cout<<"NO"<<endl;
		}else if(a==1){
			cout<<"1"<<endl;
		}else{
			cout<<sqrt(-1*a)<<endl;
		}
	}
	return 0;
}
//god! help me!