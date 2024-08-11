#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
map<string,int> ma;
map<string,int> mb;
struct st{
    string ty;
    int k;
    vector<long long> o;
    vector<int> v;
    vector<string> son;
    long long d,si;
}t[N];
int cn;
long long be[N];
string na[N];
int tp[N];
long long nla;
long long si;
string no,ls;
vector<string> as;
void dfs(int no,long long k){
    if(t[no].si<=k){
        cout<<"ERR\n";
        return;
    }
    if(no<=4){
        for(int i=0;i<as.size();++i){
            cout<<as[i];
            if(i+1!=as.size())cout<<'.';
        }cout<<'\n';
        return;
    }
    for(int j=0;j<t[no].k;++j){
        if(t[no].o[j+1]>k){
            as.push_back(t[no].son[j]);
            dfs(t[no].v[j],k-t[no].o[j]);
            break;
        }
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    no="byte";
    ++cn;
    t[cn].ty=no;ma[no]=1;
    t[cn].d=1;t[cn].si=1;
    no="short";
    ++cn;
    t[cn].ty=no;ma[no]=2;
    t[cn].d=t[cn].si=2;
    no="int";
    ++cn;
    t[cn].ty=no;ma[no]=3;
    t[cn].d=t[cn].si=4;
    no="long";
    ++cn;
    t[cn].ty=no;ma[no]=4;
    t[cn].d=t[cn].si=8;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            ++cn;
            cin>>t[cn].ty>>t[cn].k;
            ma[t[cn].ty]=cn;
            for(int i=1;i<=t[cn].k;++i){
                cin>>no>>ls;
                int to=ma[no];
                if(i==1)t[cn].o.push_back(0);
                else{
                    long long lo=t[cn].o.back();
                    long long lsi=t[t[cn].v.back()].si;
                    long long nsi=t[to].d;
                    t[cn].o.push_back(((lo+lsi-1)/nsi+1)*nsi);
                }
                t[cn].v.push_back(to);
                t[cn].son.push_back(ls);
                t[cn].d=max(t[cn].d,t[to].d);
            }
            long long lo=t[cn].o.back();
            long long lsi=t[t[cn].v.back()].si;
            t[cn].si=((lo+lsi-1)/t[cn].d+1)*t[cn].d;
            cout<<t[cn].si<<' '<<t[cn].d<<'\n';
            t[cn].o.push_back(2e18);
        }
        else if(op==2){
            ++si;
            cin>>na[si];tp[si]=ma[na[si]];
            long long nsi=t[tp[si]].si;
            int nd=t[tp[si]].d;
            if(si==1){
                be[si]=0;
                nla=nsi;
            }
            else{
                be[si]=((nla-1)/nd+1)*nd;
                nla=be[si]+nsi;
            }
            cin>>na[si];
            mb[na[si]]=si;
            cout<<be[si]<<'\n';
        }
        else if(op==3){
            cin>>no;
            long long rt=-1,eb=0;ls.clear();
            for(int i=0;i<no.size();++i){
                if(no[i]=='.'){
                    if(rt==-1){
                        eb=be[mb[ls]];
                        rt=tp[mb[ls]];
                    }
                    else{
                        for(int j=0;j<t[rt].k;++j){
                            if(ls==t[rt].son[j]){
                                eb+=t[rt].o[j];
                                rt=t[rt].v[j];
                                break;
                            }
                        }
                    }
                    ls.clear();
                }
                else{
                    ls.push_back(no[i]);
                }
            }
            if(rt==-1){
                eb=be[mb[ls]];
                rt=tp[mb[ls]];
            }
            else{
                for(int j=0;j<t[rt].k;++j){
                    if(ls==t[rt].son[j]){
                        eb+=t[rt].o[j];
                        rt=t[rt].v[j];
                        break;
                    }
                }
            }
            cout<<eb<<'\n';
        }
        else{
            long long nno;
            cin>>nno;
            if(be[si]+t[tp[si]].si-1<nno){
                cout<<"ERR\n";
                continue;
            }as.clear();be[si+1]=2e18;
            for(int i=1;i<=si;++i){
                if(be[i+1]>nno){
                    as.push_back(na[i]);
                    dfs(tp[i],nno-be[i]);
                    break;
                }
            }
        }
    }
    return 0;
}
