#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
int n,pw[5]={1,2,4,8};
struct Element{
    string name;
    int type;
};
struct Struct{
    int cnt,siz,a;
    vector<Element> e;
    unordered_map<string,int> mp;
    void geta(){
        for(auto i:e) a=max(a,pw[i.type]);
    }
}str[N];
struct Node{
    int beg,type;
    string name;
}node[N];
int tot,node_cnt,ad;
unordered_map<string,int> id,idn;
string tp,nm,tmp,query,q;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    id["byte"]=0ll;
    id["short"]=1ll;
    id["int"]=2ll;
    id["long"]=3ll;
    cin>>n;
    while(n--){
        int opt;cin>>opt;
        if(opt==1){
            ++tot;
            cin>>tmp;
            int k;cin>>k;
            id[tmp]=tot;
            for(int i=1;i<=k;i++){
                cin>>tp>>nm;
                str[tot].e.push_back({nm,id[tp]});
                str[tot].mp[nm]=str[tot].e.size()-1;
            }
            str[tot].cnt=k;
            str[tot].geta();
            str[tot].siz=k*str[tot].a;
            int res=0;
            for(auto i:str[tot].e) res+=pw[i.type];
            cout<<str[tot].siz<<" "<<str[tot].a<<'\n';
        }
        else if(opt==2){
            ++node_cnt;
            cout<<ad<<'\n';
            node[node_cnt].beg=ad;
            cin>>tp>>nm;
            node[node_cnt].type=id[tp];
            node[node_cnt].name=nm;
            idn[nm]=node_cnt;
        }
        else if(opt==3){
            cin>>query;
            int pos=0;
            for(int i=0;i<query.size();i++){
                if(query[i]=='.'){
                    pos=i;
                    break;
                }
            }
            q=query.substr(0,pos);//cout<<q<<endl;
            int curid=idn[q];//cout<<curid<<endl;
            int curad=node[curid].beg;
            q=query.substr(pos+1,query.size()-pos);//cout<<q<<endl;
            pos=str[curid].mp[q];
            for(int i=0;i<pos;i++) curad+=pw[str[curid].e[i].type];
            cout<<curad<<'\n';
        }
        else{
            int addr;cin>>addr;
            int curad=0,curid=0;
            if(addr>node[node_cnt].beg+str[node[node_cnt].type].siz){
                cout<<"ERR"<<'\n';
                continue;
            }
            for(int i=node_cnt;i>=1;i--){
                if(node[i].beg<=addr){
                    curid=i;
                    break;
                }
            }
            curad=node[curid].beg;
            int t=node[curid].type;
            for(int i=0;i<str[t].e.size();i++){
                if(curad+str[t].a>addr){
                    if(curad+pw[str[t].e[i].type]>addr) cout<<"ERR"<<'\n';
                    else cout<<node[curid].name<<"."<<str[i].e[i-1].name<<'\n';
                }
                else curad+=str[t].a;
            }
        }
    }
}
