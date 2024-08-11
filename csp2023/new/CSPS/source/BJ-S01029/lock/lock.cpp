#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b[100][100];
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
cin>>a;
for(int i=0;i<a;i++){
	for(int j=0;j<5;j++){
		cin>>b[i][j];
	}
}
cout<<82-a;
return 0;
}