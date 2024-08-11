#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],l[10],b[10],ans;
void dfs(int wz){
	if(wz==5){
		//cout<<jl1<<" "<<cnt1<<" "<<jl2<<" "<<cnt2<<"\n";for(int i=1;i<=5;++i) cout<<l[i]<<" ";cout<<"\n";
		for(int i=1;i<=n;++i){
			int cnt1=0,cnt2=0,jl1=0,jl2=0;
			for(int j=1;j<=5;++j){
				if(l[j]!=a[i][j]){
					if(!jl1) cnt1=(a[i][j]-l[j]+10)%10,jl1=j;
					else if(!jl2) cnt2=(a[i][j]-l[j]+10)%10,jl2=j;
					else return ;
				}
			}
			if(!jl1&&!jl2) return ;
			if(jl1&&jl2&&(cnt1!=cnt2||abs(jl2-jl1)>1)) return ;
		}
		ans++;
		return ;
	}
	for(int i=0;i<=9;++i) l[wz+1]=i,dfs(wz+1);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) for(int j=1;j<=5;++j) cin>>a[i][j];
	dfs(0);
	cout<<ans;
	return 0;
}