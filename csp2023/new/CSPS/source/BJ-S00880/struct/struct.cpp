#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
using namespace std;
LL T,N;
map<string,LL>name2id;
map<string,LL>ele2id;
map<string,LL>jcn2sz;
struct stru{
    map<string,LL>name2mid;
    string mid2name[105];
    LL ele[105],en;
}sts[105];LL stsen;
struct node{
    LL stid,mxe,sz;
}yss[105];LL yssen;
string ans[100005];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    jcn2sz["byte"]=1;jcn2sz["short"]=2;jcn2sz["int"]=4;jcn2sz["long"]=8;
    while(T--){
        LL op,k,adr;string s,t,n;cin>>op;
        if(op==1){
            cin>>s>>k;stsen++;
            name2id[s]=stsen;
            LL sz=0,mxn=0;
            rep(i,1,k){
                cin>>t>>n;
                sts[stsen].name2mid[n]=++sts[stsen].en;
                sts[stsen].mid2name[sts[stsen].en]=n;
                sts[stsen].ele[sts[stsen].en]=jcn2sz[t];sz+=jcn2sz[t];mxn=max(mxn,jcn2sz[t]);
            }
            cout<<sz<<' '<<mxn<<'\n';
        }
        if(op==2){
            cin>>t>>n;yssen++;
            ele2id[n]=yssen;
            if(!jcn2sz[t]){
                yss[yssen].stid=ele2id[n];
                rep(i,1,sts[ele2id[n]].en)yss[yssen].mxe=max(yss[yssen].mxe,sts[ele2id[n]].ele[i]),yss[yssen].sz+=sts[ele2id[n]].ele[i];
                if(N%yss[yssen].mxe){
                    N+=yss[yssen].mxe;N-=N%yss[yssen].mxe;
                }
                cout<<N<<endl;
                rep(j,1,sts[ele2id[n]].en){
                    rep(i,N,N+sts[ele2id[n]].ele[j]-1)ans[i]=t+'.'+sts[ele2id[n]].mid2name[j];
                    N+=sts[ele2id[n]].ele[j];
                }
            }else{
                yss[yssen].stid=-1;
                yss[yssen].mxe=jcn2sz[t];
                yss[yssen].sz=jcn2sz[t];
                if(N%yss[yssen].mxe){
                    N+=yss[yssen].mxe;N-=N%yss[yssen].mxe;
                }
                cout<<N<<endl;
                rep(i,N,N+yss[yssen].sz-1)ans[i]=t;
                N+=yss[yssen].sz;
            }
        }
        if(op==3){
            cin>>s;
            string nt="";
            LL fiid=-1;
            for(char x:s){
                if(x!='.')nt+=x;
                else{
                    fiid=ele2id[nt];nt="";
                }
            }
            LL seid=-1;
            if(fiid==-1)fiid=ele2id[nt];
            else seid=sts[yss[ele2id[nt]].stid].name2mid[nt];
            LL ansn=0;
            rep(i,1,fiid-1){
                if(ansn%yss[i].mxe){
                    ansn+=yss[i].mxe;ansn-=ansn%yss[i].mxe;
                }
                ansn+=yss[i].sz;
            }
            if(ansn%yss[fiid].mxe){
                ansn+=yss[fiid].mxe;ansn-=ansn%yss[fiid].mxe;
            }
            if(seid!=-1){
                rep(i,1,seid-1)ansn+=sts[yss[fiid].stid].ele[i];
            }
            cout<<ansn<<'\n';
        }
        if(op==4){
            cin>>adr;
            if(ans[adr]!="")cout<<ans[adr]<<'\n';
            else puts("ERR");
        }
    }
    return 0;
}
