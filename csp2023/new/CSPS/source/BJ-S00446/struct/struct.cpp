#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Stru{
    string nam;
    int k;
    int duiqi;
    int siz;
    int a[101],s[101],o[101];
    string t[101],n[101];
}st[110];
int cnt;//st的
int x_cnt;//下标的cnt
int yt_cnt;//元素的cnt
struct YuanShu{
    string t,n;
    int s;
    int b;//起始地址
    int a;//duiqiyaoqiu
}yt[110];
int n,op;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            int kk;
            cin>>st[++cnt].nam>>kk;
            st[cnt].k=kk;
            st[cnt].duiqi=1;
            for(int i=1;i<=kk;i++){
                cin>>st[cnt].t[i]>>st[cnt].n[i];
                if(st[cnt].t[i]=="byte"){
                    st[cnt].a[i]=st[cnt].s[i]=1;
                }else if(st[cnt].t[i]=="short"){
                    st[cnt].a[i]=st[cnt].s[i]=2;
                }else if(st[cnt].t[i]=="int"){
                    st[cnt].a[i]=st[cnt].s[i]=4;
                }else if(st[cnt].t[i]=="long"){
                    st[cnt].a[i]=st[cnt].s[i]=8;
                }else{
                    for(int j=1;j<cnt;j++){
                        if(st[j].nam==st[cnt].t[i]){
                            st[cnt].a[i]=st[j].duiqi;
                            st[cnt].s[i]=st[j].s[i];
                            break;
                        }
                    }
                }
                int r=st[cnt].a[i];
                st[cnt].duiqi=max(st[cnt].duiqi,r);
            }
            int aa=st[cnt].duiqi;
            st[cnt].o[1]=0;
            for(int i=2;i<=kk;i++){
                int nowa=st[cnt].o[i-1]+st[cnt].s[i-1];
                st[cnt].o[i]=(nowa-1)/st[cnt].a[i]*st[cnt].a[i]+st[cnt].a[i];
            }
            int nowa=st[cnt].o[kk]+st[cnt].s[kk];
            st[cnt].siz=(nowa-1)/aa*aa+aa;
            cout<<st[cnt].siz<<' '<<st[cnt].duiqi<<'\n';
        }
        if(op==2){
            string tt,nn;
            yt_cnt++;
            cin>>tt>>nn;
            int i=yt_cnt;
            yt[i].t=tt;
            yt[i].n=nn;
            if(tt=="byte"){
                yt[i].s=yt[i].a=1;
            }else if(tt=="short"){
                yt[i].s=yt[i].a=2;
            }else if(tt=="int"){
                yt[i].s=yt[i].a=4;
            }else if(tt=="long"){
                yt[i].s=yt[i].a=8;
            }else
            for(int j=1;j<=cnt;j++){
                if(st[j].nam==yt[i].t){
                    yt[i].s=st[j].siz;
                    yt[i].a=st[j].duiqi;
                break;}
            }//x_cnt-->
            if(i==1){
                yt[i].b=0;
                cout<<"0\n";
                continue;
            }
            int now=yt[i-1].b+yt[i-1].s,aa=yt[i].a;
            yt[i].b=(now-1)/aa*aa+aa;
            cout<<yt[i].b<<'\n';
        }
        if(op==3){
            string r;
            cin>>r;
            string nows="",nows1="";
            int now=0,ans=0;
            for(int i=0;i<r.length();i++){
                if(r[i]!='.'){
                    nows+=r[i];
                }else{
                    nows1=nows;
                    nows="";
                }
            }
            if(nows1==""){//不嵌套
                int j=1;
                for(j=1;j<=yt_cnt;j++){
                    if(yt[j].n==nows){
                        break;
                    }
                }
                cout<<yt[j].b<<'\n';
            }else{
                int j=1;
                for(j=1;j<=yt_cnt;j++){
                    if(yt[j].n==nows1){
                        break;
                    }
                }
                int p;
                for(p=1;p<=cnt;p++){
                    if(st[p].nam==yt[j].t)break;
                }

                //j中 的 nows
            }
        }
        if(op==4){
            int adr;
            cin>>adr;
            string ans="";
            int i=1;
            for(i=1;i<=yt_cnt;i++){
                if(yt[i].b+yt[i].s-1>=adr){
                    ans+=yt[i].n;
                    break;
                }
            }
            if(ans==""){
                cout<<"ERR\n";continue;
            }
            if(yt[i].t=="short"||yt[i].t=="byte"||yt[i].t=="int"||yt[i].t=="long"){
                if(yt[i].b<=adr&&adr<=yt[i].b+yt[i].s-1)cout<<ans<<"\n";
                else cout<<"ERR\n";
                continue;
            }//yti三是一个结构体
            int j=1;
            for(j=1;j<=cnt;j++){
                if(st[j].nam==yt[i].t)break;
            }int fla=0;
            for(int p=1;p<=st[j].k;p++){
                if(yt[i].b+st[j].o[p-1]<=adr&&adr<=yt[i].b+st[j].o[p]-1){
                    fla=1;
                    cout<<ans<<"."<<st[j].n[p]<<'\n';break;
                }
            }
            if(fla)continue;
            cout<<"ERR\n";
        }
    }//yt[yt_cnt].b+yt[yt_cnt].s-1
    return 0;
}
