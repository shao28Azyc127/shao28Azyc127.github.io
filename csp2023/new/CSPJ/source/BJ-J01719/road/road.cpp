#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,d,num=0,sum=0;
cin>>n>>d;
int* u=(int*)malloc(sizeof(int)*(n));
int* a=(int*)malloc(sizeof(int)*(n+1));
for(int i=0;i<n-1;i++){
	cin>>u[i];
}
for(int i=0;i<n;i++){
	cin>>a[i];
}
for(int i=0;i<n;i++){
    if(sum<u[i]/d+1){
       	sum+=(u[i]/d+1)-u[i];
       	num+=(u[i]/d+1)*a[i];
	}	
}
cout<<num;
return 0;
}

