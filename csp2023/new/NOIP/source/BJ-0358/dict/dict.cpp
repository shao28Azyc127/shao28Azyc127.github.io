#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,cnt;
char s[N][N],bes[N];
inline int cmp(char x,char y){
	return (int)x<(int)y;
}
inline int cmp2(char x,char y){
	return (int)x>(int)y;
}
inline int comp(int indx){
	for(register int i=1;i<=m;i++){
		if(s[indx][i]>bes[i]) return 1;
		if(s[indx][i]<bes[i]) return -1;
	}
	return 0;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++) bes[i]='z';
	for(register int i=1;i<=n;i++){
		cin>>(s[i]+1);
		sort(s[i]+1,s[i]+m+1,cmp2);
		if(comp(i)==-1){
			for(register int j=1;j<=m;j++) bes[j]=s[i][j];
			cnt=1;
		}else if(comp(i)==0) cnt++;
	}
	for(register int i=1;i<=n;i++){
		sort(s[i]+1,s[i]+m+1,cmp);
		if(comp(i)==1) cout<<0;
		else if(comp(i)==0){
			if(cnt==1) cout<<1;
			else cout<<0;
		}else cout<<1;
	}
	cout<<endl;
	return 0;
}
