#include<iostream>
using namespace std;
const int N=1e6+5;
int n,d,v[N],p[N];
struct nd{
	int x,y=0;
} dp[1000][1000];

int min(int x,int y){
	if(x<y) return x;
	return y;
}

	
int zhengchu(int x,int y){
	if(x%y==0) return x/y;
	return x/y+1;
	return 0;
}


int main(){
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		if(i>=2){
			v[i]=v[i]+v[i-1];
		}
		
		
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
	
		for(int j=1;j<=n-1;j++){
			if(i==1){
				dp[i][j].x=zhengchu(v[j],d)*p[i];
				dp[i][j].y=zhengchu(v[j],d)*d-v[j];
			}
			else{
				if(j-i<0){
					dp[i][j].x=dp[j][j].x;
					dp[i][j].y=dp[i-1][j].y;
					continue;
				}
				dp[i][j].y=zhengchu(v[j],d)*d-v[j];
				dp[i][j].x=min(dp[i-1][j].x,dp[i][j-1].x+zhengchu(v[j]-dp[i][j-1].y,d)*p[i]);
				
			}
			
		}
	}
	cout<<dp[n][n-1].x;
	
	return 0;
}
