#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<string,string> pss;
typedef vector<pss> vps;
typedef long long ll;
typedef pair<string,ll> psl;
typedef vector<psl> vpl;
typedef map<string,int> msi;
int n;
vps sts[105];
vpl v[105];
int stsn,vn;
ll dizhi = 0ll;
msi lo;
map<string, pair<int,int> > used;
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	
	scanf("%d",&n);
	used["byte"] = make_pair(1,1);
	used["short"] = make_pair(2,2);
	used["int"] = make_pair(4,4);
	used["long"] = make_pair(8,8);
	for(int i=1;i<=n;i++){
		int opt;
		scanf("%d",&opt);
		if(opt == 1){
			string s,t,na;
			int k;
			cin>>s>>k;
			stsn++;
			lo[s] = stsn;
			int duiqi;
			duiqi = 0;
			for(int j=1;j<=k;j++){
				cin>>t>>na;
				sts[stsn].push_back(make_pair(t,na));
				duiqi = max(duiqi,used[t].second);
			}
			printf("%d %d\n",k*duiqi,duiqi);
		}else if(opt == 2){
			string t,na;
			cin>>t>>na;
			int tmp = lo[t];
			vn++;
			int sz = sts[tmp].size();
			printf("%lld\n",dizhi);
			for(int j=0;j<sz;j++){
				v[vn].push_back(make_pair(sts[tmp][i].second,dizhi));
				dizhi += used[sts[tmp][i].first].first;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
