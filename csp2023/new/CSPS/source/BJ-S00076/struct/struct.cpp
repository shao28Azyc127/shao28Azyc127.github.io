#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll cnt=4;
map<string,ll>str;
struct node{
	ll id;string name;
};
ll d[N];

struct va{
	ll id,place;string name;
};vector<va>v;
vector<node>g[N];
bool vis[N*4];
ll last=0;
void clean(ll p){
	if(p==1||p==2||p==3||p==4){
		last=last+abs(last-d[p])%d[p];
		ll tmp=last;
		for(;last<=tmp+d[p]-1;last++){vis[last]=1;}last=tmp+d[p];
	}
	else{
		for(int i=0;i<g[p].size();i++){
			//cout<<'D'<<d[p]<<"START";
			last=last+abs(last-d[p])%d[p];
			ll tmp=last;
			for(;last<=tmp+d[g[p][i].id]-1;last++){/*cout<<last<<' ';*/vis[last]=1;}last=tmp+d[p];
			//cout<<"OK"<<endl;
		}
	}
}
string find(string &s){
	ll len=s.length();string t="";int i=0;
	for(i=0;i<len;i++){
		if(s[i]=='.')break;
		t+=s[i];
	}
	if(i==len)s="";
	else s=s.substr(i+1);
	return t;
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
//~ string t;cin>>t;
//~ cout<<find(t);return 0;
	ll n;cin>>n;
	str["byte"]=1;d[1]=1;
	str["int"]=3;d[2]=2;
	str["short"]=2;d[3]=4;
	str["long"]=4;d[4]=8;
	for(int i=1;i<=n;i++){
		ll opt;scanf("%lld",&opt);
		if(opt==1){
			ll k;
			string s;cin>>s>>k;
			str[s]=++cnt;d[cnt]=0;
			for(int j=1;j<=k;j++){
				string t,name;
				cin>>t>>name;
				//~ if(t=="byte"){
					//~ g[cnt].push_back({1,name});
					//~ d[cnt]=max(d[cnt],1ll);
				//~ }
				//~ else if(t=="short"){
					//~ g[cnt].push_back({2,name});
					//~ d[cnt]=max(d[cnt],2ll);
				//~ }
				//~ else if(t=="int"){
					//~ g[cnt].push_back({3,name});
					//~ d[cnt]=max(d[cnt],4ll);
				//~ }
				//~ else if(t=="long"){
					//~ g[cnt].push_back({4,name});
					//~ d[cnt]=max(d[cnt],8ll);
				//~ }
				//~ else{
					ll p=str[t];
					g[cnt].push_back({p,name});
					d[cnt]=max(d[cnt],d[p]);
				//~ }
			}
			//sz[cnt]=g[cnt].size()*d[cnt];
			printf("%lld %lld\n",g[cnt].size()*d[cnt],d[cnt]);
			//~ cout<<g[cnt].size()*d[cnt]<<' '
		}
		if(opt==2){
			string type,name;cin>>type>>name;
			ll p=str[type];
			last=last+abs(last-d[p])%d[p];
			printf("%lld\n",last);
			v.push_back({p,last,name});
			clean(p);
			//~ if(p==1||p==2||p==3||p==4){
				//~ clean(p);
			//~ }
			//~ else{
				//~ for(int i=0;i<g[p].size();i++){
					//~ clean(g[p][i].id);
				//~ }
			//~ }
			
		}
		if(opt==3){
			string s;cin>>s;
			ll len=0;
			string t=find(s);ll p,wh=0;
			for(int i=0;i<(int)v.size();i++){
				if(v[i].name==t){p=v[i].id;wh=v[i].place;break;}
			}
			if(p<=4){
				printf("%lld\n",wh);continue;
			}
			t=find(s);
			for(int i=0;i<g[p].size();i++){
				//cout<<wh<<' '<<d[g[p][i].id]<<' '<<d[p]<<endl;
				wh=wh+abs(wh-d[p])%d[p];
				if(g[p][i].name==t){
					printf("%lld\n",wh);break;
				}
				else{
					wh+=d[p];
				}
			}
		}
		if(opt==4){
			ll x;scanf("%lld",&x);
			if(x>=4*N){printf("ERR\n");}
			else if(vis[x]==0){printf("ERR\n");}
			else{
				string ans="";ll wh=0;
				for(int i=0;i<(int)v.size();i++){
					wh=v[i].place;
					if(v[i].id<=4)
					{
						if(v[i].place<=x&&x<v[i].place+d[v[i].id]){
							cout<<v[i].name<<endl;
							break;
						}
					}
					else{
						bool flag=0;
						for(int j=0;j<g[v[i].id].size();j++){
							wh=wh+abs(wh-d[v[i].id])%d[v[i].id];
							//cout<<wh<<' '<<"PO<<"<<endl;
							if(wh<=x&&x<wh+d[g[v[i].id][j].id]){
								cout<<v[i].name<<"."<<g[v[i].id][j].name<<endl;
								flag=1;break;
							}
							else{
								wh+=d[v[i].id];
							}
						}
						if(flag)break;
					}
				}
			}
		}
	}
	return 0;
}
//~ 10
//~ 1 a 2
//~ short a
//~ int b
//~ 2 a x

