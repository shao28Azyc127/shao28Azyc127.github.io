#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cntstr,cntval;
map<string,ll> mpstr,mpval;
map<ll,string>impval;
struct str{
	ll sum,mx;
	map<string,ll> mp;
	map<string,string> mpn;
	map<ll,string> imp;
	vector<ll> type;
}a[10005];
struct val{
	ll struct_type,l,r,cnt,mx;
}b[10005];
ll sum[10005];
bool isstr(string s){
	if(s=="byte")return 1;
	if(s=="short")return 1;
	if(s=="int")return 1;
	if(s=="long")return 1;
	return 0;
}
ll typtobit(string s){
	if(s=="byte")return 1;
	if(s=="short")return 2;
	if(s=="int")return 4;
	if(s=="long")return 8;
	//str
	ll id=mpstr[s];
	return a[id].sum;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;b[0].r=-1;
	for(int i=1;i<=n;++i){
		ll op;cin>>op;
		if(op==1){
			++cntstr;
			ll tot,mx=0;string sr;
			cin>>sr>>tot;
			mpstr[sr]=cntstr;
			for(int j=0;j<tot;++j){
				string typ,nam;cin>>typ>>nam;
				ll now=typtobit(typ);
				a[cntstr].mp[nam]=j;mx=max(mx,now);
				a[cntstr].type.push_back(now);
				a[cntstr].mpn[nam]=typ;
				a[cntstr].imp[j]=nam;
			}
			a[cntstr].mx=mx;a[cntstr].sum=tot*mx;
			cout<<a[cntstr].sum<<' '<<a[cntstr].mx<<'\n';
		}
		if(op==2){
			++cntval;
			string sr,nm;cin>>sr>>nm;
			if(isstr(sr)){
				b[cntval].l=b[cntval-1].r+1;
				mpval[nm]=cntval;impval[cntval]=nm;
				b[cntval].struct_type=-1;
				b[cntval].r=typtobit(sr);
			}
			mpval[nm]=cntval;impval[cntval]=nm;
			b[cntval].struct_type=mpstr[sr];
			b[cntval].l=b[cntval-1].r+1;
			b[cntval].r=b[cntval].l+a[b[cntval].struct_type].sum-1;
			cout<<b[cntval].l<<'\n';
		}
		if(op==3){
			string s;cin>>s;
			if(s.find('.')==s.npos){
				cout<<b[mpval[s]].l<<'\n';
				continue;
			}
			ll id=0,idx=0,ans=0;
			idx=mpval[s.substr(0,s.find('.'))];
			string res=s.substr(s.find('.')+1);res.pop_back();
			ans=b[idx].l;id=b[idx].struct_type;
			for(int i=0;i<a[id].type.size();++i){
				if(a[id].imp[i]==res){cout<<ans+1<<'\n';break;}
				ans+=a[id].mx;
			}
		}
		if(op==4){
			ll idx=0,pid=0;cin>>pid;
			for(idx=1;idx<=cntval;++idx){
				if(b[idx].r>=pid)break;
			}
			if(b[idx].struct_type==-1){
				cout<<impval[idx]<<'\n';continue;
			}
			pid-=b[idx].l;
			string ans=impval[idx];ans+='.';
			idx=b[idx].struct_type;
			for(int i=0;i<a[idx].type.size();++i){
				if(pid<a[idx].mx){
					if(pid>a[idx].type[i]){cout<<"-1\n";break;}
					else{ans+=a[idx].imp[i];cout<<ans<<'\n';break;}
				}
				pid-=a[idx].mx;
			}
		}
	}
	return 0;
}