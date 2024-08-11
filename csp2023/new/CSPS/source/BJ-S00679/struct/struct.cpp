#include<bits/stdc++.h>

using namespace std;
const int N=105;
int n,cnt=4;
map<string,int> mp{{"byte",1},{"short",2},{"int",3},{"long",4}};//某名称的结构体对应的序号
string nnam[N];
int nnamcnt;
struct stc{
    // vector<tuple<string,int,int> > lst;//名称, 起始地址，子结构体类型序号
    vector<string> nam;
    vector<int> start;
    vector<int> typ;
    map<string,int> qs;//某子结构体对应的起始地址
    int len=0,maxlen=0;//长度
}lst[N]={{},
{{},{},{},{},1},
{{},{},{},{},2},
{{},{},{},{},4},
{{},{},{},{},8}};
int updiv(int x,int y){
    int tmp=x/y;
    if(tmp*y<x) ++tmp;
    return tmp;}
void add(vector<pair<int,string> > &vec){
    int l=0;
    for(auto i:vec){
        int len=lst[i.first].len;
        lst[cnt].maxlen=max(lst[cnt].maxlen,len);
        int num=updiv(l,len);
        lst[cnt].nam.push_back(i.second);
        lst[cnt].typ.push_back(num*len);
        lst[cnt].typ.push_back(i.first);
        mp[i.second]=num*len;
        l=len*(num+1);
    }
    lst[cnt].len=updiv(l,lst[cnt].maxlen)*lst[cnt].maxlen;
}
int addrlen;
vector<pair<int,int> > address;//第i个实例的起始地址与类型
map<string,int> namemap;//实例名称对应的序号
void neww(int x,string s){
    int len=lst[x].len;
    address.push_back({updiv(addrlen,len)*len,x});
    addrlen=(updiv(addrlen,len)+1)*len;
    namemap[s]=address.size()-1;
}
int fw(int x,deque<string> &fd){//找结构体x中fd最后元素的起始地址
    int ans=0;
    while(!fd.empty()){
        string aim=fd.front();
        fd.pop_front();
        ans+=lst[x].qs[aim];
    }   
    return ans;
}
bool chk(int typ,int i,vector<int> &ans){
    if(i<0||i>=lst[typ].len) return 0;
    if(lst[typ].nam.size()==0){
        ans.push_back(typ);
        return 1;
    }
    auto it=lower_bound(lst[typ].start.begin(),lst[typ].start.end(),i);
    if(it==lst[typ].start.end()) return 0;
    int idx=it-lst[typ].start.begin();
    if(chk(lst[typ].typ[idx],i-lst[typ].start[idx],ans)){
        ans.push_back(typ);
        return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string s;int k;
            cin>>s>>k;
            mp[s]=++cnt;
            nnam[++nnamcnt]=s;
            vector<pair<int,string> > v;
            while(k--){
                string s1,s2;
                cin>>s1>>s2;
                v.push_back({mp[s1],s2});
            }
            add(v);
            cout<<lst[cnt].len<<" "<<lst[cnt].maxlen<<"\n";
        }else if(op==2){
            string t,s;
            cin>>t>>s;
            neww(mp[t],s);
            cout<<(address[address.size()-1]).first<<"\n";
        }else if(op==3){
            string s,tmp="",typname="";
            deque<string> fd;
            cin>>s;
            for(int i=0;i<s.length();i++){
                if(s[i]=='.'){
                    if(typname!="") fd.push_back(tmp);
                    else typname=tmp;
                    tmp="";
                    continue;
                }
                tmp+=s[i];
            }
            pair<int,int> aim=address[namemap[typname]];
            cout<<aim.first<<" "<<aim.second<<endl;
            cout<<aim.first+fw(aim.second,fd)<<"\n";
        }else{
            int addr;
            cin>>addr;
            auto it=lower_bound(address.begin(),address.end(),pair<int,int>{addr,0});
            if(it==address.end()){
                cout<<"ERR\n";
            }else{
                vector<int> ans;
                if(chk((*it).second,addr-(*it).first,ans)){
                    for(int i=ans.size()-1;i>=0;i--){
                        cout<<nnam[ans[i]]<<".";
                    }cout<<"\n";
                }
            }
        }
    }
    return 0;
}