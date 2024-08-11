#include<bits/stdc++.h>
#define int long long
using namespace std;

struct st{
    string typ;
    int ads,ade,rade;
};

int N,op,k,maxn,addr;
string s,t,n;
map<string> typ;
map<string,pair<int,vector<pair<string,string>>>> def;
unordered_map<string,st> stru;

void news(string t,string n){
    stru[n].typ=t;
    stru[n].ads=maxn+1;
    stru[n].ade=maxn+def[t].first.second;
    stru[n].rade=maxn+ceil((1.0*stru[n].ade)/(1.0*def[t].first.first))*def[t].first.first;
}

int finds(string ns){
    string ty=stru[ns].typ;
    getline(cin,s,'.');
    char c=getchar();
    if(c=='\n'){
        for(pair<string,string> x:def[ns].second){
            if(x.second==s){
                return tot+1;
            }
            tot+=typ[x.first];
        }
    }
    int tot=0;
    for(pair<string,string> x:def[ty].second){
        if(x.second==s){
            return tot+finds(s);
        }
        tot+=typ[x.first];
    }
}

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>N;
    typ["byte"]=1;
    typ["short"]=2;
    typ["int"]=4;
    typ["long"]=8;
    for(int i=1;i<=N;i++){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            int maxn=LLONG_MAX,tot=0;
            for(int j=1;j<=k;j++){
                cin>>t>>n;
                maxn=max(maxn,typ[t]);
                tot+=typ[t];
                def[s].second.push_back(make_pair(t,n));
            }
            def[s].first=maxn;
            typ[s]=tot;
        }
        if(op==2){
            cin>>t>>n;
            news(t,n);
        }
        if(op==3){
            getline(cin,s,'.');
            cout<<finds(s)<<endl;
        }
        if(op==4){
            cin>>addr;
            unordered_map<string,st>::iterator it=stru.begin();
            while(it!=stru.end()){
                st struc=*it;
                if(struc.ade<addr&&addr<=struc.rade){
                    cout<<"ERR";
                }
            }
        }
    }

    return 0;
}
