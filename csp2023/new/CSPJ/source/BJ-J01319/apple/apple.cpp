#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout); 
	int n;
	cin>>n;
	int a[101];
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	int v=0;
	for(int j=1;j<=n;j++){
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			if(i%3!=0){
				a[i]=0;
				v++;
			}else{
				continue;
			}
		}else{continue;}
	}
	v++; 
}
cout<<v; 
	return 0;
}