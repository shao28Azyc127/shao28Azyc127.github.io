#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,max,a[100100],b[100100],c[100100],time[100100],l;
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int x=1;x<=n;x++){
		time[x]=x;
		while(l<a[x]){
			if(b[x]+x*c[x]>1){
				l+=b[x]+x*c[x];
			}else{
				l++;
			}
			
			
			
			
			//l+=max(b[x]+x*c[x],1);
			//time[x]++;
		}
	}
	for(int x=1;x<=n;x++){
		if(max<time[x]){max=time[x];}
	}
	cout<<max;
	return 0;
}
			
