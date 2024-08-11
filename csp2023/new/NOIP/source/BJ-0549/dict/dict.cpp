#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005][26],b[3005][2][3005],maxx1,maxx2;
char c[3005][3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			a[i][c[i][j]-'a'+1]++;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=26;j++)
			for(int k=1;k<=a[i][j];k++) b[i][0][++t]=j;
		t=0;
		for(int j=26;j>=1;j--)
			for(int k=1;k<=a[i][j];k++) b[i][1][++t]=j;
	}
	maxx1=1;maxx2=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][1][j]>b[maxx2][1][j]) break;
			if(b[i][1][j]<b[maxx2][1][j]){
				maxx2=i;
				break;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[i][1][j]>b[maxx1][1][j]) break;
			if(b[i][1][j]<b[maxx1][1][j]){
				maxx2=maxx1;
				maxx1=i;
				break;
			}
		}
	}
	//cout<<maxx1<<" "<<maxx2<<endl;
	for(int i=1;i<=n;i++){
		int l=maxx1,ansi=1;
		if(i==maxx1) l=maxx2;
		for(int j=1;j<=m;j++){
			if(b[i][0][j]>b[l][1][j]){
				ansi=0;
				break;
			}
			if(b[i][0][j]!=b[l][1][j]) break;
		}
		printf("%d",ansi);
	}
	return 0;
}
