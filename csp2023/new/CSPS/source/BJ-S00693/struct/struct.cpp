#include<iostream>
using namespace std;
string a[10005];
int v;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		string s,s1;
		int op;
		cin>>op;
		if(op==2){
			cin>>s>>s1;
			for(int i=v*8;i<=(v+1)*8;i++){
				a[i]=s1;
			}
			cout<<v*8<<endl;
			v++;
		}
		if(op==3){
			cin>>s1;
			for(int i=0;i<=8*v;i++){
				if(a[i]==s1){
					cout<<i*8<<endl;
					break;
				}
			}
		}
		if(op==4){
			int x;
			cin>>x;
			cout<<a[x]<<endl;
		}
	}
	return 0;
}