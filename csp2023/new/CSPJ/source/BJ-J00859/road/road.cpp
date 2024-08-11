#include<iostream>
using namespace std;
int dis[10000],m,oo;
int money[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>dis[i];
	for(int i=1;i<=n;i++){
		cin>>money[i];
	}
	long long sum=0;
	int k=0;
	for(int i=1;i<n;i++){
		if(money[i+1]<money[i]){
			if((dis[i]-k)%d==0) m=(dis[i]-k)/d;
			else m=(dis[i]-k)/d+1;
			sum+=m*money[i];
			k=m*d-dis[i];
		}
		else{
			int dishe=dis[i];
			for(int j=i+1;j<n;j++){
				if(money[j]<money[i]){
					 oo=j-1;
					break;
				}
				dishe+=dis[j];
			}
			dishe-=k;
			if(dishe%d==0) m=dishe/d;
			else  m=dishe/d+1;
			sum+=m*money[i];
			k=m*d-dishe;
			i=oo;
		}	
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}