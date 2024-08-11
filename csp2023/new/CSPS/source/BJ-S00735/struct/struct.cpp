#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int N=105;
int n,cnt;
long long cur;
struct STRUCT{
    long long mxdq,mxx;
    vector<string>gname;
    vector<long long>gsize;
    vector<long long>gst;
    vector<long long>ged;
    vector<string>gtype;
}a[N];
map<string,int>mp;
vector<string>gname;
vector<string>gtype;
vector<long long>gsize;
vector<long long>gst;
vector<long long>ged;
long long fname(string name){
    string fst,type;
    int l=name.size();
    long long curfr;
    int i;
    for(i=0;i<l;i++){
        if(name[i]=='.')break;
        fst+=name[i];
    }
    i++;
    for(int cc=0;cc<gname.size();cc++){
        if(gname[cc]==fst){
            curfr=gst[cc];
            type=gtype[cc];
            break;
        }
    }
    if(type=="byte"||type=="short"||type=="int"||type=="long")return curfr;
    int tpid=mp[type];
    while(true){
        string cstr;
        for(;i<l;i++){
            if(name[i]=='.')break;
            cstr+=name[i];
        }
        i++;
        for(int cc=0;cc<a[tpid].gname.size();cc++){
            if(a[tpid].gname[cc]==cstr){
                curfr+=a[tpid].gst[cc];
                tpid=mp[a[tpid].gtype[cc]];
                break;
            }
        }
        if(i>=l-1)break;
    }
    return curfr;
}
string fstruct(long long x,int tpid){
    int pls;
    for(int i=0;i<a[tpid].gst.size();i++){
        if(x<a[tpid].gst[i])break;
        pls=i;
    }
    string curtp=a[tpid].gtype[pls];
    if(curtp=="byte"||curtp=="short"||curtp=="int"||curtp=="long"){
        if(x>a[tpid].ged[pls])return "ERR";
        else return a[tpid].gname[pls];
    }
    if(x>a[tpid].ged[pls])return "ERR";
    x-=a[tpid].gst[pls];
    string sret=fstruct(x,mp[a[tpid].gtype[pls]]);
    if(sret=="ERR")return "ERR";
    else return a[tpid].gname[pls]+"."+sret;
}
string scache(long long x){
    int pls;
    string ret;
    if(gname.size()==0)return "ERR";
    for(int cc=0;cc<gname.size();cc++){
        if(gst[cc]>x)break;
        pls=cc;
    }
    ret+=gname[pls];
    x-=gst[pls];
    string sret=fstruct(x,mp[gtype[pls]]);
    if(sret=="ERR")return "ERR";
    return ret+"."+sret;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            mp[s]=++cnt;
            long long mxdq=0,ccur=0;
            for(int i=1;i<=k;i++){
                string type,name;
                cin>>type>>name;
                a[cnt].gname.push_back(name);
                a[cnt].gtype.push_back(type);
                if(type=="byte"){
                    mxdq=max(mxdq,1ll);
                    a[cnt].gsize.push_back(1);
                    a[cnt].gst.push_back(ccur);
                    a[cnt].ged.push_back(ccur);
                    ccur++;
                }
                else if(type=="short"){
                    mxdq=max(mxdq,2ll);
                    a[cnt].gsize.push_back(2);
                    if(ccur%2!=0)ccur=ccur+2-ccur%2;
                    a[cnt].gst.push_back(ccur);
                    a[cnt].ged.push_back(ccur+1);
                    ccur+=2;
                }
                else if(type=="int"){
                    mxdq=max(mxdq,4ll);
                    a[cnt].gsize.push_back(4);
                    if(ccur%4!=0)ccur=ccur+4-ccur%4;
                    a[cnt].gst.push_back(ccur);
                    a[cnt].ged.push_back(ccur+3);
                    ccur+=4;
                }
                else if(type=="long"){
                    mxdq=max(mxdq,8ll);
                    a[cnt].gsize.push_back(8);
                    if(ccur%8!=0)ccur=ccur+8-ccur%8;
                    a[cnt].gst.push_back(ccur);
                    a[cnt].ged.push_back(ccur+7);
                    ccur+=8;
                }
                else{
                    int tpid=mp[type];
                    long long ld=a[tpid].mxdq;
                    mxdq=max(mxdq,ld);
                    a[cnt].gsize.push_back(a[tpid].mxx);
                    if(ccur%ld!=0)ccur=ccur+ld-ccur%ld;
                    a[cnt].gst.push_back(ccur);
                    a[cnt].ged.push_back(ccur+a[tpid].mxx-1);
                    ccur+=a[tpid].mxx;
                }
            }
            if(ccur%mxdq!=0)ccur=ccur+mxdq-ccur%mxdq;
            a[cnt].mxx=ccur;
            a[cnt].mxdq=mxdq;
            cout<<a[cnt].mxx<<" "<<mxdq<<"\n";
        }
        else if(op==2){
            string type,name;
            cin>>type>>name;
            gname.push_back(name);
            gtype.push_back(type);
            if(type=="byte"){
                gsize.push_back(1);
                cout<<cur<<"\n";
                gst.push_back(cur);
                ged.push_back(cur);
                cur++;
            }
            else if(type=="short"){
                if(cur%2!=0)cur=cur+2-cur%2;
                gsize.push_back(2);
                cout<<cur<<"\n";
                gst.push_back(cur);
                ged.push_back(cur+1);
                cur+=2;
            }
            else if(type=="int"){
                if(cur%4!=0)cur=cur+4-cur%4;
                gsize.push_back(4);
                cout<<cur<<"\n";
                gst.push_back(cur);
                ged.push_back(cur+3);
                cur+=4;
            }
            else if(type=="long"){
                if(cur%8!=0)cur=cur+8-cur%8;
                gsize.push_back(8);
                cout<<cur<<"\n";
                gst.push_back(cur);
                ged.push_back(cur+7);
                cur+=8;
            }
            else{
                int id=mp[type];
                long long dq=a[id].mxdq,mxx=a[id].mxx;
                if(cur%dq!=0)cur=cur+dq-cur%dq;
                gsize.push_back(a[id].mxx);
                cout<<cur<<"\n";
                gst.push_back(cur);
                ged.push_back(cur+a[id].mxx-1);
                cur+=a[id].mxx;
            }
        }
        else if(op==3){
            string name;
            cin>>name;
            cout<<fname(name)<<"\n";
        }
        else{
            long long aa;
            cin>>aa;
            cout<<scache(aa)<<"\n";
        }
    }
    return 0;
}
//Workingmen of all countries, unite!
