#include<bits/stdc++.h>
using namespace std;
map<string,int> sz,hsh;
map<string,int> beg,ed;
vector<string> v[10005],f,vv[10005];
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
    int T,tot=0;
    cin>>T;
    long long add=0;
    sz["byte"]=1,sz["short"]=2,sz["int"]=4,sz["long"]=8;
    while(T--){
        int op,k;
        cin>>op;
        if(op==1){
            int p=1;
            string s,type[105],ss[105];
            cin>>s>>k;
            tot++;
            hsh[s]=tot;
            for(int i=1;i<=k;i++){
                cin>>type[i]>>ss[i];
                f.push_back(s+"."+ss[i]);
                p=max(p,sz[type[i]]);
                v[hsh[s]].push_back(ss[i]);
                vv[hsh[s]].push_back(type[i]);
            }
            // ac
            for(int i=1;i<=k;i++){
                beg[s+"."+ss[i]]=add;
                ed[s+"."+ss[i]]=add+sz[type[i]]-1;
                add+=p;
            }
            sz[s]=p*k;
            cout<<sz[s]<<" "<<p<<'\n';
        }else if(op==2){
            string t,s;
            cin>>t>>s;
                f.push_back(s);
                hsh[s]=++tot;
                beg[s]=add,ed[s]=add+sz[t]-1;
                add+=sz[t];
                v[hsh[s]].push_back(s);
                cout<<beg[s]<<"\n";
        }else if(op==3){
            string s,root="",son="";
            cin>>s;
            cout<<beg[s]<<"\n";
        }else{
        	int k; bool flg=0;
        	cin>>k;
        	for(int i=0;i<f.size();i++){
        		string s=f[i];
        		if(beg[s]<=k && ed[s]>=k){
        			cout<<s<<'\n';
        			flg=1;
        		}
        	}
        	if(!flg) cout<<"ERR\n";
        }
    }
    return 0;
}