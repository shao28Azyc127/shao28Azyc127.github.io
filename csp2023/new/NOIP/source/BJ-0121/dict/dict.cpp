#include<bits/stdc++.h>

using namespace std;
const int N=3e3+5;
int n,m;
string s[N],mins[N],maxs[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]=" "+s[i];
		int minj,maxj;
		char minc='z'+1,maxc=0;
		for(int j=1;j<=m;j++){
			char c=s[i][j];
			if(c<=minc){
				minc=c;
				minj=j;
			}
			if(c>=maxc){
				maxc=c;
				maxj=j;
			}
		}
		mins[i]=maxs[i]=s[i];
		if(minj!=1){
			int j=1;
			while(j<=m&&mins[i][j]==minc) j++;
			if(j!=m+1) swap(mins[i][j],mins[i][minj]);
		}
		if(maxj!=1){
			int j=1;
			while(j<=m&&maxs[i][j]==maxc) j++;
			if(j!=m+1) swap(maxs[i][j],maxs[i][maxj]);
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mins[i]>=maxs[j]){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}