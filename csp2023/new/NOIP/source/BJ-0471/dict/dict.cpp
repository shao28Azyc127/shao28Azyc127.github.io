#include <bits/stdc++.h>
using namespace std;

int n,m,f,nw=99,cnt;
int zi[3005][3005],tim[3005][30],mi[3005][3005],ma[3005][3005];
string s[3005];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<=m;j++){
			zi[i][j]=s[i][j-1]-'a'+1;
			tim[i][zi[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cnt=1;
		for(int j=1;j<=26;j++){
			if(tim[i][j]!=0){
				for(int k=1;k<=tim[i][j];k++){
					mi[i][cnt]=j;
					ma[i][m-cnt+1]=j;
					cnt++;
				}
			}
		}
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			if(zi[i][1]<nw){
				f=i,nw=zi[i][1];
			}
		}
		for(int i=1;i<=n;i++){
			if(i==f){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		cout<<endl;
	}else{
		for(int i=1;i<=n;i++){
			f=1;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=m;k++){
					if(mi[i][k]<ma[j][k]){
						break;
					}else if(mi[i][k]>ma[j][k]){
						f=0;
						break;
					}
				}
				if(f==0){
					break;
				}
			}
			cout<<f;
		}
		cout<<endl;
	}
	return 0;
}
