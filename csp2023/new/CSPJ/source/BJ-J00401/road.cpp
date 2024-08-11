#include<bits/stdc++.h>
using namespace std;
int n,d,r[100005],p[100005];
int a,t=0,k,e=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>r[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    a=p[1];
    k=r[1];
    for(int i=2;i<=n;i++){
    	if(i==n){
    		if((k-e)%d)
    			t+=((k-e)/d+1)*a;
    		else 
    			t+=(k-e)/d*a;
    		break;
		}
		
    	else if(p[i]<a){
    		if((k-e)%d>0){
    			t+=((k-e)/d+1)*a;
    			e+=((k-e)/d+1)*d-k;
			}
    		else{
    			t+=(k-e)/d*a;
    			e=0;
			}
    		a=p[i];
    		k=0;
		}
		k+=r[i];
	}
	cout<<t;
    return 0;
}
