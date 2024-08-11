#include<bits/stdc++.h>
using namespace std;
string a[105];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	/*int n,op;
	scanf("%d%d",&n,&op);
	if(op==1){
		string s;
		int k,mt=0,i;
		cin>>s;
		scanf("%d",&k);
		for(i=1;i<=k;++i){
			string a,b;
			cin>>a>>b;
			if(a=="byte")mt=max(mt,1);
			else if(a=="short")mt=max(mt,2);
			else if(a=="int")mt=max(mt,4);
			else mt=max(mt,8);
		}
		printf("%d",mt*k);
	}
	else if(op==2){
		string a,b;
		cin>>a>>b;
		printf("%d",0);
	}
	else{
		printf("ERR");
	}*/
	int n,nn=0,i,j,op;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>op;
		if(op==2){
			cout<<nn*8<<endl;
			string p;
			cin>>p>>a[++nn];
		}
		else if(op==3){
			string s;
			cin>>s;
			for(j=1;j<=nn;++j){
				if(a[j]==s){
					cout<<(j-1)*8<<endl;
					break;
				}
			}
		}
		else{
			int d;
			cin>>d;
			if(d/8+1>nn)cout<<"ERR"<<endl;
			else cout<<a[d/8+1]<<endl;
		}
	}
	return 0;
}
