#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,m;
int a[3005][30];
string mx[3005],mn[3005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		for(char c:tmp){
			a[i][c-'a'+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			for(int k=1;k<=a[i][j];k++){
				mn[i].push_back(j+'a'-1);
			}
		}
		for(int j=26;j>=1;j--){
			for(int k=1;k<=a[i][j];k++){
				mx[i].push_back(j+'a'-1);
			}
		}
	}
	int minidx=1;
	for(int i=1;i<=n;i++) if(mx[minidx]>mx[i]) minidx=i;
	for(int i=1;i<=n;i++){
		bool flag=1;
		if(i==minidx){
			for(int j=1;j<=n;j++) if(i!=j) flag&=(mn[i]<mx[j]);
		}
		else{
			flag&=(mn[i]<mx[minidx]);
		}
		cout<<flag;
	}
	return 0;
}
