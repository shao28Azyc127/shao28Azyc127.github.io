#include<bits/stdc++.h>
using namespace std;
long long n;
int opt;
struct tp{
	long long sonsn;
	vector<string> sons;//to name
};
struct nm{
	string name;
	long long space;
};
map<string,tp> types;
map<string,string> name2type;
vector<nm> defed;
bool isbty(string ttype){
	if(ttype=="long"||ttype=="int"||ttype=="short"||ttype=="byte")return 1;
	return 0;
}
long long type2space(string tname){
	string ttype=name2type[tname];
	if(ttype=="long")return 8;
	if(ttype=="int")return 4;
	if(ttype=="short")return 2;
	if(ttype=="byte")return 1;
	int maxusize=0;
	tp unit=types[ttype];
	for(long long i = 0;i < unit.sonsn;i++){
		long long tmax=type2space(name2type[unit.sons[i]]);
		if(tmax>maxusize)maxusize=tmax;
	}
	return maxusize*unit.sonsn;
}
long long findspace(string path,long long nowspace){
	long long i;
	string fname,npath;
	for(i = 0;i < (long long)path.size();i++){
		if(path[i]=='.')break;
		fname[i]=path[i];
	}
	if(i==(long long)path.size())return nowspace;
	long long nspace=nowspace+type2space(name2type[fname]);
	i++;
	for(int j = 0;i < (long long)path.size();i++,j++){
		npath[j]=path[i];
	}
	return findspace(npath,nspace);
}
string findpath(string nowpath,string nowpos,long long leftspace){
	long long sonsn=types[name2type[nowpos]].sonsn,i,space=leftspace;
	for(i = 0;i <= sonsn;i++){
	    if(space<(type2space(name2type[nowpos])/types[name2type[nowpos]].sonsn))break;
		space-=(type2space(name2type[nowpos])/types[name2type[nowpos]].sonsn);
	}
	if(type2space(name2type[types[name2type[nowpos]].sons[i]])>space){
		if(isbty(name2type[name2type[types[name2type[nowpos]].sons[i]]])){
			return nowpath+"."+types[name2type[nowpos]].sons[i];
		}else{
		    return findpath(nowpath+"."+types[name2type[nowpos]].sons[i],types[name2type[nowpos]].sons[i],space);
		}
	}else {
		return "ERR";
	}
}
int main(){
	ios::sync_with_stdio(false);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    while(n--){
		scanf("%d",&opt);
		if(opt==1){
			string s,t,n;
			long long k;
			tp tmp;
			tmp.sonsn=k;
			while(k--){
				cin>>t>>n;
				name2type[n]=t;
				tmp.sons.push_back(n);
			}
			types[s]=tmp;
		}else if(opt==2){
			string t,n;
			cin>>t>>n;
			name2type[n]=t;
			nm tmp;
			tmp.name=n;
			tmp.space=type2space(t);
			defed.push_back(tmp);
		}else if(opt==3){
			string path;
			cin>>path;
			long long i,bef=0;
	        string fname;
	        for(i = 0;i < (long long)path.size();i++){
	            if(path[i]=='.')break;
	        	fname[i]=path[i];
	        }
	        for(i = 0;i <= (long long)defed.size();i++){
				if(fname==defed[i].name)break;
				bef+=defed[i].space;
			}
			cout<<bef+findspace(path,0)<<endl;
		}else{
			long long space,i;
			cin>>space;
	        for(i = 0;i <= (long long)defed.size();i++){
				if(space<defed[i].space)break;
				space-=defed[i].space;
			}
			/*string ans=findpath(defed[i].name,defed[i].name,space);
			if(ans[(long long)ans.size()-1l]=='R'){
				cout<<"ERR\n";
			}else{*/
				cout<<findpath(defed[i].name,defed[i].name,space)<<endl;
			//}
		}
	}
    return 0;
}