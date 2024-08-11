#include<bits/stdc++.h>
using namespace std;
char c[3005];
int cnt[3005][30];
int n,m;
bool ans[3005];
void init(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[j];
			cnt[i][int(c[j]-'a'+1)]++;
		}
	} 
}
bool cmp(int x,int y){
	int stx=0,sty=26;
	while(cnt[x][stx]==0) stx++;
	while(cnt[y][sty]==0) sty--;
	if(stx<sty) return true;
	return false;
}

void solve(int i){
	for(int j=1;j<=n;j++){
		if(i!=j){
			if(cmp(i,j)==0){
				ans[i]=0;
				return;
			}
		}
	}
	ans[i]=1;
	return ;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    init();
    for(int i=1;i<=n;i++) solve(i);
    for(int i=1;i<=n;i++) cout<<ans[i];
    return 0;
}
