#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
int n,s,cnt;
long long ll;
string a,b,c;
set<long long> r,l;
map<string,vector<pair<string,string>>> jie;
map<string,int> buquan,fl;
map<int,string> duiying;
map<string,string> jianli;
set<long long>::iterator it,iu;
map<long long,string> lf,rf;
string inline read(){
    string sl;
    char c=getchar();
    while(c>='a' && c<='z'){
        sl=sl+c;
        c=getchar();
    }
    return sl;
}
void build(string e){
    for(pair<string,string> p:jie[e]){
        char d=p.second[0];
        if(d>='0' && d<='9'){
            d=d-'0';
            l.insert(ll);
            lf[ll]=e;
            fl[e]=ll;
            r.insert(ll+d-1);
            rf[ll+d-1]=e;
            ll+=buquan[e]-1;
        }
        else{
            build(p.second);
        }
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int op;
    for(int k=1;k<=n;k++){
        cin>>op;
        if(op==1){
            cin>>a>>s;
            cnt=0;
            for(int i=1;i<=s;i++){
                cin>>b>>c;
                if(b=="byte"){
                    cnt=max(cnt,1);
                    jie[a].push_back({c,"1"});
                }
                else if(b=="short"){
                    cnt=max(cnt,2);
                    jie[a].push_back({c,"2"});
                }
                else if(b=="int"){
                    cnt=max(cnt,4);
                    jie[a].push_back({c,"4"});
                }
                else if(b=="long"){
                    cnt=max(cnt,8);
                    jie[a].push_back({c,"8"});
                }
                else{
                    cnt=max(cnt,buquan[b]);
                    jie[a].push_back({c,"1"});
                }
            }
            buquan[a]=cnt;
            cout<<cnt*s<<" "<<cnt<<endl;
        }
        else if(op==2){
            cin>>a>>b;
            jianli[b]=a;
            cout<<ll<<endl;
            for(pair<string,string> p:jie[a]){
                char d=p.second[0];
                if(d>='0' && d<='9'){
                d=d-'0';
                l.insert(ll);
                lf[ll]=a;
                fl[a]=ll;
                r.insert(ll+d-1);
                rf[ll+d-1]=a;
                ll+=buquan[a]-1;
                }
                else{
                    build(p.second);
                }
            }
        }
        else if(op==3){
            s=getchar();
            a=read();
            a=jianli[a];
            while(1){
                if(jie[a].size()==0)
                    break;
                a=read();
            }
            a=read();
            cout<<fl[a]<<endl;
        }
        else{
            cin>>s;
            it=r.lower_bound(s);
            iu=l.lower_bound(s);
            iu--;
            if(lf[*iu]!=lf[*it])
                cout<<"ERR"<<endl;
            else
                cout<<lf[*iu]<<endl;
            }
    }
    return 0;
}