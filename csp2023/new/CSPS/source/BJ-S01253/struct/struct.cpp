#include<bits/stdc++.h>
using namespace std;

struct qqq{
	string s;
	long long l;
	int mx;
	int cnt;
	string c[105];
	int a[105];
}p[105];
int len=4;

int q;
int op;

map<string,int> mp;

string nms[105];
int opt[105],lp;
int lenall;

string f[105];
int lf,fxy;

long long xy,sum;

void init(){
	p[1].s="byte";
	p[1].l=1;
	p[1].mx=1;
	mp["byte"]=1;
	p[2].s="short";
	p[2].l=2;
	p[2].mx=2;
	mp["short"]=2;
	p[3].s="int";
	p[3].l=4;
	p[3].mx=4;
	mp["int"]=3;
	p[4].s="long";
	p[4].l=8;
	p[4].mx=8;
	mp["long"]=4;
	return;
}

string tmp,ans;

void dfs(int pxy){
	if(pxy<=4){
		return;
	}
	for(int i=1;i<=p[pxy].cnt;++i){
		if(p[pxy].c[i]==f[fxy]){
			++fxy;
			dfs(p[pxy].a[i]);
			return;
		}
		sum+=p[pxy].mx;
	}
	return;
}

bool dfs2(int pxy){
	if(pxy<=4){
		if(xy<sum+p[pxy].l){
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=p[pxy].cnt;++i){
		if(i==p[pxy].cnt || sum+p[pxy].mx>xy){
			ans+='.';
			ans+=p[pxy].c[i];
			return dfs2(p[pxy].a[i]);
		}
		sum+=p[pxy].mx;
	}
	return 0;
}

int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	init();
	cin>>q;
	while(q--){
		cin>>op;
		if(op==1){
			++len;
			cin>>p[len].s>>p[len].cnt;
			mp[p[len].s]=len;
			for(int i=1;i<=p[len].cnt;++i){
				cin>>tmp>>p[len].c[i];
				p[len].a[i]=mp[tmp];
				p[len].mx=max(p[len].mx,p[mp[tmp]].mx);
			}
			p[len].l=0;
			for(int i=1;i<=p[len].cnt;++i){
				if(p[len].a[i]<=4){
					p[len].l+=p[len].mx;
				}
				else{
					p[len].l+=p[p[len].a[i]].l;
				}
			}
			cout<<p[len].l<<' '<<p[len].mx<<'\n';
		}
		if(op==2){
			++lp;
			cin>>tmp>>nms[lp];
			opt[lp]=mp[tmp];
			cout<<lenall<<'\n';
			lenall+=p[opt[lp]].l;
		}
		if(op==3){
			cin>>tmp;
			lf=1;
			f[1]="";
			for(int i=0;i<(int)(tmp.size());++i){
				if(tmp[i]=='.'){
					++lf;
					f[lf]="";
				}
				else{
					f[lf]+=tmp[i];
				}
			}
			fxy=1;
			sum=0;
			for(int i=1;i<=lp;++i){
				if(nms[i]==f[fxy]){
					++fxy;
					dfs(opt[i]);
					break;
				}
				sum+=p[opt[i]].l;
			}
			cout<<sum<<'\n';
		}
		if(op==4){
			cin>>xy;
			sum=0;
			ans="";
			for(int i=1;i<=lp;++i){
				if(i==lp || sum+p[opt[i]].l>xy){
					ans+=nms[i];
					if(dfs2(opt[i])==0){
						ans="ERR";
					}
					break;
				}
				sum+=p[opt[i]].l;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
