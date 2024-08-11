#include <bits/stdc++.h>
using namespace std;
map<string,int> m,init;
long long number;
int op,n,j; 
string a[1000000];
string s,t;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	init["byte"]=1;
	init["short"]=2;                                     
	init["long"]=8;
	init["int"]=4;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		if(op==2){
			cin>>s>>t;
			m[t]=j;
			for(int k=1;k<=init[s];k++){
				a[j++]=t;
			}
		}
		if(op==3){
			cin>>s;
			cout<<m[s]<<endl;
		}else if(op==4){
			cin>>number;
			if(j<=number) cout<<"ERR"<<endl;
			else cout<<a[number]<<endl;
		}
	}
	return 0;
}
