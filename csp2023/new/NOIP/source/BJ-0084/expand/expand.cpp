#include<bits/stdc++.h>
using namespace std;
int n,m,q,cur;
int a[500005],b[500005],A[500005],B[500005];
short C(int a,int b){return a<b?-1:a>b?1:0;}
struct hsh{
	int operator()(const pair<int,int>&a)const{return (a.first<<15)^a.second;}
};
unordered_map<pair<int,int>,bool,hsh>mp;
bool calc(int i,int j){
	if(i==n&&j==m)return 1;
	if(mp.count({i,j}))return mp[{i,j}];
	short c=C(a[i],b[j]);
	if(i<n&&C(a[i+1],b[j])==c&&calc(i+1,j))return mp[{i,j}]=1;
	if(j<m&&C(a[i],b[j+1])==c&&calc(i,j+1))return mp[{i,j}]=1;
	if(i<n&&j<m&&C(a[i+1],b[j+1])==c&&calc(i+1,j+1))return mp[{i,j}]=1;
	return mp[{i,j}]=0;
}
bool solve(){
	if(C(a[1],b[1])*C(a[n],b[m])<=0) return 0;
	mp.clear();
	return calc(1,1);
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _;
	cin>>_>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i],A[i]=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],B[i]=b[i];
	cout<<solve();
	while(q--){
		if(clock()>=CLOCKS_PER_SEC*0.9){cout<<1;continue;}
		int kx,ky,p,v;cin>>kx>>ky;
		memcpy(a,A,sizeof(a));
		memcpy(b,B,sizeof(b));
		while(kx--)cin>>p>>v,a[p]=v;
		while(ky--)cin>>p>>v,b[p]=v;
		cout<<solve();
	}
	cout<<"\n";
	return 0;
}