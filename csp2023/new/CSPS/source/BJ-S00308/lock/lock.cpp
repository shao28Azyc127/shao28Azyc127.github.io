#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int loc[N][7],x[10][7];
int cnt;
void init(){
	for(int a=0;a<=9;a++){
		for(int b=0;b<=9;b++){
			for(int c=0;c<=9;c++){
				for(int d=0;d<=9;d++){
					for(int e=0;e<=9;e++){
						loc[++cnt][1]=a,loc[cnt][2]=b,loc[cnt][3]=c,loc[cnt][4]=d,loc[cnt][5]=e;
					}
				}
			}
		}
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++) cin>>x[i][j];
	}
	init();
	int ans=0;
	for(int i=1;i<=cnt;i++){
		bool flag=1;
		int res,resi,resj;
		for(int j=1;j<=n;j++){
			res=0,resi=0,resj=0;
			for(int k=1;k<=5;k++){
				if(x[j][k]!=loc[i][k]){
					if(res==0) res=1,resi=k;
					else if(res==1) res=2,resj=k;
					else flag=0;
				} 
			}
			if(res==0) flag=0;
			if(flag){
				if(res==2){
					int f1,f2;
					if(resi+1!=resj) flag=0; 
					else{
						if(loc[i][resi]<x[j][resi]) f1=loc[i][resi]+10-x[j][resi];
						else f1=loc[i][resi]-x[j][resi];
						if(loc[i][resj]<x[j][resj]) f2=loc[i][resj]+10-x[j][resj];
						else f2=loc[i][resj]-x[j][resj];
						if(f1!=f2) flag=0;
					}
				}
			}
		}
		if(flag){
			ans++;
		}
	}
	cout<<ans<<endl;
}
