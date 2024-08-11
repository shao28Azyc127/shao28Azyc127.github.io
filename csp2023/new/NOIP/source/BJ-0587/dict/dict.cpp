#include<bits/stdc++.h>
using namespace std;
char w[1005][1005];int n,m;bool x[1005];
bool cmp(char a,char b){
	return a<b;
}
void edit(int deep){
	x[deep]=1;
	char s[1005];
	for(int i = 0;i <= m;i++){
		s[i]=w[deep][i];
	}
	sort(s,s+m+1,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			if(s[j]<w[i][j]){
				x[i]=1;
				break;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(x[i]==0){
			cout<<0;return;
		}
	}
	cout<<1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m;j++){
			w[i][j]=getchar();
		}
	}
	for(int i = 1;i <= n;i++){
		edit(i);memset(x,0,sizeof(x));
	}
	return 0;
}
