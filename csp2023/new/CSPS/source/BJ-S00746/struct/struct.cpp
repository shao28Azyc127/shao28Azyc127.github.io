#pragma optimize GCC(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
map<string,ll>mp;
map<string,ll>dzjgt;//duizhao
map<string,ll>dzys;
struct ys{
    string type,ming;
    ll l,r,zj;
};
struct jgt{
    string ming;
    ll l,r,zj;
    vector<ys>vec;
};
vector<ys>v1;
vector<jgt>v2;
ll js(ll st,ll mod){
    ll r=st%mod;
    return st+mod-r;
}
ll ans(int I,vector<string>v3,string ming){
    if(I==v3.size()){
        if(!dzjgt.count(ming)){
            string tr=v3.back();
            ys tmp=v1[dzys[tr]];
            return tmp.l;
        }
        return 0;
    }
    //cout<<ming<<" "<<v3.size()<<" ";
    string tr=v3[I];//cout<<tr<<" ";
    jgt tmp=v2[dzjgt[ming]];
    //cout<<tmp.ming<<" ";
    //cout<<tmp.vec[0].ming<<" ";
    for(int i=0;i<tmp.vec.size();i++)
        if(tmp.vec[i].ming==tr)
            return tmp.vec[i].l+ans(I+1,v3,tmp.vec[i].type);
}
bool ji(string s){
    return s=="byte"||s=="short"||s=="int"||s=="long";
}
void ser(ll n,string &sq,string ming){
    if(ming=="zong"){
        cout<<v1[0].l<<" "<<v1[0].r<<" ";
        for(int i=0;i<v1.size();i++){
            if(v1[i].l<=n&&n<=v1[i].r)
                if(ji(v1[i].type)){
                    sq=v1[i].ming;return;
                }else{
                    sq=v1[i].ming+".";
                    ser(n-v1[i].l,sq,v1[i].type);
                    return;
                }
            sq="ERR";return;
        }
    }
    cout<<ming;
    jgt tmp=v2[dzjgt[ming]];
    vector<ys>vv1=tmp.vec;
    for(int i=0;i<vv1.size();i++)
        if(vv1[i].l<=n&&n<=vv1[i].r)
            if(ji(vv1[i].type)){
                sq+=vv1[i].ming;return;
            }else{
                sq=sq+vv1[i].ming+".";
                ser(n-vv1[i].l,sq,vv1[i].type);
                return;
            }
    sq="ERR";return;
}
int main(){
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    mp["byte"]=1;mp["short"]=2;mp["int"]=4;mp["long"]=8;
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;cin>>op;
        if(op==1){
            string s;ll k;cin>>s>>k;
            ll maxn=-1;jgt tmp;tmp.ming=s;
            string lei[105],ming[105];
            for(int i=1;i<=k;i++){
                cin>>lei[i]>>ming[i];maxn=max(maxn,mp[lei[i]]);
            }
            tmp.zj=maxn;mp[s]=maxn;tmp.l=0;
            for(int i=1;i<=k;i++){
                ys tmp1;
                tmp1.type=lei[i];tmp1.ming=ming[i];
                if(tmp.vec.size()==0)tmp1.l=tmp.l;
                else tmp1.l=js(tmp.vec.back().r,mp[lei[i]]);
                tmp1.r=tmp1.l+mp[lei[i]]-1;
                tmp1.zj=mp[lei[i]];
                tmp.vec.push_back(tmp1);
            }
            tmp.r=js(tmp.vec.back().r,maxn)-1;
            v2.push_back(tmp);
            cout<<tmp.r-tmp.l+1<<" "<<tmp.zj<<"\n";
            dzjgt[tmp.ming]=v2.size()-1;
        }
        if(op==2){
            string lei,ming;cin>>lei>>ming;
            ys tmp;tmp.type=lei;tmp.ming=ming;tmp.zj=mp[tmp.type];
            if(v1.size()==0)tmp.l=0;
            else tmp.l=js(v2.back().r,tmp.zj);
            tmp.r=tmp.l+tmp.zj-1;
            v1.push_back(tmp);
            cout<<tmp.l<<"\n";
            dzys[tmp.ming]=v1.size()-1;
        }
        if(op==3){
            //cout<<v2[1].vec[0].ming<<" ";
            string fang;cin>>fang;
            int qs;vector<string>fwys;
            qs=0;
            for(int i=0;i<fang.size();i++){
                if(fang[i]=='.'){fwys.push_back(fang.substr(qs,i-qs));qs=i+1;}
                else if(i==fang.size()-1)fwys.push_back(fang.substr(qs,i-qs+1));
            }
            cout<<ans(1,fwys,v1[dzys[fwys[0]]].type)<<"\n";
        }
        if(op==4){
            ll tl;cin>>tl;
            string sq;
            ser(tl,sq,"zong");
            cout<<sq;
        }
    }
    return 0;
}
