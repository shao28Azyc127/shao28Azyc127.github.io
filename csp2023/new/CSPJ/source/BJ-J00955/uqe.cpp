#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[10000],d[10000],e[10000];
int main(){
	freopen("uqe.in","r","stdin");
	freopen("uqe.out","w","stdout");
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i]>>d[i]>>e[i];
	}
	for(int i=1;i<=a;i++){
		if(c[i]>=-2&&c[i]<=2&&d[i]>=-2&&d[i]<=2&&e[i]>=-2&&e[i]<=2){
			cout<<1<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}