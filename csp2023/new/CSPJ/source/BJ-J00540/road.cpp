#include <iostream>
using namespace std;
int v[100001],a[100001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,ans=0;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(v[i]==0){
			continue;
		}
		if(a[i]>a[i+1]){
			if(v[i]%d==0){
				ans+=v[i]/d*a[i];
			}else{
				ans+=(v[i]/d+1)*a[i];
				int cnt=d-v[i]%d,j=i+1;
				while(cnt>0){
					if(v[j]>=cnt){
						v[j]-=cnt;
						break;
					}else{
						cnt-=v[j];
						v[j]=0;
						j++;
					}
				}
			}
		}else{
			int j=i;
			while(a[j]<=a[j+1]){
				j++;
			}
			int cntt=0;
			for(int k=i;k<=j;k++){
				cntt+=v[k];
				v[k]=0;
			}
			if(cntt%d==0){
				ans+=cntt/d*a[i];
			}else{
				ans+=(cntt/d+1)*a[i];
				int cnt=d-cntt%d,k=j+1;
				while(cnt>0){
					if(v[k]>=cnt){
						v[k]-=cnt;
						break;
					}else{
						cnt-=v[k];
						v[k]=0;
						k++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
