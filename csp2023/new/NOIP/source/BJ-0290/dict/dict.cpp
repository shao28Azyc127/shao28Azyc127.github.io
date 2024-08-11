#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[3500];int t[200][5005],len[10000],len1[10000];
struct Node{char s;int nm;}lz[27][3005],lz1[27][3005];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)t[a[i][j]][i]++;
	for(int i=1;i<=n;i++)for(int j='a';j<='z';j++){
		if(t[j][i])lz[++len[i]][i].s=j,lz[len[i]][i].nm=t[j][i];
	}for(int i=1;i<=n;i++)for(int j='z';j>='a';j--){
		if(t[j][i])lz1[++len1[i]][i].s=j,lz1[len1[i]][i].nm=t[j][i];
	}for(int i=1;i<=n;i++){bool ans=1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=max(len[i],len1[i]);k++){
				char c=lz[k][i].s,c1=lz1[k][j].s;
				int aa=lz[k][i].nm,aa1=lz1[k][j].nm;
				if(c<c1)break;if(c>c1){ans=0;break;}
				if(aa>aa1){ans=0;break;}
				if(aa<aa1){ans=0;break;}
			}
		}cout<<ans;
	}cout<<endl;return 0;
}