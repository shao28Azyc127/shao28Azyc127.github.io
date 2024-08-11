#include<bits/stdc++.h>
using namespace std;
int dis[100000];//dis[i]为第i个站点到第i-1个站点的距离
int n,d;
struct station{
	int num,cost;
}s[100000];
int mmin[100000];//油价第i小的站
long long int dis1[100000];//第i个站点到终点距离
long long int cnt1=0,ans=0;//ans:答案cnt1:多余的油
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<=n-1;i++)cin>>dis[i];
	for(int i=0;i<n;i++){
		cin>>s[i].cost;s[i].num=i;
	}
	dis1[n-1]=0;
	for(int i=n-2;i>=0;i--){
		dis1[i]=dis1[i+1]+dis[i+1];
	}
	int mini=0,cnt=0;mmin[0]=n-1;
	while(mmin[max(cnt-1,0)]!=0){
		for(int i=0;i<mmin[max(cnt-1,0)];i++){
			if(s[i].cost<s[mini].cost)mini=i;
		}
		mmin[cnt]=s[mini].num;cnt++;mini=0;
	}
	int d1;
    for(cnt=cnt;cnt>=0;cnt--){
		if(cnt>0)d1=dis1[mmin[cnt]]-dis1[mmin[cnt-1]];
		else d1=dis1[mmin[cnt]];
		d1-=cnt1;cnt1=0;
		ans+=s[mmin[cnt]].cost*(d1/d+min(1,d1%d));
		if(d1%d!=0)cnt1=d-d1%d;
//		cout<<ans<<' '<<cnt1<<endl;
	}
	cout<<ans;
	return 0;
}
