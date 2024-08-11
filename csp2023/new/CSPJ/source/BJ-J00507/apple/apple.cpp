#include<bits/stdc++.h>
using namespace std;
int n,qu;
bool a[1000000005];
bool noa(){
	for(int i=1;i<=n;i++){
		if(a[i]==true) return false;
	}
	return true;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=true;
	}
	int now=0;
	while(1){
		now++;
		int l=2;
		for(int i=1;i<=n;i++){
			if(l==2&&a[i]==true){
				a[i]=false;
				l=0;
			}
			if(a[i]==true) l++;
		}
		if(a[n]==true) qu++;
		if(noa()) break;
	}
	cout<<now<<" "<<qu+1<<endl;
	return 0;
}
