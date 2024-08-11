#include <bits/stdc++.h>
using namespace std;
int n,nowindexa=0;
int op;
string s,t,tt,m;
int k;
int a[n+1];
int op1a,op1b,op2;
int func(string ss){
	int temp=0;
	int intemp;
	for(int i=1;i<=ss.size();i++){
		if(ss[i]=='.'){
			temp++;
		}
		if(temp==2){
			intemp=i;
			break;
		}
	}
	for(int i=intemp;i<=s.size();i++){
		if(ss[i]=m){
			return a[i];
		}
	}
}
int main(){
	
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>s;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>t>>m;
				if(t=="byte"||t=="short"||t=="int"){
					op1a+=4;
					a[nowindexa]=4;
					nowindexa++;
					if(t=="byte"){
						op1b=1;
					}
					if(t=="short"){
						op1b=2;
					}
					if(t=="int"){
						op1b=4;
					}
				}else{
					op1a+=8;
					a[nowindexa]=8;
					nowindexa++;
					op1b=8;
				}
			}
			cout<<op1a<<" "<<op1b;
		}
		op2=0-op1a;
		if(op==2){
			cin>>tt>>m;
	 		op2+=op1a;
	 		cout<<op2;
		}
		if(op==3||op==4){
			if(op==4){
				int b;
				cin>>b;
				if(func(s)!=b)cout<<"ERR";
			}
			else cout<<func(s);
		}
	}
	return 0;
}