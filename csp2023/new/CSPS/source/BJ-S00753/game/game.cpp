#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,cnt,a[2000010][30];
string s;
char k;
struct node{
	int l,r;
}nd;
vector<node> vct;
inline bool ishui(int l,int r){
	for(int i=0;i<26;i++){
		if((a[r][i]-a[l][i])%2==1){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%c",&k);
		s[i]=k;
		for(int j=0;j<26;j++){
			a[i][j]+=a[i-1][j];
			if(s[i]-'a'==j){
				a[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ishui(i,j)){
				cnt++;
				nd.l=i;
				nd.r=j;
				vct.push_back(nd);
			}
		}
	}
	for(int i=0;i<(int)(vct.size());i++){
		for(int j=i+1;j<(int)(vct.size());j++){
			if(vct[i].r+1==vct[j].l){
				nd.l=vct[i].l;
				nd.r=vct[j].r;
				vct.push_back(nd);
			}
		}
	}
	printf("%lld",(int)(vct.size())+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
