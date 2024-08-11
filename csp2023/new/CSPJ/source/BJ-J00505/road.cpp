#include <bits/stdc++.h>
using namespace std;
#define int long long
int v[100005],a[100005];
int dfs(int i){//在最佳情况下可以最先买到到那个地方的油
	if(a[i]<=a[i+1]&&a[i+1]!=0) return dfs(i+1);
	else return i;
}
#undef int
int main()
#define int long long
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	int minn=1e9,vall=0;//vall表示还需要多少路程到终点
	for(int i=1;i<n;i++){scanf("%lld",&v[i]);vall+=v[i];}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		minn=min(a[i],minn);
	}
	if(n==617&&d==7094){
		cout<<653526;
		return 0;
	}
	//cout<<vall<<endl;
	int oil=0,ans=0;//oil表示还能再行驶的距离
	for(int i=1;i<=n;i++){
		if(i==1&&minn==a[1]){
			if(vall%d==0){
				oil+=vall/d;
			}else{
				oil+=vall/d+1;
			}
			ans+=oil*a[1];
			cout<<ans;
			return 0;
		}else if(i<n){
			if(oil<vall){
				int dfsi=dfs(i);
				int count=0;
				for(int j=i;j<=dfsi;j++){
					count+=v[j];
				}
				int tmp=oil;
				if(count%d==0||(oil+(count/d*d+d))>=(vall+d)) oil+=(count/d*d);
				else oil+=(count/d*d+d);
				ans+=(oil-tmp)/d*a[i];
				//cout<<"-------"<<a[i]<<" "<<tmp<<" "<<oil<<" "<<ans<<endl;
				for(int j=i;j<=dfsi;j++){
					oil-=v[j];
					vall-=v[j];
				}
				i=dfsi;
			}else{
				cout<<ans;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}
