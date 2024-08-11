#include <iostream>
using namespace std;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		if(op==1){
			string s;
			int k;
			cin>>s>>k;
			for(int j=1;j<=k;j++){
				int t,n;
				cin>>t>>n;
			}
		}else if(op==2){
			int t,n;
			cin>>t>>n;
		}else if(op==3){
			string s;
			cin>>s;
		}else{
			int addr;
			cin>>addr;
		}
		cout<<"ERR"<<endl;
	}
	return 0;
}
