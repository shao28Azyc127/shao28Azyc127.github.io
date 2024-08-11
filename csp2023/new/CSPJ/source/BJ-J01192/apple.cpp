#include<bits/stdc++.h>
using namespace std;

int dg(int x){
	if(x==1)return 1;
	else if(x==2)return 2;
	else return dg(x-(x+2)/3)+1;
}

int gd(int x){
	if(x%3==1)return 1;
	else return gd(x-(x+2)/3)+1;
}

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	cout<<dg(n)<<" "<<gd(n);
	return 0;
}
