#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	string name;
	ll st,en;
};
node a[205];
ll addr,n,op,k,m,flag,po;
string t,s,na;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			cin>>s>>k;
			for(int i=1;i<=k;i++){
				cin>>t>>na;
			}
		}
		else if(op==2){
			cin>>t>>na;
			a[++m].name=na;
			po=m==1?0:a[m-1].en+1;
			for(ll i=po;i<=po+15;i++){
				if(t=="byte"){
					a[m].st=i,a[m].en=i;
					break;
				}
				else if(t=="short"){
					if(i%2==0){
						a[m].st=i,a[m].en=i+1;
					}
				}
				else if(t=="int"){
					if(i%4==0){
						a[m].st=i;
						a[m].en=i+3;
					}
				}
				else if(t=="long"){
					if(i%8==0){
						a[m].st=i;
						a[m].en=i+7;
					}
				}
			}
		}
		else if(op==3){
			cin>>t;
			for(ll i=1;i<=m;i++){
				if(a[i].name==t){
					cout<<a[i].st<<endl;
				}
			}
		}
		else{
			flag=0;
			cin>>addr;
			for(ll i=1;i<=m;i++){
				if(a[i].st<=addr&&a[i].en>=addr){
					flag=1;
					cout<<a[i].name<<endl;
					break;
				}
			}
			if(flag==0){
				cout<<"ERR"<<endl;
			}
		}
	}
	return 0;
}
