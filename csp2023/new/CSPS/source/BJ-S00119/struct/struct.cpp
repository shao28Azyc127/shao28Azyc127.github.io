#include<bits/stdc++.h>
using namespace std;
int n;
map<string,pair<int,int>> mp;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	mp["long"]=make_pair(8,8),mp["int"]=make_pair(4,4),mp["short"]=make_pair(2,2),mp["byte"]=make_pair(1,1);
	cin>>n;
	for(int op,i=1;i<=n;i++){
		cin>>op;
		if(op==1){
			string s,a,b;
			int k;
			cin>>s>>k;
			int ans=0,pos=0;
			for(int i=1;i<=k;i++){
				cin>>a>>b;
				int f=mp[a].first;
				while(pos%f!=0)pos++;
				pos+=mp[a].second;
				ans=max(ans,mp[a].first);
				//cout<<pos<<endl;
			}
			int f=ans;
			while(pos%f!=0)pos++;
			mp[s]=make_pair(ans,pos);
			cout<<pos<<" "<<ans<<endl;
		}
	}
	return 0;
}
