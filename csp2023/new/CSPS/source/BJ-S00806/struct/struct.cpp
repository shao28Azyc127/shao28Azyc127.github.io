#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<string,string>,int> recordmp2;//名字为1的结构体 名字为2的变量 在结构体中的3的位置
map<string,pair<int,int> > mp;
map<string,string> rec_type;//记录名字为1的结构体的类型
map<string,int> recordmp;//名字为1的结构体 起始位置为2
map<string,pair<string,int> > p[100005];//名字为1 类型为2 位置为3
bool b[100005];

signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int n,op,cnt=0,now=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op;
		
		if(op==1){
			string s,s1,s2;
			int k;
			cin>>s>>k;
			cnt++;
			int maxx=1,cur=0;
			for(int j=1;j<=k;j++){
				cin>>s1>>s2;
				if(s1=="byte"){
					recordmp2[make_pair(s,s2)]=cur;
					cur++;
				}
				if(s1=="short"){
					cur++;
					recordmp2[make_pair(s,s2)]=cur;
					if(cur%2==0) cur+=1;
					else cur+=2;
					maxx=max(maxx,2ll);
				}
				if(s1=="int"){
					if(cur%4==0) recordmp2[make_pair(s,s2)]=cur;
					else{
						cur+=4-cur%4;
						recordmp2[make_pair(s,s2)]=cur;
					}
					cur+=4;
					maxx=max(maxx,4ll);
				}
				if(s1=="long"){
					if(cur%8==0) recordmp2[make_pair(s,s2)]=cur;
					else{
						cur+=8-cur%8;
						recordmp2[make_pair(s,s2)]=cur;
					}
					cur+=8;
					maxx=max(maxx,8ll);
				}
			}
			if(cur%maxx!=0){
				cur+=maxx-cur%maxx;
			}
			cout<<cur<<" "<<maxx<<"\n";
			mp[s]=make_pair(cur,maxx);
		}
		
		if(op==2){
			string s1,s2;
			cin>>s1>>s2;
			cout<<now<<"\n";
			recordmp[s2]=now;
			rec_type[s2]=s1;
			if(s1=="byte"){
				p[now]=make_pair(s1,s2);
				now++;
			}
			else if(s1=="short"){
				if(now%2==0){
					p[now]=make_pair(s1,s2);
					now+=2;
					p[now-1]=make_pair(s1,s2);
				}
				else{
					now+=3;
					p[now+1]=make_pair(s1,s2);
					p[now+2]=make_pair(s1,s2);
				}
			}
			else if(s1=="int"){
				if(now%4==0){
					for(int j=0;j<=3;j++) {p[now+j]=make_pair(s1,s2);b[now+j]=1;}
					now+=4;
				}
				else{
					now+=4-now%4;
					for(int j=0;j<=3;j++) {p[now+j]=make_pair(s1,s2);b[now+j]=1;}
					now+=4;
				}
			}
			else if(s1=="long"){
				if(now%8==0){
					for(int j=0;j<=7;j++) {p[now+j]=make_pair(s1,s2);b[now+j]=1;}
					now+=8;
				}
				else{
					now+=8-now%8;
					for(int j=0;j<=7;j++) {p[now+j]=make_pair(s1,s2);b[now+j]=1;}
					now+=8;
				}
			}
			else{
				if(now%mp[s1].second!=0) now+=mp[s1].second-now%mp[s1].second;
				for(int j=0;j<=mp[s1].first;j++) p[now+j]=make_pair(s1,s2);
				now+=mp[s1].first;
			}
		}
		
		if(op==3){
			int j;
			long long ls;
			string s,s1,s2;
			cin>>s;
			ls=(long long)s.size();
			for(int j=0;j<ls;j++){
				if(s[j]!='.') s1+=s[j];
				else break;
			}
			if(j==ls-1){
				cout<<recordmp[s1]<<"\n";
				continue;
			}
			j++;
			for(int k=j+1;k<ls;k++){
				s2+=s[k];
			}
			cout<<recordmp[s1]+recordmp2[make_pair(rec_type[s1],s2)]<<"\n";
		}
	}
	return 0;
}
