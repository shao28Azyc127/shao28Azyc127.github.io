#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <map>
using namespace std;
struct Node{
    long long k,len,rule;
    string s[205];
    map<string,int> mapn;
}node[205];
long long  n,opt,k,cnt=4,K;
string S[205];
map<string,int> mapp;
long long f(int id,string s1)
{
    long long l=0,len,rule; string s2,s3;s2=""; s3="";
        for(int i=0;i<s1.size();i++){
                if(s1[i]=='.'){
                    for(int j=i+1;j<s1.size();j++) s3+=s1[j];
                    break;
                }
            s2+=s1[i];
        }
    for(int i=0;i<node[id].k;i++){
            if(node[id].s[i]==s2){
                           rule=node[node[id].mapn[node[id].s[i]]].rule;
                        if(l%rule!=0) l=(l/rule+1)*rule;
                if(s3=="") return l;
                else return l+f(node[id].mapn[node[id].s[i]],s3);
            }
        len=node[node[id].mapn[node[id].s[i]]].len; rule=node[node[id].mapn[node[id].s[i]]].rule;
        if(l%rule!=0) l=(l/rule+1)*rule;
        l+=len;
    }

}
void f2(int id,int ad){
    long long l=0,lst=0,len,rule;
            for(int i=0;i<node[id].k;i++){
                    lst=l;
                len=node[node[id].mapn[node[id].s[i]]].len; rule=node[node[id].mapn[node[id].s[i]]].rule;
                if(l%rule!=0) l=(l/rule+1)*rule;
                if(ad<l) {cout<<"ERR"<<endl; break;}
                l+=len;
                if(ad<l){
                    if(node[id].mapn[node[id].s[i]]<=4) cout<<node[id].s[i]<<endl;
                    else {cout<<node[id].s[i]<<".";
                    f2(node[id].mapn[node[id].s[i]],ad-lst);}
                     break;
                }
            }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    string s1,s2,s3;
    node[1].len=1; node[1].rule=1;
    node[2].len=2; node[2].rule=2;
    node[3].len=4; node[3].rule=4;
    node[4].len=8; node[4].rule=8;
    mapp["byte"]=1; mapp["short"]=2; mapp["int"]=3; mapp["long"]=4;
    while(n--){
        cin>>opt;
        if(opt==1){
            cin>>s1>>k;
            mapp[s1]=++cnt; node[cnt].k=k;
            long long l=0,r=1;
            for(int i=0;i<k;i++){
                cin>>s2>>s3; node[cnt].s[i]=s3; node[cnt].mapn[s3]=mapp[s2];
                long long len=node[mapp[s2]].len,rule=node[mapp[s2]].rule;
                if(l%rule!=0) l=(l/rule+1)*rule;
                l+=len; r=max(r,rule);
            }
            if(l%r!=0) l=(l/r+1)*r;
            node[cnt].len=l; node[cnt].rule=r;
            cout<<l<<" "<<r<<endl;
        }
        if(opt==2){
            cin>>s1>>s2;
            long long l=0;
            for(int i=0;i<K;i++){
                long long len=node[mapp[S[i]]].len,rule=node[mapp[S[i]]].rule;
                if(l%rule!=0) l=(l/rule+1)*rule;
                l+=len;
            }
            S[K++]=s2; mapp[s2]=mapp[s1];
            long long rule=node[mapp[s2]].rule;
            if(l%rule!=0) l=(l/rule+1)*rule;
            cout<<l<<endl;
        }
        if(opt==3){
            cin>>s1; s2=""; s3="";
            for(int i=0;i<s1.size();i++){
                    if(s1[i]=='.'){
                        for(int j=i+1;j<s1.size();j++) s3+=s1[j];
                        break;
                    }
                s2+=s1[i];
            }
            long long l=0,len,rule;
            for(int i=0;i<K;i++){
                    if(S[i]==s2){
                           rule=node[mapp[S[i]]].rule;
                        if(l%rule!=0) l=(l/rule+1)*rule;

                            if(s3=="") cout<<l<<endl;
                            else cout<<l+f(mapp[S[i]],s3)<<endl;
                        break;
                    }
                len=node[mapp[S[i]]].len; rule=node[mapp[S[i]]].rule;
                if(l%rule!=0) l=(l/rule+1)*rule;
                l+=len;
            }
        }
        if(opt==4){
            long long ad;
            cin>>ad;
            long long l=0,lst=0,len,rule;
            for(int i=0;i<K;i++){
                    lst=l;
                len=node[mapp[S[i]]].len; rule=node[mapp[S[i]]].rule;
                if(l%rule!=0) l=(l/rule+1)*rule;
                if(ad<l) {cout<<"ERR"<<endl; break;}
                l+=len;
                if(ad<l){
                        if(mapp[S[i]]<=4) cout<<S[i]<<endl;
                        else cout<<S[i]<<"."; f2(mapp[S[i]],ad-lst);
                        break;
                }
            }
            if(ad>=l) cout<<"ERR"<<endl;
        }
    }
    return 0;
}

