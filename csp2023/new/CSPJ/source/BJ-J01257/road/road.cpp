#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a],d[a+1];
	for(int i=1;i<a;i++){
		cin>>c[i];
	}
	int e=0;
	for(int i=1;i<=a;i++){
		cin>>d[i];
		e+=d[i];
	}
	e++;
	e/=a;
	e*=c[i];
	e--;
	cout<<e;
	return 0;
}
