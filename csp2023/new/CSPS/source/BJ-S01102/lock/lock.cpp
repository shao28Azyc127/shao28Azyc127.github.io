#include<bits/stdc++.h>
using namespace std;
char mm[10][6];
int w[6]={0};
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;i++){
	for(int j=0;j<5;j++){
	cin>>mm[i][j];}
}
if(n==1){
cout<<81;
}
else if(n==2){
	if(strcmp(mm[0],mm[1])==0){
		cout<<81;
		}
	else{
		cout<<10;}}
else{
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(mm[i],mm[j])!=0){
					for(int k=0;k<5;k++){
						if(mm[i][k]==mm[j][k]){
							w[k]=1;
						}
					}
				}
			}
	}
	for(int i=0;i<5;i++){
		if(!w[i]){
			ans+=9;
			}
		}
	cout<<ans;
}
return 0;
}
