#include<bits/stdc++.h>
#define int long long
using namespace std;
int sz[115],dq[115];
struct edg{
	int l,r,v;
};
vector<edg>edge[115];
string var_name[115];
vector<string>son_name[115];
map<string,int>son_id[115];
map<string,int>str_id;
map<string,int>var_id;
int varcnt=0;
int pos[115],var_typ[115];
int idcnt=4;
int NOW=0;
vector<string>vec;
signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	string tmp="byte";
	str_id[tmp]=1;
	sz[1]=dq[1]=1;
	tmp="short";
	str_id[tmp]=2;
	sz[2]=dq[2]=2;
	tmp="int";
	str_id[tmp]=3;
	sz[3]=dq[3]=4;
	tmp="long";
	str_id[tmp]=4;
	sz[4]=dq[4]=8;
	int n,k,op,addr;
	string s,typ,nam;
	cin>>n;
	for(int _=1;_<=n;_++){
		scanf("%lld",&op);
		if(op==1){
			cin>>s;
			str_id[s]=++idcnt;
			scanf("%lld",&k);
			int now=0;
			for(int j=0;j<k;j++){
				cin>>typ>>nam;
				int id=str_id[typ];
				dq[idcnt]=max(dq[idcnt],dq[id]);
				son_id[idcnt][nam]=j;
				now=(now+dq[id]-1)/dq[id]*dq[id];
				edge[idcnt].push_back((edg){now,now+sz[id]-1,id});
				son_name[idcnt].push_back(nam);
				now=now+sz[id];
			}
			sz[idcnt]=(now+dq[idcnt]-1)/dq[idcnt]*dq[idcnt];
			printf("%lld %lld\n",sz[idcnt],dq[idcnt]);
		}
		if(op==2){
			cin>>typ>>nam;
			int tp=str_id[typ];
			var_id[nam]=++varcnt;
			var_typ[varcnt]=tp;
			var_name[varcnt]=nam;
			NOW=(NOW+dq[tp]-1)/dq[tp]*dq[tp];
			pos[varcnt]=NOW;
			NOW+=sz[tp];
			printf("%lld\n",pos[varcnt]);
		}
		if(op==3){
			cin>>nam;
			int lst=-1;
			vec.clear();
			for(int i=0;i<nam.size();i++){
				if(nam[i]=='.'){
					vec.push_back(nam.substr(lst+1,i-(lst+1)));
					lst=i;
				}
			}
			vec.push_back(nam.substr(lst+1,nam.size()-(lst+1)));
			int id=var_id[vec[0]],ret=pos[id],now_str=var_typ[id];
			for(int i=1;i<vec.size();i++){
				int nxt=son_id[now_str][vec[i]];
				ret+=edge[now_str][nxt].l;
				now_str=edge[now_str][nxt].v;
			}
			printf("%lld\n",ret);
		}
		if(op==4){
			scanf("%lld",&addr);
			int l=1,r=varcnt;
			while(l<r){
				int mid=l+r+1>>1;
				if(pos[mid]<=addr) l=mid;
				else r=mid-1;
			}
			int id=r;
			if(addr<pos[id]||addr>pos[id]+sz[var_typ[id]]-1){
				puts("ERR");
				continue;
			}
			vec.clear();
			vec.push_back(var_name[id]);
			int now_str=var_typ[id],ok=1;
			addr-=pos[id];
			while(now_str>4){
				int l=0,r=edge[now_str].size()-1;
				while(l<r){
					int mid=l+r+1>>1;
					if(edge[now_str][mid].l<=addr) l=mid;
					else r=mid-1;
				}
				if(addr<edge[now_str][r].l||addr>edge[now_str][r].l+sz[edge[now_str][r].v]-1){
					puts("ERR");
					ok=0;
					break;
				}
				vec.push_back(son_name[now_str][r]);
				addr-=edge[now_str][r].l;
				now_str=edge[now_str][r].v;
			}
			if(ok){
				cout<<vec[0];
				for(int i=1;i<vec.size();i++) cout<<"."<<vec[i];
				cout<<endl;
			}
		}
	}
	return 0;
}