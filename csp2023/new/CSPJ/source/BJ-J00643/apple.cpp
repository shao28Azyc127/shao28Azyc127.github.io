#include<iostream>
using namespace std;
int da,na;
void solve(int n,int f,int c){
	if(!n){
		return ;
	}
	int t=n/3+(n%3!=0);
	if(n==t){
		da=c;
	}
	if(n%3==1&&!f){
		na=c;
		f=1;
	}
	solve(n-t,f,c+1);
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	solve(n,0,1);
	cout<<da<<" "<<na;
	return 0;
}
