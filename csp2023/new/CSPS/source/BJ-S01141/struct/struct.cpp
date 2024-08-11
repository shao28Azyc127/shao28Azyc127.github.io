#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=110;
int n;
struct node{
	int dq;
	ll len;
	string name;
	string sn[110],lx[110];
	ll s[110],scnt=0,op[110],ed[110]={-1};
}t[110];
struct have{
	ll op,ed;
	string lx,name;
}H[110];
int tcnt,hcnt;
ll getnext(ll x,ll y){
	for(ll i=x+1;i<=x+7;i++){
		if(i%y==0)return i;
	}
	return 0;
}
map<string,int>mp;
string divv[110];
int divlen;
void divide(string str){
	divlen=0;
	string s0="";
	for(int i:str){
		if(i=='.'){
			divv[++divlen]=s0;
			s0="";
		}else s0+=i;
	}
	divv[++divlen]=s0;
}
void dfs(int next,ll re,string lxx){
	//cout<<next<<' '<<re<<' '<<lxx<<'\n';
	int kk=mp[lxx];
	if(next==divlen){
		for(int i=1;i<=t[kk].scnt;i++){
			if(t[kk].sn[i]==divv[next]){
				cout<<re+t[kk].op[i]<<'\n';return ;
			}
		}
	}
	for(int i=1;i<=t[kk].scnt;i++){
		//cout<<t[kk].sn[i]<<' '<<divv[next]<<'\n';
		if(t[kk].sn[i]==divv[next]){
			dfs(next+1,re+t[kk].op[i],t[kk].lx[i]);
		}
	}
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    ll pla=-1;
    for(int i=1;i<=n;i++){
		int op;cin>>op;
		if(op==1){
			tcnt++;
			cin>>t[tcnt].name;
			int k;cin>>k;t[tcnt].scnt=k;
			int duiqi=0;
			mp[t[tcnt].name]=tcnt;
			for(int j=1;j<=k;j++){
				string s1,s2;
				cin>>s1>>s2;
				if(s1=="byte"){
					t[tcnt].s[j]=1;
					t[tcnt].sn[j]=s2;
					duiqi=max(duiqi,1);
				}
				else if(s1=="short"){
					t[tcnt].s[j]=2;
					t[tcnt].sn[j]=s2;
					duiqi=max(duiqi,2);
				}
				else if(s1=="int"){
					t[tcnt].s[j]=3;
					t[tcnt].sn[j]=s2;
					duiqi=max(duiqi,4);
				}
				else if(s1=="long"){
					t[tcnt].s[j]=4;
					t[tcnt].sn[j]=s2;
					duiqi=max(duiqi,8);
				}
				else{
					int kk=mp[s1];
					t[tcnt].s[j]=5;
					t[tcnt].lx[j]=s1;
					t[tcnt].sn[j]=s2;
					duiqi=max(duiqi,t[kk].dq);
				}
			}
			t[tcnt].dq=duiqi;
			int nowop=0;
			for(int j=1;j<=k;j++){
				//cout<<j<<' '<<nowop<<'\n';
				t[tcnt].op[j]=nowop;
				if(t[tcnt].s[j]<=4)nowop+=duiqi;
				else{
					int kk=mp[t[tcnt].lx[j]];
					//cout<<kk<<'\n';
					nowop+=t[kk].len;
				}
			}
			t[tcnt].len=nowop;
			cout<<t[tcnt].len<<' '<<t[tcnt].dq<<'\n';
		}
		if(op==2){
			string s1,s2;
			cin>>s1>>s2;
			hcnt++;
			H[hcnt].name=s2,H[hcnt].lx=s1;
			if(s1=="byte"){
				int opp=getnext(pla,1);
				H[hcnt].op=opp,H[hcnt].ed=opp+0;
				pla=opp+1;
			}
			else if(s1=="short"){
				int opp=getnext(pla,2);
				H[hcnt].op=opp,H[hcnt].ed=opp+1;
				pla=opp+2;
			}
			else if(s1=="int"){
				int opp=getnext(pla,4);
				H[hcnt].op=opp,H[hcnt].ed=opp+3;
				pla=opp+4;
			}
			else if(s1=="long"){
				int opp=getnext(pla,8);
				H[hcnt].op=opp,H[hcnt].ed=opp+7;
				pla=opp+8;
			}
			else{
				int kk=mp[s1];
				int opp=getnext(pla,t[kk].dq);
				H[hcnt].op=opp,H[hcnt].ed=opp+t[kk].len-1;
				pla=opp+t[kk].len;
			}
			cout<<H[hcnt].op<<'\n';
		}
		if(op==3){
			string str;cin>>str;
			divide(str);
			if(divlen==1){
				for(int j=1;j<=hcnt;j++){
					if(H[j].name==str){
						cout<<H[j].op<<'\n';
					}
				}
				continue;
			}
			for(int j=1;j<=hcnt;j++){
				if(H[j].name==divv[1]){
					dfs(2,H[j].op,H[j].lx);
				}
			}
			//cout<<"Yeah!";
		}
		if(op==4){
			ll x;cin>>x;
			cout<<"ERR\n";
		}
	}
    return 0;
}
