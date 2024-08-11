#include<bits/stdc++.h>
using namespace std;
int k(int a,int b,int c){
	int s= -b+sqrt(c)/2a;
	int t= -b-sqrt(c)/2a;
	if(s>t){
		return s;
	}
	else{
		return t;
	}
int f(int x.int y,int z){
	int m=y*y-4*x*z;
	return m;
}
struct node td[10001]{
	int a;
	int b;
	int c;
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int T,M;
	cin>>T>>M;
	for(int i=1;i<=T;i++){
		cin>>td[i].a>>td[i].b>>td[i].c;
	}
	for(int i=1;i<=n;i++){
		if(f(td[i].a,td[i].b,td[i].c)<0){
			cout<<"NO";
		}
		if(f(td[i].a,td[i].b,td[i].c)>=0){
			cout<<k(td[i].a,td[i].b,f(td[i].a,td[i].b,td[i].c));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}