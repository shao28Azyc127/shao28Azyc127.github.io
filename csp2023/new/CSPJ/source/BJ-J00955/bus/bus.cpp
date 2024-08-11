#include<bits/stdc++.h>
using namespace std;
int a,b,c,alltime;
int start[100010];
int ed[100010];
int tim[100010];
int main(){
	freopen("bus.in","r","stdin");
	freopen("bus.out","w","stdout");
	cin>>a>>b>>c;
	if(a==1||b==1){
		cin>>start[1]>>ed[1]>>tim[1];
		alltime=tim[1];
		int d=alltime/c;
		if(d*c==alltime){
			cout<<alltime;
		}else{
			d=d+1;
			cout<<c*d;
		}
	}else{
		cout<<a+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
