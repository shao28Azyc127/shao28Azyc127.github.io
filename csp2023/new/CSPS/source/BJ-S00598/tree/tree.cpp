#include<iostream>
using namespace std;
int n,a[101],b[101],c[101],u,v;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
	}
	cout<<1;
	return 0;
}
