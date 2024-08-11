#include<bits/stdc++.h>
using namespace std;
long long y,d[100000],jia[100000],zong[100000],Ny,jyd[1000000],dqlc[1000000],hjh;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,b;
	cin>>n>>b;
	for(int i=1;i<=n-1;i++){
		cin>>d[i];
		hjh+=d[i];
		dqlc[i]=hjh;
	}
	for(int i=1;i<=n;i++){
		cin>>jia[i];
	}
	jyd[1]=1;
	for(int i=1;i<n;i++){
		if(jia[i]<=jia[i+1]){
			jyd[i+1]=jyd[i];
		}
		else{
			zong[i]=d[i];
			jyd[i+1]=i+1;
			zong[jyd[i]]=d[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<d[i];j++){
			if((j+y)*b>=dqlc[i]){
				y=y+j;
				Ny=Ny+j*jia[jyd[i]];
				break;
			}
		}
	}
	cout<<Ny;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
