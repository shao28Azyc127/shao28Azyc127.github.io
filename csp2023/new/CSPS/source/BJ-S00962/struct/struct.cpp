#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
const int N=1e2+5;
int n,op,k,sz,mx[N],l,p,dx[N],bg[N],ed[N],lt,tl,si,is,ist[N],ard;
string s[N],tp,nm[N],tmp,out,mm;
bool isot,err,oo;
struct T {
    string name;
    int st,ed;
    int it;
};
vector<T> str[N];
int fdp(int l,int tz){
    if(l==0)
        return 0;
    int re=l+1;
    while(re%tz!=0){
        re++;
    }
    return re;
}
signed main() {
    //freopen("in.in","r",stdin);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s[++sz]>>k;
            //continue;
            l=0;
            for(int j=1;j<=k;j++){
                cin>>tp>>mm;
                //continue;
                if(tp=="type"){
                    mx[sz]=max(mx[sz],1ll);
                    p=fdp(l,1);
                    str[sz].push_back((T){mm,p+0,p+0,0});
                    l=p+0;
                    continue;
                }
                if(tp=="short"){
                    mx[sz]=max(mx[sz],2ll);
                    p=fdp(l,2);
                    str[sz].push_back((T){mm,p+0,p+1,0});
                    l=p+1;
                    continue;
                }
                if(tp=="int"){
                    mx[sz]=max(mx[sz],4ll);
                    p=fdp(l,4);
                    str[sz].push_back((T){mm,p+0,p+3,0});
                    l=p+3;
                    continue;
                }
                if(tp=="long"){
                    mx[sz]=max(mx[sz],8ll);
                    p=fdp(l,8);
                    str[sz].push_back((T){mm,p+0,p+7,0});
                    l=p+7;
                    continue;
                }
                for(int h=1;h<sz;h++){
                    if(tp==s[h]){
                        mx[sz]=max(mx[sz],mx[h]);
                        p=fdp(l,mx[h]);
                        str[sz].push_back((T){mm,p+0,p+mx[h]-1,h});
                        l=p+mx[h]-1;
                        break;
                    }
                }
            }
            //continue;
            dx[sz]=fdp(l,mx[sz]);
            cout<<dx[sz]<<" "<<mx[sz]<<endl;
        }
        if(op==2){
            cin>>tp>>nm[++si];
            //continue;
            ist[si]=0;
            if(tp=="type"){
                p=fdp(tl,1);
                bg[si]=p+0;
                ed[si]=p+0;
                tl=p+0;
                cout<<bg[si]<<endl;
                continue;
            }
            if(tp=="short"){
                p=fdp(tl,2);
                bg[si]=p+0;
                ed[si]=p+1;
                tl=p+1;
                cout<<bg[si]<<endl;
                continue;
            }
            if(tp=="int"){
                p=fdp(tl,4);
                bg[si]=p+0;
                ed[si]=p+3;
                tl=p+3;
                cout<<bg[si]<<endl;
                continue;
            }
            if(tp=="long"){
                p=fdp(tl,8);
                bg[si]=p+0;
                ed[si]=p+7;
                tl=p+7;
                cout<<bg[si]<<endl;
                continue;
            }
            for(int j=1;j<=sz;j++){
                if(s[j]==tp){
                    //cout<<"!!!\n";
                    p=fdp(tl,dx[j]);
                    bg[si]=p+0;
                    ed[si]=p+dx[j]-1;
                    tl=ed[si];
                    ist[si]=j;
                    cout<<bg[si]<<endl;
                    break;
                }
            }
        }
        if(op==3){
            cin>>tp;
            //continue;
            isot=false;
            for(int j=1;j<=si;j++){
                if(nm[j]==tp){
                    if(ist[j]){
                        is=ist[j];
                        l=bg[j];
                        break;
                    }
                    cout<<bg[j]<<endl;
                    isot=true;
                    break;
                }
            }
            if(isot) continue;
            tmp="";
            oo=false;
            for(int u=0;u<tp.size();u++){
                if(tp[u]=='.'){
                    if(!oo){
                        for(int j=1;j<=si;j++){
                            if(nm[j]==tmp){
                                is=ist[j];
                                l=bg[j];\
                                break;
                            }
                        }
                        oo=true;
                    }
                    else{
                        for(int j=0;j<str[is].size();j++){
                            if(str[is][j].name==tmp){
                                if(str[is][j].it!=0){
                                    p=str[is][j].it;
                                }
                                else{
                                    p=-1;
                                }
                                l+=str[is][j].st;
                                //cout<<l<<endl;
                                break;
                            }
                        }
                        is=p;
                    }
                    tmp="";
                }
                else{
                    tmp+=tp[u];
                    //tmp.append(tp[u]);
                }
            }
            for(int j=0;j<str[is].size();j++){
                if(str[is][j].name==tmp){
                    l+=str[is][j].st;
                    //cout<<l<<endl;
                    break;
                }
            }
            cout<<l<<endl;
        }
        if(op==4){
            cin>>ard;
            //continue;
            for(int j=1;j<=si;j++){
                if((j==si)||ard<bg[j+1]){
                    if(ard<bg[j]){
                        cout<<"ERR"<<endl;
                        break;
                    }
                    if(ist[j]){
                        out=nm[j];
                        ard-=bg[j];
                        p=ist[j];
                        err=false;
                        while(p!=-1){
                            //cout<<p<<"!!!\n";
                            //if(p==2)
                            //    break;
                            for(int u=0;u<str[p].size();u++){
                                if((u+1==str[p].size())||(u+1<str[p].size()&&ard<str[p][u+1].st)){
                                    if(ard<str[p][u].st){
                                        err=true;
                                        break;
                                    }
                                    out=out+"."+str[p][u].name;
                                    if(ard>str[p][u].ed){
                                        err=true;
                                        break;
                                    }
                                    if(str[p][u].it!=0){
                                        p=str[p][u].it;
                                    }
                                    else{
                                        p=-1;
                                    }
                                    break;
                                }
                            }
                            //cout<<p<<endl;
                            if(err)
                                break;
                        }
                        if(err)
                            cout<<"ERR"<<endl;
                        else
                            cout<<out<<endl;
                        break;
                    }
                    if(ard<=ed[j])
                        cout<<nm[j]<<endl;
                    else
                        cout<<"ERR"<<endl;
                    break;
                }
            }
        }
    }
    //for(int i=1;i<=si;i++)
    //    cout<<"***"<<bg[i]<<endl;
    return 0;
}
