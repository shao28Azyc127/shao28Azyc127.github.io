#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,d,t[N],v[N],cnt=1,s,ans;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++)
		cin>>v[i];
	q.push(v[1]);
	while(cnt<n){
		int x=q.top();
//		cout<<s<<" "<<x<<" "<<ans<<" "<<cnt<<endl;
		if((t[cnt]-s)%d==0){
			ans+=(t[cnt]-s)/d*x;
			cnt++;
			s=0;
			q.push(v[cnt]);
		}else{
			ans+=((t[cnt]-s)/d+1)*x;
			s=d-((t[cnt]-s)%d);
			cnt++;
			q.push(v[cnt]);
		}
	}
	cout<<ans<<endl;
	return 0;
}