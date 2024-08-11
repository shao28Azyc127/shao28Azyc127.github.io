#include<bits/stdc++.h>
using namespace std;

int n;
int step(int l){
	if(l==1){
		return 1;
	}	
	if(l%3==0){
		return 1+step(l-l/3);
	}else{
		return 1+step(l-(l/3+1));
	}
}	

int which(int l){
	if(l%3==1){
		return 1;
	}
	if(l%3==0){
		return 1+which(l-l/3);
	}else{
		return 1+which(l-(l/3+1));
	}
}

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	cout<<step(n)<<" "<<which(n);
	return 0;
}
