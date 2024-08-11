#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("road.in","r",stdin);
        freopen("road.out","w",stdout);
	int n,d,s,f=0,fs=0,r=1,ans=0;
	bool m;
	cin>>n>>d;
	int v[n],a[n+1];
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(i==r){
			m=false;
			for(int j=i+1;j<=n;j++){
				if((a[j]<a[i]||j==n)&&m==false){
					r=j;
					s=0;
					for(int k=i;k<j;k++){
						s+=v[k];
					}
					f=f+s-fs*d;
					if(f==f/d*d){
						fs=f/d;
					}
					else{
						fs=f/d+1;
					}
					ans+=fs*a[i];
					m=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
