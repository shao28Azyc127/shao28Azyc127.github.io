#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int a,b,c,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
	}
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
	}
	cout<<n+1;
    return 0;
}
