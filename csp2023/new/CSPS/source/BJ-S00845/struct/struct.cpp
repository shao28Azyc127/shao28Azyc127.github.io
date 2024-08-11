#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=125;
int n;
map<string,int> id;
struct Node{
    ll siz;
    int str;
    string name;
};
struct Str{
    ll lim;
    ll siz;
    bool end;
    int tot;
    vector<Node> var;
};
struct Var{
    ll siz;
    int str;
    string name;
};
Str stru_name[N];
Var var_name[N];
ll total_siz=0;
int strtot=0,vartot=0;
string ans[N];
int anstot=0;
inline ll getaddr(ll now,ll siz){
    ll k=now%siz;
    if(k>0) return now-k+siz;
    else return now;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);

    strtot=4;
    id["byte"]=1;
    id["short"]=2;
    id["int"]=3;
    id["long"]=4;
    for(int j=1;j<=4;j++) stru_name[j].end=true,stru_name[j].lim=stru_name[j].siz=(1<<(j-1));

    string str_nam,var_nam,str;
    int k;
    for(int i=1;i<=n;i++){
        int op;
        scanf("%d",&op);
        if(op==1){
            cin>>str_nam>>k;
            strtot++;
            id[str_nam]=strtot;
            stru_name[strtot].end=false;
            stru_name[strtot].tot=k;
            ll nowsiz=0;
            ll nowlim=0;
            for(int j=1;j<=k;j++){
                cin>>str>>var_nam;
                int p=id[str];
                ll siz=stru_name[p].siz,lim=stru_name[p].lim;
                nowsiz=getaddr(nowsiz,lim);
                nowlim=max(nowlim,lim);
                stru_name[strtot].var.push_back((Node){nowsiz,p,var_nam});
                nowsiz+=siz;
            }
            nowsiz=getaddr(nowsiz,nowlim);
            stru_name[strtot].siz=nowsiz,stru_name[strtot].lim=nowlim;
            printf("%lld %lld\n",nowsiz,nowlim);
        }
        else if(op==2){
            cin>>str_nam>>var_nam;
            int p=id[str_nam];
            vartot++;
            var_name[vartot].str=p;
            var_name[vartot].name=var_nam;
            total_siz=getaddr(total_siz,stru_name[p].lim);
            var_name[vartot].siz=total_siz;
            printf("%lld\n",total_siz);
            total_siz+=stru_name[p].siz;
        }
        else if(op==3){
            cin>>str_nam;
            ll pre=0;
            int nv=0,nowstr=0;
            int ss=str_nam.size();
            int jiba=0,get=0;
            string hel;
            for(int j=0;j<ss;j++){
                if(str_nam[j]=='.' || j==ss-1){
                    if(j==ss-1){
                        hel.resize(j+1-jiba);
                        for(int l=jiba;l<=j;l++) hel[l-jiba]=str_nam[l];
                    }
                    else{
                        hel.resize(j-jiba);
                        for(int l=jiba;l<j;l++) hel[l-jiba]=str_nam[l];
                    }
                    get++;
                    if(get==1){
                        for(int l=1;l<=vartot;l++){
                            if(var_name[l].name==hel){
                                nv=l;
                                break;
                            }
                        }
                        pre=var_name[nv].siz;
                        nowstr=var_name[nv].str;
                    }
                    else{
                        for(int l=0;l<stru_name[nowstr].tot;l++){
                            if(stru_name[nowstr].var[l].name==hel){
                                nv=l;
                                break;
                            }
                        }
                        pre+=stru_name[nowstr].var[nv].siz;
                        nowstr=stru_name[nowstr].var[nv].str;
                    }
                    jiba=j+1;
                }
            }
            printf("%lld\n",pre);
        }
        else if(op==4){
            ll addr;
            scanf("%lld",&addr);
            if(total_siz<=addr){
                printf("ERR\n");
                continue;
            }
            ll pre=0;
            int nv=0;
            for(int j=1;j<=vartot;j++){
                if(var_name[j].siz>addr) break;
                nv=j;
                pre=var_name[j].siz;
            }
            int nowstr=var_name[nv].str;
            anstot=0;
            ans[++anstot]=var_name[nv].name;
            while(!stru_name[nowstr].end){
                for(int j=0;j<stru_name[nowstr].tot;j++){
                    if(pre+stru_name[nowstr].var[j].siz>addr) break;
                    nv=j;
                }
                pre+=stru_name[nowstr].var[nv].siz;
                ans[++anstot]=stru_name[nowstr].var[nv].name;
                nowstr=stru_name[nowstr].var[nv].str;
            }
            if(pre+stru_name[nowstr].siz<=addr){
                printf("ERR\n");
                continue;
            }
            for(int j=1;j<=anstot;j++){
                cout<<ans[j];
                if(j<anstot) cout<<".";
            }
            printf("\n");
        }
    }
    return 0;
}