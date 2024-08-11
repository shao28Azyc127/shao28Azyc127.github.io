#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
struct thing{
    string name;
    ll sz=0,need=0;
    vector<pair<string,string>>v;
};
map<string,thing>tpool;
map<string,pair<ll,string>>epool;
ll tot;
map<ll,string>len;
map<ll,ll>len_len;
map<string,ll>query;
void add(thing t,string l){
    query[l]=tot;
    if(t.v.empty()){
        //cout<<tot<<" "<<l<<endl;
        len[tot]=l;
        len_len[tot]=t.sz;
        tot+=t.sz;
        return;
    }
    for(auto i:t.v){
        string L=l+"."+i.second;
        //cout<<l<<" "<<L<<" "<<tot<<" ";
        if(tot%tpool[i.first].need){
            tot+=(tpool[i.first].need-(tot%tpool[i.first].need))%tpool[i.first].need;
        }
        //cout<<tot<<endl;
        add(tpool[i.first],L);
    }
}
ll found(string l,ll start,ll i,thing num){
    if(i==l.size()){
        return start;
    }
    string now;
    while(i<l.size()-1&&l[i+1]!='.'){
        now+=l[i+1];
        ++i;
    }
    ++i;
    ll sz=0;
    for(auto j:num.v){
        //cout<<j.first<<" "<<j.second<<" "<<now<<endl;
        if(j.second==now){
            return found(l,start+sz*num.need,i,tpool[j.first]);
        }
        ++sz;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    tpool["byte"].need=tpool["byte"].sz=1;
    tpool["short"].need=tpool["short"].sz=2;
    tpool["int"].need=tpool["int"].sz=4;
    tpool["long"].need=tpool["long"].sz=8;
    for(auto i:tpool){
        tpool[i.first].name=i.first;
    }
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll op;
        scanf("%lld",&op);
        if(op==1){
            string s;
            ll k;
            cin>>s>>k;
            thing New;
            New.name=s;
            ll st=0;
            for(int i=1;i<=k;++i){
                string son,name;
                cin>>son>>name;
                New.v.push_back({son,name});
                New.need=max(New.need,tpool[son].need);
                if(st%tpool[son].need!=0){
                    //cout<<st<<" "<<tpool[son].need-(st%tpool[son].need)<<" "<<son<<" "<<tpool[son].sz<<endl;
                    New.sz+=(tpool[son].need-(st%tpool[son].need))%tpool[son].need;
                    st+=tpool[son].need-(st%tpool[son].need);
                }
                New.sz+=tpool[son].sz;
                st+=tpool[son].sz;
            }
            New.sz+=(New.need-(New.sz%New.need))%New.need;
            //cout<<New.need-(New.sz%New.need)<<endl;
            tpool[New.name]=New;
            printf("%lld %lld\n",New.sz,New.need);
        }else if(op==2){
            string type,name;
            cin>>type>>name;
            epool[name]={tot,type};
            if(tot%tpool[type].need){
                tot+=(tpool[type].need-(tot%tpool[type].need))%tpool[type].need;
            }
            cout<<tot<<endl;
            add(tpool[type],name);
        }else if(op==3){
            string l;
            cin>>l;
            cout<<query[l]<<endl;
        }else{
            ll addr;
            cin>>addr;
            bool good=false;
            for(ll i=addr;i>=addr-7&&i>=0;--i){
                if(len.count(i)&&i+len_len[i]-1>addr){
                    cout<<len[i]<<endl;
                    good=true;
                    break;
                }
            }
            if(!good){
                printf("ERR\n");
            }
        }
    }
    return 0;
}


