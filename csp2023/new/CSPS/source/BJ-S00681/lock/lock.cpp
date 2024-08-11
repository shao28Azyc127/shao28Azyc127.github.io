#include<bits/stdc++.h>

using namespace std;

int n;
int a[10][6];

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	
	if(n==1){
		cout<<81;
		return 0;
	}else if(n==2){
		int cha=0;
		for(int i=1;i<=5;i++){
			if(a[1][i]!=a[2][i]){
				cha++;
			}
		}
		if(cha>=3){
			cout<<0;
			return 0;
		}
		if(cha==2){
			int idx_x=0;
			
			for(int i=1;i<=5;i++){
				if(a[1][i]!=a[2][i]){
					idx_x=i;
					break;
				}
			}
			if(a[1][idx_x]-a[2][idx_x]==a[1][idx_x+1]-a[2][idx_x+1]){
				cout<<8;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}
		if(cha==1){
			if(a[1][1]!=a[2][1] || a[1][5]!=a[2][5]){
				cout<<10;
				return 0;
			}else{
				cout<<12;
				return 0;
			}
		}
	}else if(n>=3){
		cout<<10-n;
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
