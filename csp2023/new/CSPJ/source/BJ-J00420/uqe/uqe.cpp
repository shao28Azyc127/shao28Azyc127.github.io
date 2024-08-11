#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m,a[5005],b[5005],c[5005],p,q;
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	if(m==1||m==-1||m==0){
		for(int i=1;i<=t;i++){
			cout<<"0"<<endl;
		}
	}
	else{
	for(int i=1;i<=t;i++){
		p=b[i]*b[i];
		q=4*a[i]*c[i];
		if(p-q<0){
			cout<<"NO"<<endl;
		}
	}
}
	return 0;
}
