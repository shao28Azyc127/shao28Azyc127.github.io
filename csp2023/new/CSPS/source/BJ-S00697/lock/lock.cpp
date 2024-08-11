#include <bits/stdc++.h>
using namespace std;
long long a[10],b[10],c[10],d[10],e[10];
int main(){
	long long n,a1,b1,c1,d1,e1,o=0,p=0;
	cin>>n;
	
	if(n==1){
		cin>>a[1]>>b[1]>>c[1]>>d[1]>>e[1];
		cout<<81;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			a1++;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		if(b[i]!=b[i-1]){
			b1++;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			c1++;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		if(d[i]!=d[i-1]){
			d1++;
			break;
		}
	}
	for(int i=2;i<=n;i++){
		if(e[i]!=e[i-1]){
			e1++;
			break;
		}
	}
	if(a1==1){
		o=1;
	}
	if(b1==1&&o==0){
		o=1;
	}
	else if(b1==1){
		p=1;
	}
	if(c1==1&&o==0){
		o=1;
	}
	else if(c1==1){
		p=1;
	}
	if(d1==1&&o==0){
		o=1;
	}
	else if(d1==1){
		p=1;
	}
	if(e1==1&&o==0){
		o=1;
	}
	else if(e1==1){
		p=1;
	}
	if(o==1&&p==0){
		cout<<10;
	}
	
return 0;
}
