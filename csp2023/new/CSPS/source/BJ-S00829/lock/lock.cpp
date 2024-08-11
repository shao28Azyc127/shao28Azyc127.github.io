#include<bits/stdc++.h>
using namespace std;
const int N=8+2;
int a[N][6];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>a[i][j];
	for(int i=1;i<=5;i++){
		for(int j=1;j<=9;j++){
			bool p=1;
			a[1][i]=(a[1][i]+1)%10;
			for(int k=2;k<=n;k++){
				vector<int> dif;
				for(int h=1;h<=5;h++){
					if(a[1][h]!=a[k][h]) dif.push_back(h);
				}
				if(dif.size()>2){
					p=0;
					break;
				}
				if(dif.size()==2&&(dif[1]-dif[0]!=1||(abs(a[1][dif[1]]-a[k][dif[1]]))%10!=(abs(a[1][dif[2]]-a[k][dif[2]]))%10)){
					p=0;
					break;
				}
			}
			if(p) ans++;
		}
		a[1][i]=(a[1][i]+1)%10;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=9;j++){
			bool p=1;
			a[1][i]=(a[1][i]+1)%10;
			a[1][i+1]=(a[1][i+1]+1)%10;
			for(int k=2;k<=n;k++){
				vector<int> dif;
				for(int h=1;h<=5;h++){
					if(a[1][h]!=a[k][h]) dif.push_back(h);
				}
				if(dif.size()>2){
					p=0;
					break;
				}
				if(dif.size()==2&&(dif[1]-dif[0]!=1||abs(a[1][dif[1]]-a[k][dif[1]])!=abs(a[1][dif[2]]-a[k][dif[2]]))){
					p=0;
					break;
				}
			}
			if(p) ans++;
		}
		a[1][i]=(a[1][i]+1)%10;
		a[1][i+1]=(a[1][i+1]+1)%10;
	}
	cout<<ans;
	return 0;
}
