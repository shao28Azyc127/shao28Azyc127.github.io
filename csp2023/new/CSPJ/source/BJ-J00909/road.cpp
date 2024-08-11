#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],minn=10000000,money,sum;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>d;
for(int i=1;i<n;i++)
	cin>>v[i];
for(int i=1;i<=n;i++){
	cin>>a[i];
}
	minn=a[1];
for(int i=1;i<=n;i++){
	sum=0;
	for(int j=i;j<n;j++){
		sum+=v[j-1]/d+1;
		if(a[j]<minn){
			minn=a[j];
			i=j;
			break;
		
		}
	}
	money+=sum*a[i];
	
}
cout<<money;
fclose(stdin);
fclose(stdout);
return 0;
}
