#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=100;
ll m,n,cnt=0,_ans=0;
map<string,vector<string> >mp;
unordered_map<string,ll> ty;
unordered_map<string,pair<ll,ll> > sl;
vector< pair<ll,string> > st;
ll ef(ll s){
    if(st[st.size()-1].fi+sl[st[st.size()-1].se].se-1<s)return -1;
    ll l=0,r=st.size()-1,mid;
    _ans=-1;
    while(l<r){
        mid=l+r>>1;
        if(st[mid].fi<=s){
            _ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return _ans;
}

int main(){
    ty["byte"]=1;
    ty["short"]=2;
    ty["int"]=3;
    ty["long"]=4;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&m);
    while(m--){
        ll pos,s;
        string c,k,e;
        scanf("%lld",&pos);
        if(pos==1){
            cin>>c>>s;
            for(int i=1;i<=s;i++){
                cin>>k>>e;
            }
        }else if(pos==2){
            cin>>c>>k;
            st.push_back({cnt,k});
            //solve2(c,k);
            sl[k].fi=cnt;
            if(c=="byte")cnt++;
            if(c=="short")cnt+=2;
            if(c=="int")cnt+=4;
            if(c=="long")cnt+=8;
            sl[k].se=cnt-sl[k].fi;
        }else if(pos==3){
            cin>>c;
            printf("%lld\n",sl[c].fi);
        }else if(pos==4){
            scanf("%lld",&s);
            //ll q=upper_bound(st.begin(),st.end(),make_pair(s,0))-st.begin();
            ll q=ef(s);
            if(q<0){
                printf("ERR\n");
            }else{
                cout<<st[q].se;
                printf("\n");
            }
        }
    }
    return 0;
}
