#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stc{
    vector<string>type;
    vector<string>name;
    vector<int>allocat;
    int size;
    int pref;
    int find(string _name){
        for(int i=0;i<name.size();i++){
            if(name[i]==_name){
                return i;
            }
        }
    }
    int find(int _allocat){
        for(int i=0;i<allocat.size();i++){
            if(_allocat>=allocat[i]){
                return i;
            }
        }
    }
};
map<string,stc>p;
map<string,int>len;
string s,s1,s2,auv,t[100],m[100];
int n,k,op,allcnt;
stc tmp;
vector<string>type;
vector<string>name;
vector<int>allocat;
vector<string>sp;
void split(string s){
    sp.clear();
    auv="";
    for(auto&it:s){
        if(it=='.'){
            sp.push_back(auv);
            auv="";
        }else{
            auv+=it;
        }
    }
    sp.push_back(auv);
}
int dfs(string str,int x){
    if(x==sp.size()){
        return 0;
    }
    auto&cur=p[str];
    for(int i=0;i<cur.name.size();i++){
        if(cur.name[i]==sp[x]){
            return cur.allocat[i]+dfs(cur.type[i],x+1);
        }
    }
}
string dfss(string str,int x){
    auto&cur=p[str];
    if(cur.allocat.size()){
        for(int i=0;i<cur.allocat.size();i++){
            if(i==cur.allocat.size()-1||x<cur.allocat[i+1]){
                return"."+cur.name[i]+dfss(cur.type[i],x-cur.allocat[i]);
            }
        }
    }else{
        if(x>=p[str].size){
            return"ERR";
        }else{
            return"";
        }
    }
}
string prt(string x){
    if(x.substr(x.size()-3,3)=="ERR"){
        return"ERR";
    }else{
        return x;
    }
}
int Ceil(int x,int y){
    return(x+y-1)/y*y;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    p["byte"].size=1;
    p["byte"].pref=1;
    p["short"].size=2;
    p["short"].pref=2;
    p["int"].size=4;
    p["int"].pref=4;
    p["long"].size=8;
    p["long"].pref=8;
    cin>>n;
    while(n--){
        cin>>op;
        switch(op){
        case 1:{
            cin>>s>>k;
            auto&cur=p[s];
            for(int i=0;i<k;i++){
                cin>>t[i]>>m[i];
                cur.type.push_back(t[i]);
                cur.name.push_back(m[i]);
                cur.pref=max(cur.pref,p[t[i]].pref);
            }
            for(int i=0;i<k;i++){
                cur.allocat.push_back(Ceil(cur.size,p[t[i]].pref));
                cur.size=Ceil(cur.size,p[t[i]].pref)+p[t[i]].size;
            }
            cur.size=Ceil(cur.size,cur.pref);
            cout<<cur.size<<" "<<cur.pref<<endl;
            break;
        }
        case 2:
            cin>>s1>>s2;
            type.push_back(s1);
            name.push_back(s2);
            allocat.push_back(Ceil(allcnt,p[s1].pref));
            cout<<Ceil(allcnt,p[s1].pref)<<endl;
            allcnt=Ceil(allcnt,p[s1].pref)+p[s1].size;
            break;
        case 3:
            cin>>s;
            split(s);
            for(int i=0;i<name.size();i++){
                if(name[i]==sp[0]){
                    cout<<allocat[i]+dfs(type[i],1)<<endl;
                }
            }
            break;
        case 4:
            cin>>k;
            bool flag=0;
            allocat.push_back(allcnt);
            for(int i=0;i<allocat.size()-1;i++){
                if(k<allocat[i+1]){
                    cout<<prt(name[i]+dfss(type[i],k-allocat[i]))<<endl;
                    flag=1;
                    break;
                }
            }
            allocat.pop_back();
            if(flag==0){
                cout<<"ERR"<<endl;
            }
            break;
        }
    }
}
/*
488
*/
