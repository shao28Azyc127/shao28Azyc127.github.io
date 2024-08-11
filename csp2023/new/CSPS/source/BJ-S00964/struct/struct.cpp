#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define FileIO(f) freopen(f".in","r",stdin),freopen(f".out","w",stdout)
struct yuansu{
	string nam;
	int ty,id,yq;
	ll st,ed;
}s[1000005];
struct jgt{
	string nam;
	int yq,k;
	ll siz;
	map<string,int>mt;
	vector<yuansu>ys;
	vector<pii>pr;
}b[1000005];
int n,cntb=0,cnts=0,fg;
vector<pii>pr;
bool chk(pii x){return x.fi<fg;}
bool cmp(pii x,pii y){return x.fi<y.fi;}
string str;
map<string,int>ms,ma;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	FileIO("struct");
	int i,k,op;
	ll x,y,z;
	cin>>n;
	while(n--){
		cin>>op;
		if(op==1){
			cntb++;
			cin>>b[cntb].nam>>b[cntb].k;
			ms[b[cntb].nam]=cntb;
			for(i=0;i<b[cntb].k;i++){
				cin>>str;
				if(str=="byte")b[cntb].ys[i].ty=1,
					b[cntb].ys[i].id=1,
					b[cntb].ys[i].yq=1;
				else if(str=="short")b[cntb].ys[i].ty=1,
					b[cntb].ys[i].id=2,
					b[cntb].ys[i].yq=2;
				else if(str=="int")b[cntb].ys[i].ty=1,
					b[cntb].ys[i].id=3,
					b[cntb].ys[i].yq=4;
				else if(str=="long")b[cntb].ys[i].ty=1,
					b[cntb].ys[i].id=4,
					b[cntb].ys[i].yq=8;
				else b[cntb].ys[i].ty=2,b[cntb].ys[i].id=ms[str],
					b[cntb].ys[i].yq=b[ms[str]].yq;
				cin>>b[cntb].ys[i].nam;
				ms[b[cntb].ys[i].nam]=i;
			}
			b[cntb].yq=0;
			for(i=0;i<b[cntb].k;i++)
				b[cntb].yq=max(b[cntb].yq,b[cntb].ys[i].yq);
			b[cntb].ys[0].st=0;
			b[cntb].ys[0].ed=b[cntb].ys[0].yq;
			b[cntb].pr[0]=mp(b[cntb].ys[0].st,0);
			for(i=1;i<b[cntb].k;i++){
				b[cntb].ys[i].st=(b[cntb].ys[i-1].ed
					/(b[cntb].ys[i].yq)
					*(b[cntb].ys[i].yq)
					+(b[cntb].ys[i].yq));
				b[cntb].ys[i].ed=b[cntb].ys[i].st+b[cntb].ys[i].yq-1;
				b[cntb].pr[i]=mp(b[cntb].ys[i].st,i);
			}b[cntb].siz=(b[cntb].ys[b[cntb].k-1].ed
				/(b[cntb].yq)*(b[cntb].yq)+(b[cntb].yq));
			sort(b[cntb].pr.begin(),b[cntb].pr.end(),cmp);
			cout<<b[cntb].siz<<" "<<b[cntb].yq<<"\n";
		}else if(op==2){
			cin>>str;cnts++;
			if(str=="byte")s[cnts].ty=1,s[cnts].id=1,s[cnts].yq=1;
			else if(str=="short")s[cnts].ty=1,s[cnts].id=2,s[cnts].yq=2;
			else if(str=="int")s[cnts].ty=1,s[cnts].id=3,s[cnts].yq=4;
			else if(str=="long")s[cnts].ty=1,s[cnts].id=4,s[cnts].yq=8;
			else s[cnts].ty=2,s[cnts].id=ms[str],s[cnts].yq=b[ms[str]].yq;
			cin>>s[cnts].nam;ma[s[cnts].nam]=cnts;
			if(s[cnts].ty==1){
				s[cnts].st=(s[cnts-1].ed/s[cnts].yq*s[cnts].yq+s[cnts].yq);
				s[cnts].ed=s[cnts].st+s[cnts].yq-1;
			}else if(s[cnts].ty==2){
				s[cnts].st=(s[cnts-1].ed/s[cnts].yq*s[cnts].yq+s[cnts].yq);
				s[cnts].ed=s[cnts].st+b[s[cnts].id].siz-1;
			}
			pr.push_back(mp(s[cnts],cnts));
			sort(pr.begin(),pr.end(),cmp);
			cout<<s[cnts].st<<"\n";
		}else if(op==3){
			string str1="";
			cout<<str;
			int sz=str.size(),id;
			ll ps=-1;
			for(k=0;k<sz;k++){
				if(str[k]=='.'){
					if(ps==-1)id=s[ma[str1]].id,ps=s[ma[str1]].st;
					else id=b[id].ys[b[id].mt[str1]].id,
						ps=b[id].ys[b[id].mt[str1]].st;
					str1="";
				}else str1+=str[k];
			}
			if(ps==-1)ps=s[ma[str1]].st;
			else ps=b[id].ys[b[id].mt[str1]].st;
			cout<<ps<<"\n";
		}
	}
	return 0;
}