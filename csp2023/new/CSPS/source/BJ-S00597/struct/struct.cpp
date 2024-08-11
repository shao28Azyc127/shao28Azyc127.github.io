#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='0') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=105;
struct strt{
    string t[N],name[N];
    int k,same,siz;
};
struct comp{
    string name;
    int addr;
};
struct member{
    string t;
    int addr;
};
map<string,strt> mp;
map<string,member> mem;
map<comp,member> nmem;
bool operator<(const comp &A,const comp &B){
    return A.addr<B.addr;
}
int newceil(int n,int m){
    if(n%m==0) return n/m;
    return n/m+1;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int q=read();
    int lst=0;
    mp["byte"].siz=mp["byte"].same=1;
    mp["short"].siz=mp["short"].same=2;
    mp["int"].siz=mp["int"].same=4;
    mp["long"].siz=mp["long"].same=8;
    while(q--){
        int op=read();
        if(op==1){
            string name;
            int k;
            cin>>name>>k;
            int same=0;
            for(int i=1;i<=k;i++){
                string t,nm;
                cin>>t>>nm;
                if(t=="byte") same=max(same,1);
                else if(t=="short") same=max(same,2);
                else if(t=="int") same=max(same,4);
                else if(t=="long") same=max(same,8);
                else same=max(same,mp[t].siz);
                mp[name].t[i]=t,mp[name].name[i]=nm;
            }
            mp[name].k=k,mp[name].siz=same*k,mp[name].same=same;
            cout<<same*k<<" "<<same<<'\n';
        }else if(op==2){
            string t,name;
            cin>>t>>name;
            int siz=mp[t].siz,same=mp[t].same;
            lst=newceil(lst,same)*same;
            cout<<lst<<'\n';
            mem[name]={t,lst};
            lst+=siz;
        }else if(op==3){
            string s;
            cin>>s;
            s+='#';
            string name="",str;
            int stt=0,ad=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    str=mem[name].t;
                    stt=i+1;
                    break;
                }else if(s[i]=='#'){
                    strt tmp=mp[str];
                    for(int j=1;j<=tmp.k;j++){
                        if(tmp.name[j]==name){
                            stt=i+1;
                            break;
                        }
                        else if(s=="byte") ad++;
                        else if(s=="short") ad+=2;
                        else if(s=="int") ad+=3;
                        else ad+=4;
                    }
                }
                else name+=s[i];
            }
            if(ad==0) ad=mem[name].addr;
            name="";
            for(int i=stt;i<s.size();i++){
                if(s[i]=='.'){
                    strt tmp=mp[str];
                    int pot;
                    for(int j=1;j<=tmp.k;j++){
                        if(tmp.name[j]==name){
                            pot=j;
                            break;
                        }
                        else if(s=="byte") ad++;
                        else if(s=="short") ad+=2;
                        else if(s=="int") ad+=3;
                        else if(s=="long") ad+=4;
                        else ad+=mp[tmp.t[j]].siz;
                    }
                    str=tmp.t[pot];
                    name="";
                }else if(s[i]=='#'){
                    strt tmp=mp[str];
                    for(int j=1;j<=tmp.k;j++){
                        if(tmp.name[j]==name) break;
                        else if(s=="byte") ad++;
                        else if(s=="short") ad+=2;
                        else if(s=="int") ad+=3;
                        else ad+=4;
                    }
                }else name+=s[i];
            }
            cout<<ad<<endl;
        }else{
            int addr=read();
            string ans="";
            int same,ad;
            for(auto it=mem.begin();it!=mem.end();it++){
                nmem.insert(pair<comp,member>({it->first,(it->second).addr},it->second));
            }
            for(auto it=nmem.begin();it!=nmem.end();it++){
                ad=(it->second).addr;
                if(ad<=addr&&ad+mp[(it->second).t].siz>addr){
                    ans+=(it->first).name;
                    same=mp[(it->second).t].same;
                    if((it->second).t=="byte"||(it->second).t=="short"||(it->second).t=="int"||(it->second).t=="long") ad+=mp[(it->second).t].same;
                    else{
                        strt str=mp[(it->second).t];
                        bool flag=true;
                        while(flag){
                            for(int i=1;i<=str.k+1;i++){
                                if(ad>addr){
                                    string t=str.t[i-1];
                                    ans+='.';
                                    ans+=str.name[i];
                                    same=str.same;
                                    flag=false;
                                    if(t=="byte") ad-=same;
                                    else if(t=="short") ad-=same;
                                    else if(t=="int") ad-=same;
                                    else if(t=="long") ad-=same;
                                    else{
                                        same=mp[t].siz;
                                        str=mp[t];
                                        ad-=mp[t].siz;
                                        flag=true;
                                    }
                                    break;
                                }else{
                                    string t=str.t[i];
                                    ad+=mp[t].siz;
                                }
                            }
                        }
                    }
                }
            }
            if(ad-addr>same) cout<<"ERR\n";
            else cout<<ans<<'\n';
        }
    }
    return 0;
}
