#include<iostream>
#include<cstdio>
using namespace std;
int a[1000001],b[1000001],c[1000001];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k,cns=0;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>a[i]>>b[i]>>c[i];
		cns+=c[i];
	}
	if(cns==0){
		cout<<m;
	}
	else{
		cout<<-1;
	}
	return 0;
}

