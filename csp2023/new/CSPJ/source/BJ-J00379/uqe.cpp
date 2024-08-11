#include<bits/stdc++.h>
using namespace std;

int t,m,a[5010],b[5010],c[5010];

int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	for(int i=0;i<t;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]==0 && c[i]==0)cout<<sqrt(a[i]);
	}
	
}
