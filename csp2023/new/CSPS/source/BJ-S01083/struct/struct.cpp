#include <bits/stdc++.h>
#define int long long
using namespace std;

#define gc getchar
#define pc putchar

inline int read(){
	int x=0; bool f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return f?x:-x;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}

map<string,int> mp,fnd;
int num=3,tot=0,cnt=0;

int getnum(string s){
	if(s=="byte") return 0;
	if(s=="int") return 2;
	if(s=="short") return 1;
	if(s=="long") return 3;
	if(!mp[s]) mp[s]=++num;
	return mp[s];
}

struct Tpe{vector<pair<int,string> > vec;}sample[10000005];
struct Node{
	int maxn,Tpe,StartAddr,siz,flag;
	string nam;
	vector<pair<int,string> > id;
	bool operator<(const Node &o)const{
		return StartAddr==o.StartAddr?siz>o.siz:StartAddr<o.StartAddr;
	}
}b[1000005];

bitset<100000005>vis;
vector<int> used[10005];

int Creat(int x,bool flag){
	used[x].push_back(++cnt);
	b[cnt].Tpe=x,b[cnt].flag=flag;
	int cntt=cnt;
	if(x<=3){
		b[cnt].maxn=(1<<x);
		return cnt;
	}
	for(int i=0;i<sample[x].vec.size();i++)	b[cntt].id.push_back(make_pair(Creat(sample[x].vec[i].first,flag),sample[x].vec[i].second));
	for(pair<int,string> i:b[cntt].id) b[cntt].maxn=max(b[cntt].maxn,b[i.first].maxn);
	return cntt;
}
int Give(int x,int tot){
	b[x].StartAddr=tot;
	int cur=tot,tmp=cur,siz=0;
	if(b[x].Tpe<=3) return b[x].siz=(1<<b[x].Tpe);
	for(pair<int,string> i:b[x].id){
		b[i.first].nam=i.second;
		while(siz%b[i.first].maxn!=0) vis[++cur]=1,siz++;
		int ad=Give(i.first,cur);
		cur+=ad,siz+=ad;
	}
	while(siz%b[x].maxn!=0) vis[++cur]=1,siz++;
	return b[x].siz=cur-tmp;
}
int getsiz(int x){
	if(b[x].Tpe<=3) return b[x].siz=(1<<b[x].Tpe);
	for(pair<int,string> i:b[x].id){
		while(b[x].siz%b[i.first].maxn!=0) b[x].siz++;
		b[x].siz+=getsiz(i.first);
	}
	while(b[x].siz%b[x].maxn!=0) b[x].siz++;
	return b[x].siz;
}

signed main(){
	// system("diff struct.out struct1.ans"); return 0;
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T; cin>>T;
	b[0].maxn=1;
	b[1].maxn=2;
	b[2].maxn=4;
	b[3].maxn=8;
	while(T--){
		int op,k; string s,t;
		cin>>op;
		if(op==1){
			cin>>s>>k;
			int i=getnum(s);
			for(int j=1;j<=k;j++){
				string x,y; cin>>x>>y;
				sample[i].vec.push_back(make_pair(getnum(x),y));
			}
			int nw=tot,NW=cnt;
			int tmp=Creat(i,0);
			int res=getsiz(tmp),mx=b[tmp].maxn;
			cout<<res<<' '<<mx<<'\n';
		}
		if(op==2){
			cin>>s>>t;
			int i=getnum(s);
			int tmp=Creat(i,1);
			fnd[t]=tmp;
			cout<<tot<<'\n';
			b[tmp].nam=t;
			tot+=Give(tmp,tot);
		}
		if(op==3){
			cin>>s;
			string t;
			int curid=0,curAddr=0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='.'){
					if(!curid){
						curid=fnd[t];
					}
					else{
						for(pair<int,string> num:b[curid].id) if(num.second==t){
							curid=num.first;
							break;
						}
					}
					t="";
				}
				else t+=s[i];
			}
			if(!curid){
				curid=fnd[t];
			}
			else{
				for(pair<int,string> num:b[curid].id) if(num.second==t){
					curid=num.first;
					break;
				}
			}
			cout<<b[curid].StartAddr<<'\n';
		}
		if(op==4){
			cin>>k;
			// for(int i=0;i<30;i++) cout<<vis[i]; cout<<'\n';
			if(vis[k]==1 || k>tot){
				cout<<"ERR\n";
				continue;
			}
			vector<string> vec;
			sort(b+1,b+1+cnt);
			bool Flag=0;
			for(int i=1;i<=cnt;i++){
				if(b[i].StartAddr<=k && b[i].StartAddr+b[i].siz>=k && b[i].flag) vec.push_back(b[i].nam);
				if(b[i].StartAddr>k){
					if(b[i-1].Tpe>3 || !vec.size()) cout<<"ERR\n";
					else{
						cout<<vec[0];
						for(int i=1;i<vec.size();i++) cout<<"."<<vec[i];
						cout<<'\n';
					}
					Flag=1;
					break;
				}
			}
			if(!Flag){
				if(b[cnt].Tpe>3 || !vec.size()) cout<<"ERR\n";
				else{
					cout<<vec[0];
					for(int i=1;i<vec.size();i++) cout<<"."<<vec[i];
					cout<<'\n';
				}
				Flag=1;
			}
		}
	}
}