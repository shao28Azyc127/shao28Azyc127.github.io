#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int memhead=0;
map<string,vector<pair<string,pair<int,int> > > > lst;
int cnt=0;
int asz[110];
map<string,int> dy;
map<string,int> dq;
map<string,string> yd;
map<string,pair<int,int> > lr;
void addstruct(){
	string name;
	int n;
	cin >> name >> n;
	int lasto=0,lasts=0,maxl=-1;
	fr(i,1,n){
		string type;
		string na;
		cin >> type >> na;
		int len=dy[type];
		
		maxl=max(maxl,len);
		
		if(i!=1)
			lasto=((lasto+lasts+len-1)/len)*len;
		lst[name].push_back({na,{lasto,len}});
		lasts=len;
		
		//cout << lasto+len-1 << " ";
	}
	//cout << endl;
	dy[name]=((lasto+lasts+maxl-1)/maxl)*maxl;
	dq[name]=maxl;
	cout << dy[name] << " " << maxl << endl;
}
void newstruct(){
	string type,name;
	cin >> type >> name;
	yd[name]=type;
	
	cout << memhead << endl;
	int tmp=memhead;
	memhead=((memhead+dy[type]+dq[type]-1)/dq[type])*dq[type];
	lr[name]={tmp,memhead-1};
	//cout << "lr: " << tmp << "," << memhead-1  << endl;
}
void visit(){
	string s;
	cin >> s;
	bool flag=0;
	for(auto x:s)if(x=='.')flag=1;
	if(flag){
		string tmp="",tmp2="";
		fr(i,0,s.size()-1){
			if(s[i]=='.'){
				fr(j,i+1,s.size()-1)tmp2+=s[j];
				break;
			}
			tmp+=s[i];
		}
		string ttmp=tmp;
		tmp=yd[tmp];
		//cout << tmp << " " << tmp2 << endl;
		for(auto t:lst[tmp]){
			if(t.first==tmp2){
				cout << lr[ttmp].first +t.second.first << endl;
			}
		}
	}
	else{
			cout << lr[s].first << endl;
	}
}
void visitmem(){
	int ad;
	cin >> ad;
	bool flag=1;
	for(auto t:lr){
		if(t.second.first<=ad&&t.second.second>=ad){
			flag=0;
			int start=0,len=0;
			string name;
			string ttmp=yd[t.first];
			for(auto tt:lst[ttmp]){
				//cout <<  t.second.first+tt.second.first << " ";
				if(t.second.first+tt.second.first<=ad){
					start=t.second.first+tt.second.first,len=tt.second.second;
					name=tt.first;
				}
			}
			//cout << start << " " << len << endl;
			if(start<=ad&&start+len-1>=ad)
				cout << t.first << "." << name << endl;
			else cout << "ERR" << endl;
			break;
		}
	}
	if(flag)cout << "ERR" << endl;
}
signed main(){
	dy["byte"]=1,dy["short"]=2,dy["int"]=4,dy["long"]=8;
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		int op;
		cin >> op;
		if(op==1){
			addstruct();
		}
		if(op==2){
			newstruct();
		}
		if(op==3){
			visit();
		}
		if(op==4){
			visitmem();
		}
	}
	return 0;
}
