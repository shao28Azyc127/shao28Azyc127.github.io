#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(b*b+4*(a*c)<0){
			cout<<"NO";
		}
		int maxx=-2147483648;
		for(int j=0-m;j<=m;j++){
			if(a*j*j+b*j+c==0){
				if(j>maxx){
					maxx=j;
				}
			}
		}
		cout<<"sqrt("<<maxx<<")";
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
