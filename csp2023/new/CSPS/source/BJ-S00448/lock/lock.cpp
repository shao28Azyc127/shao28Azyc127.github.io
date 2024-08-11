#include<iostream>
#include<vector>
#include<map>
using namespace std;
int n,x[6],y[6],r,ans,vis[15];
vector<int> vc[9],poss[80005],poss2;
map<vector<int>,int> vos;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>x[j];
			vc[i].push_back(x[j]);
		}
		for(int j=1;j<=5;j++){
			y[j]=x[j];
			for(int k=1;k<=9;k++){
				for(int l=1;l<=5;l++){
					y[l]=x[l];
				}
				y[j]=(x[j]-k+10)%10;
				++r;
				for(int l=1;l<=5;l++){
					poss[r].push_back(y[l]);
				}
			}
		}
		for(int j=1;j<=4;j++){
			y[j]=x[j];
			for(int k=1;k<=9;k++){
				for(int l=1;l<=5;l++){
					y[l]=x[l];
				}
				y[j]=(x[j]-k+10)%10;
				y[j+1]=(x[j+1]-k+10)%10;
				++r;
				for(int l=1;l<=5;l++){
					poss[r].push_back(y[l]);
				}
				for(int l=1;l<=5;l++){
					y[l]=x[l];
				}
				y[j]=(x[j]+k+10)%10;
				y[j+1]=(x[j+1]+k+10)%10;
				++r;
				for(int l=1;l<=5;l++){
					poss[r].push_back(y[l]);
				}
			}
		}
	}
	for(int i=1;i<=r;i++){
		if(vos[poss[i]]){
			continue;
		}
		vos[poss[i]]=1;
		int flg=1;
		for(int j=1;j<=n;j++){
			if(vc[j]==poss[i]){
				flg=0;
				break;
			}
		}
		if(flg){
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			for(int j=1;j<=5;j++){
				x[j]=y[j]=poss[i][j-1];
			}
			for(int j=1;j<=5;j++){
				for(int k=1;k<=9;k++){
					for(int l=1;l<=5;l++){
						y[l]=x[l];
					}
					y[j]=(x[j]-k+10)%10;
					poss2.clear();
					for(int l=1;l<=5;l++){
						poss2.push_back(y[l]);
					}
					for(int l=1;l<=n;l++){
						if(poss2==vc[l]){
							vis[l]=1;
						}
					}
				}
			}
			for(int j=1;j<=4;j++){
				for(int k=1;k<=9;k++){
					for(int l=1;l<=5;l++){
						y[l]=x[l];
					}
					y[j]=(x[j]-k+10)%10;
					y[j+1]=(x[j+1]-k+10)%10;
					poss2.clear();
					for(int l=1;l<=5;l++){
						poss2.push_back(y[l]);
					}
					for(int l=1;l<=n;l++){
						if(poss2==vc[l]){
							vis[l]=1;
						}
					}
					for(int l=1;l<=5;l++){
						y[l]=x[l];
					}
					y[j]=(x[j]+k+10)%10;
					y[j+1]=(x[j+1]+k+10)%10;
					poss2.clear();
					for(int l=1;l<=5;l++){
						poss2.push_back(y[l]);
					}
					for(int l=1;l<=n;l++){
						if(poss2==vc[l]){
							vis[l]=1;
						}
					}
				}
			}
			int ret=1;
			for(int j=1;j<=n;j++){
				ret&=vis[j];
			}
			ans+=ret;
		}
	}
	cout<<ans;
	return 0;
}
