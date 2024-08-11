#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][5];
int main(){
	ios::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
		printf("81");
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 5;j++){
			cin>>a[i][j];
		}
	}
	int tdiff,ans=1e9+1,tans;
	for(int i = 1;i <= n;i++){
	    for(int j = 1;j <= n;j++){
			if(a[i][1]==a[j][1]&&a[i][5]==a[j][5]){
	    		tdiff=0;
	            for(int k = 2;k <= 4;k++){
	    			if(a[i][k]!=a[j][k]&&a[i][k-1]==a[j][k-1])tdiff++;
	            }
	            if(tdiff==0)tans=81;
	            else if(tdiff==1)tans=12;
	            else if(tdiff==2)tans=128;
			}else if(a[i][1]!=a[j][1]&&a[i][5]!=a[j][5]){
				tans=0;
				tans=0;
			}else{
	            for(int k = 2;k <= 4;k++){
	    			if(a[i][k]!=a[j][k]&&a[i][k-1]==a[j][k-1])tdiff++;
	            }
	            if(tdiff==0)tans=10;
			}
	        ans=min(ans,tans);
	    }
	}
	cout<<ans;
    return 0;
}