#include<bits/stdc++.h>
using namespace std;
int n,a[100010],v[100010],sum,d,tmp,y,i;
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	v[n]=-1;
	i=1;
	while(i<n){
		tmp=0;
		for(int j=i+1;j<=n;j++){
			tmp+=a[j-1];
			if(v[j]<v[i]){
				if(y>=tmp){
					y-=tmp;
					i=j;
					break;
				}
				else{
					int tsum=(tmp-y)/d;
					if((tmp-y)%d>0)tsum++;
					sum+=tsum*v[i];
					y=tsum*d-(tmp-y);
					
					i=j;
					break;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}