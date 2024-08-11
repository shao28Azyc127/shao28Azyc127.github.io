#include<bits/stdc++.h>
using namespace std;
int a[10][10],y[1000001];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		int t=0;
		for(int j=1; j<=5; j++){
			cin>>a[i][j];
			t=(t+a[i][j])*10;
		}
		y[t/10]=-1e9;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=5; j++){
			for(int k=0; k<=9; k++){
				int t=0;
				for(int l=1; l<=5; l++){
					if(l==j){
						t=(t+k)*10;
					} else{
						t=(t+a[i][l])*10;
					}
				}
				y[t/10]++;
			}
		}
		for(int j=1; j<=4; j++){
			for(int k=0; k<=9; k++){
				int t=0;
				for(int l=1; l<=5; l++){
					if(l==j||l==j+1){
						t=(t+(a[i][l]+k)%10)*10;
					} else{
						t=(t+a[i][l])*10;
					}
				}
				y[t/10]++;
			}
		}
	}
	for(int i=0; i<=99999; i++){
		if(y[i]>=n){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}