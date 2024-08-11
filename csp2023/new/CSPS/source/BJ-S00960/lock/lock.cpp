#include<bits/stdc++.h>
using namespace std;
const int maxnum=1e5+10;
int n,sum=0;
bool lis[2][maxnum];
int a[5];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	memset(lis,1,sizeof(lis));
	for(int i=0;i<n;i++){
		for(int j=0;j<maxnum;j++) lis[i%2][j]=false;
		for(int j=0;j<5;j++) cin>>a[j];
		for(int j=1;j<10;j++){
			for(int k=0;k<5;k++){
				a[k]+=j;
				a[k]%=10;
				sum=0;
				for(int l=0;l<5;l++){
					sum*=10;
					sum+=a[l];
				}
				//cout<<sum<<endl;
				lis[i%2][sum]=lis[(i+1)%2][sum];
				a[k]+=(10-j);
				a[k]%=10;
			}
			for(int k=0;k<4;k++){
				a[k]+=j;
				a[k]%=10;
				a[k+1]+=j;
				a[k+1]%=10;
				sum=0;
				for(int l=0;l<5;l++){
					sum*=10;
					sum+=a[l];
				}
				lis[i%2][sum]=lis[(i+1)%2][sum];
				a[k]+=(10-j);
				a[k]%=10;
				a[k+1]+=(10-j);
				a[k+1]%=10;
			}
		}
	}
	sum=0;
	for(int i=0;i<maxnum;i++){
		if(lis[(n-1)%2][i]) sum++;
	}
	cout<<sum;
}