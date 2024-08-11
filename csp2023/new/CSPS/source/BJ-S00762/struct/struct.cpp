#include<bits/stdc++.h>
using namespace std;
char t[105],n[105],a,b,c;
int addr;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int op;
		cin>>op;
		if(op==1){
			char a,int b;
			cin>>a>>b;
			for(int i = 1;i <= b;i++){
				cin>>t[i]>>n[i];
			}
		}else if(op==2){
			cin>>a>>b;
		}else if(op==3){
			cin>>c;
		}else if(op==4){
			cin>>addr;
		}
	}
	return 0;
}
