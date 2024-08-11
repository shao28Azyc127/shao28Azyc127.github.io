#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Str{
    vector<pair<int,string> > chs;
    ll sz;
    int duiqi;
    string name;
};
vector<Str> stref;
map<string,int> sts;
vector<pair<int,string> > vals;
ll usedaddr=0;
int n;
ll minD(ll a,ll b){
    if(a%b==0) return a;
    return (a/b+1)*b;
}
pair<int,ll> find(vector<pair<int,string> > vals,string name){
    ll addr=0;
    for(auto p:vals){
        int type=p.first;
        // cout<<p.second<<" ";
        addr=minD(addr,stref[type].duiqi);
        // cout<<addr<<endl;
        if(p.second==name){
            return {type,addr};
        }
        addr+=stref[type].sz;
    }
    return {-1,-1};
}
queue<string> q;
void dfs(int tpid,ll baddr,ll addr){
    baddr=minD(baddr,stref[tpid].duiqi);
    if(stref[tpid].chs.size()==0){
        if(baddr<=addr&&addr<baddr+stref[tpid].sz){
            while(q.size()>1){
                cout<<q.front()<<".";
                q.pop();
            }
            cout<<q.front()<<endl;
        }
        else cout<<"ERR"<<endl;
        return;
    }
    bool found=0;
    auto vec=stref[tpid].chs;
    for(int i=0;i<vec.size();i++){
        ll lstpos=baddr;
        baddr=minD(baddr,stref[vec[i].first].duiqi);
        if(lstpos<=addr&&addr<baddr){
            found=1;
            cout<<"ERR"<<endl;
            return;
        }
        // cout<<" "<<vec[i].second<<" "<<baddr<<" "<<baddr+stref[vec[i].first].sz<<endl;
        if(baddr<=addr&&addr<baddr+stref[vec[i].first].sz){
            found=1;
            q.push(vec[i].second);
            dfs(vec[i].first,baddr,addr);
            return;
        }
        baddr+=stref[vec[i].first].sz;
    }
    cout<<"ERR"<<endl;
}
int main(){
    #ifndef JZQ
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin>>n;
    Str basictype;
    basictype.sz=basictype.duiqi=1;
    stref.push_back(basictype);
    sts["byte"]=0;
    basictype.sz=basictype.duiqi=2;
    stref.push_back(basictype);
    sts["short"]=1;
    basictype.sz=basictype.duiqi=4;
    stref.push_back(basictype);
    sts["int"]=2;
    basictype.sz=basictype.duiqi=8;
    stref.push_back(basictype);
    sts["long"]=3;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            // cout<<"(1 "<<s<<")";
            Str st;
            ll o=0;
            st.duiqi=0;
            for(int i=0;i<k;i++){
                string t,n;
                cin>>t>>n;
                st.chs.push_back({sts[t],n});
                if(i!=0){
                    o=minD(o+stref[st.chs[i-1].first].sz,stref[st.chs[i].first].duiqi);
                }
                st.duiqi=max(st.duiqi,stref[st.chs[i].first].duiqi);
            }
            st.sz=minD(o+stref[st.chs[k-1].first].sz,st.duiqi);
            st.name=s;
            sts[s]=stref.size();
            stref.push_back(st);
            cout<<st.sz<<" "<<st.duiqi<<endl;
        }
        else if(op==2){
            string t,n;
            cin>>t>>n;
            // cout<<"(2)";
            vals.push_back({sts[t],n});
            Str st=stref[sts[t]];
            usedaddr=minD(usedaddr,st.duiqi);
            cout<<usedaddr<<endl;
            usedaddr+=st.sz;
        }
        else if(op==3){
            string s;
            cin>>s;
            // cout<<"(3)";
            string t="";
            int tpid=-1;
            ll addr=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'||i==s.size()-1){
                    if(i==s.size()-1) t+=s[i];
                    pair<int,ll> p;
                    if(tpid==-1) p=find(vals,t);
                    else p=find(stref[tpid].chs,t);
                    // cout<<stref[tpid].name<<" "<<p.second<<endl;
                    tpid=p.first;
                    addr=minD(addr,stref[tpid].duiqi)+p.second;
                    if(i==s.size()-1) cout<<addr<<endl;
                    t="";
                    continue;
                }
                t+=s[i];
            }
        }
        else{
            while(!q.empty()) q.pop();
            ll addr;
            cin>>addr;
            ll addpos=0;
            bool found=0;
            for(int i=0;i<vals.size();i++){
                ll lstpos=addpos;
                addpos=minD(addpos,stref[vals[i].first].duiqi);
                if(lstpos<=addr&&addr<addpos){
                    found=1;
                    cout<<"ERR"<<endl;
                    break;
                }
                // cout<<vals[i].second<<" "<<addpos<<" "<<addpos+stref[vals[i].first].sz<<endl;
                if(addpos<=addr&&addr<addpos+stref[vals[i].first].sz){
                    found=1;
                    q.push(vals[i].second);
                    dfs(vals[i].first,addpos,addr);
                    break;
                }
                addpos+=stref[vals[i].first].sz;
            }
            if(!found) cout<<"ERR"<<endl;
        }
    }
    return 0;
}