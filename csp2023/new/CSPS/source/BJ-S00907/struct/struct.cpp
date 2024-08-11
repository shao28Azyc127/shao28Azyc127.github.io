#include <bits/stdc++.h>
#define mp make_pair
#define int long long
using namespace std;
const int N=1e6+10;
int nxtadr;
struct type{
    int big,O;
    vector < pair<string,string> > son;
};
struct opt{
    int beg;
    string typ;
    vector < pair<string,int> > son;
};
//data
map <string,int> Optid;
map <string,type> StrType;
map <int,opt> StrOpt;
//memtree
int cnt,tag[N];
vector <int> Tree[N];
void init(int rt){
    int nowadr=StrOpt[rt].beg;
    for(int i=0;i<StrType[StrOpt[rt].typ].son.size();i++){
        StrOpt[rt].son.push_back(mp(StrType[StrOpt[rt].typ].son[i].second,++cnt));
        StrOpt[cnt].typ=StrType[StrOpt[rt].typ].son[i].first;
        int b=(nowadr-1)/StrType[StrOpt[cnt].typ].O+1;
        if(nowadr!=0){
            b*=StrType[StrOpt[cnt].typ].O;
        }else b=0;
        StrOpt[cnt].beg=b;
        nowadr=StrOpt[cnt].beg+StrType[StrOpt[cnt].typ].big;
        Tree[rt].push_back(cnt);
    }
    tag[rt]=1;
}
string serach(int rt,int x,string ans){
    if(StrOpt[rt].typ=="byte"||StrOpt[rt].typ=="short"||StrOpt[rt].typ=="int"||StrOpt[rt].typ=="long"){
        return ans;
    }
    if(!tag[rt]){
        init(rt);
    }
    //cout<<rt<<endl;
    for(int i=0;i<StrOpt[rt].son.size();i++){
        int v=StrOpt[rt].son[i].second;
        //cout<<StrOpt[rt].son[i].first<<" "<<StrOpt[v].beg<<" "<<StrOpt[v].beg+StrType[StrOpt[v].typ].big<<endl;
        if(x>=StrOpt[v].beg&&x<StrOpt[v].beg+StrType[StrOpt[v].typ].big){
            return serach(v,x,ans+'.'+StrOpt[rt].son[i].first);
        }
    }
    return "";
}
int query(int rt,string s){
    if(s.size()==0){
        return StrOpt[rt].beg;
    }
    if(!tag[rt]){
        //cout<<"Yes"<<endl;
        init(rt);
    }
    string nxt;
    string now;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            for(int j=i+1;j<s.size();j++)
                nxt.push_back(s[j]);
            break;
        }
        now.push_back(s[i]);
    }
    //cout<<StrOpt[rt].son.size()<<" "<<rt<<" "<<StrOpt[rt].beg<<endl;
    for(int i=0;i<StrOpt[rt].son.size();i++){
        int v=StrOpt[rt].son[i].second;
        string T=StrOpt[rt].son[i].first;
        //cout<<T<<endl;
        if(T==now){
            return query(v,nxt);
        }
    }
    return -1;
}
namespace IO{
    int n,op,k,addr;
    string s,t,m;
    void solve(){
        StrType["byte"].big=StrType["byte"].O=1;
        StrType["short"].big=StrType["short"].O=2;
        StrType["int"].big=StrType["int"].O=4;
        StrType["long"].big=StrType["long"].O=8;
        tag[0]=1;
        cin>>n;
        while(n--){
            cin>>op;
            if(op==1){
                cin>>s>>k;int B=0;
                for(int i=1;i<=k;i++){
                    cin>>t>>m;
                    StrType[s].son.push_back(mp(t,m));
                    StrType[s].O=max(StrType[s].O,StrType[t].O);
                    int b=(B-1)/StrType[t].O+1;
                    if(B!=0){
                        b*=StrType[t].O;
                    }else b=0;
                    B=b+StrType[t].big;
                }
                StrType[s].big=((B-1)/StrType[s].O+1)*StrType[s].O;
                cout<<StrType[s].big<<" "<<StrType[s].O<<endl;
            }else if(op==2){
                cin>>t>>m;
                Optid[m]=++cnt;
                opt &Opt=StrOpt[cnt];
                Opt.typ=t;
                int b=(nxtadr-1)/StrType[t].O+1;
                if(nxtadr!=0){
                    b*=StrType[t].O;
                }else b=0;
                Opt.beg=b;
                nxtadr=Opt.beg+StrType[Opt.typ].big;
                tag[cnt]=1;
                init(Optid[m]);
                Tree[0].push_back(Optid[m]);
                StrOpt[0].son.push_back(mp(m,Optid[m]));
                cout<<Opt.beg<<endl;
            }else if(op==3){
                cin>>s;s=s+".";
                cout<<query(0,s)<<endl;
            }else{
                cin>>addr;string e;
                string ans=serach(0,addr,e);
                if(ans.size()){
                    for(int i=1;i<ans.size();i++)
                        cout<<ans[i];
                    cout<<"\n";
                }else cout<<"ERR"<<endl;
            }
        }
    }
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    IO::solve();
	return 0;
}
