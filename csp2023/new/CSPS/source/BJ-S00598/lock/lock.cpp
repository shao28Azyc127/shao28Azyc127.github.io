#include<iostream>
using namespace std;
int n,lock[800][7],sum,cun[800][7],cnt=1,cun2[800][7],cnt2=1,sum1=0,sum2=0,cc=0;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>lock[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(lock[i][j]==lock[1][j]){
				cc++;
			}
        }
    }
    if(cc==5*(n-1)){
		cout<<81;
		return 0;
	}
    for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			for(int k=1;k<=9;k++){
				lock[i][j]=lock[i][j]+k;
				for(int h=1;h<=5;h++){
					cun[cnt][h]=lock[i][h];
				}
				cnt++;
				lock[i][j]=lock[i][j]-k;
			}
		}
		for(int j=1;j<=4;j++){
			for(int k=1;k<=9;k++){
				lock[i][j]=lock[i][j]+k;
				lock[i][j+1]=lock[i][j+1]+k;
				for(int h=1;h<=5;h++){
					cun2[cnt2][h]=lock[i][h];
				}
				cnt2++;
				lock[i][j]=lock[i][j]-k;
				lock[i][j+1]=lock[i][j+1]-k;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=45;j++){
			for(int k=1;k<=45;k++){
				for(int h=1;h<=5;h++){
					if(cun[j][h]==cun[i*45+k][h]){
						sum1++;
						
					}
				}
				if(sum1==5){
					sum2++;
				}
				sum1=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=36;j++){
			for(int k=1;k<=36;k++){
				for(int h=1;h<=5;h++){
					if(cun2[j][h]==cun2[i*36+k][h]){
						sum1++;
						
					}
				}
				if(sum1==5){
					sum2++;
				}
				sum1=0;
			}
			
		}
	}
	cout<<sum2;
    return 0;
}
