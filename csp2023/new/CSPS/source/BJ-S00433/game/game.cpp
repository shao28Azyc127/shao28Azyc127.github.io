#include<bits/stdc++.h>
using namespace std;
int d[4000010],f[4000010],cnt;
map<pair<int,int>,int> mp;
struct node{
	int l,r,mid;
}m[4000010];
bool cmp(node x,node y){
	if(x.r!=y.r) return x.r<y.r;
	else return x.r-x.l<y.r-y.l;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	string t,s;
	cin>>n;
	cin>>t;
	s+="(#";
	for(int i=0;i<n;++i) s+=t[i],s+='#';
	s+=")";
	int zhong=2,kuan=1;
	for(int i=2;i<s.size()-1;++i){
		d[i]=max(1,min(d[zhong-i+zhong],zhong+kuan-i));
		while(s[i+d[i]]==s[i-d[i]]) d[i]++;
		if(s[i+d[i]]!=s[i-d[i]]) d[i]--;
		if(i+d[i]>zhong+kuan) zhong=i,kuan=d[i];
		if(s[i]=='#'&&d[i]>1) m[++cnt]=(node){i-d[i],i+d[i],i};
	}
	long long ans=0;
	for(int i=1;i<=cnt;++i){
		//cout<<i<<" "<<m[i].l<<" "<<m[i].r<<" "<<m[i].mid<<"\n";
		for(int j=m[i].mid+1;j<=m[i].r;++j)
			f[j]=1+f[m[i].mid-j+m[i].mid];
	}
	for(int i=0;i<s.size();++i) if(s[i]=='#') ans+=f[i];//cout<<i<<" "<<f[i]<<"\n";
	cout<<ans;
	return 0;
}