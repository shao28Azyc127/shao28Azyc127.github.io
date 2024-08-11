#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
using namespace std;
#define int long long
const int N=110;
int n;
struct node{
    string typ,nam;
    int pos;
};
inline bool operator<(const node&x,const node&y){return x.pos<y.pos;}
set<node>mem2[N];
map<string,node>mem[N];
map<string,int>id;
int siz[N],mx[N],pos[N],tot;
string type[N],name[N];
inline int get_pos(const string&loc){
    string ele;
    int len=loc.size(),p=0;
    for(;p<len;p++){
        if(loc[p]=='.')break;
        else ele+=loc[p];
    }
    int now=id[ele];
    int res=pos[now];
    now=id[type[now]];
    ele.clear();
    for(p++;p<len;p++){
        if(loc[p]=='.'){
            node nex=mem[now][ele];
            res+=nex.pos;
            now=id[nex.typ];
            ele.clear();
        }
        else ele+=loc[p];
    }
    node nex=mem[now][ele];
    res+=nex.pos;
    ele.clear();
    return res;
}
inline string get_nam(int k){
    if(!tot)return"ERR";
    int p=upper_bound(pos+1,pos+tot+1,k)-pos-1;
    // cout<<*lower_bound(pos+1,pos+tot+1,k)<<endl;
    // cout<<p<<endl;
    k-=pos[p];
    string res=name[p];
    if(type[p]=="byte"){
        if(k>0)return "ERR";
        else return res;
    }
    else if(type[p]=="short"){
        if(k>1)return"ERR";
        else return res;
    }
    else if(type[p]=="int"){
        if(k>3)return"ERR";
        else return res;
    }
    else if(type[p]=="long"){
        if(k>7)return"ERR";
        else return res;
    }
    int now=id[type[p]];
    while(true){
        // node sub=*mem[now].begin();
        // for(node i:mem[now])if(i.pos<=k&&i.pos>sub.pos)sub=i;
        auto it=mem2[now].upper_bound((node){"0","0",k});
        // cout<<now<<endl;
        // cout<<mem2[now].size()<<endl;
        // cout<<(mem2[now].begin()->pos)<<' '<<(it->pos)<<' '<<k<<endl;
        assert(it!=mem2[now].begin());
        it--;
        res+="."+(it->nam);
        k-=it->pos;
        string typ=it->typ;
        if(typ=="byte"){
            if(k>0)return "ERR";
            else return res;
        }
        else if(typ=="short"){
            if(k>1)return"ERR";
            else return res;
        }
        else if(typ=="int"){
            if(k>3)return"ERR";
            else return res;
        }
        else if(typ=="long"){
            if(k>7)return"ERR";
            else return res;
        }
        else now=id[typ];
    }
}
signed main(){
    ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
    // freopen("struct/struct3.in","r",stdin);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int now=0;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(t==1){
            string nam;cin>>nam;
            id[nam]=i;
            int k;cin>>k;
            for(int j=1;j<=k;j++){
                // cout<<siz[i]<<' ';
                string typ,sub;cin>>typ>>sub;
                if(typ=="byte"){
                    mx[i]=max(mx[i],1ll);
                    mem[i][sub]=((node){typ,sub,siz[i]});
                    mem2[i].insert((node){typ,sub,siz[i]});
                    siz[i]++;
                }
                else if(typ=="short"){
                    mx[i]=max(mx[i],2ll);
                    siz[i]=(siz[i]+1)/2*2;
                    mem[i][sub]=((node){typ,sub,siz[i]});
                    mem2[i].insert((node){typ,sub,siz[i]});
                    siz[i]+=2;
                }
                else if(typ=="int"){
                    mx[i]=max(mx[i],4ll);
                    siz[i]=(siz[i]+3)/4*4;
                    mem[i][sub]=((node){typ,sub,siz[i]});
                    mem2[i].insert((node){typ,sub,siz[i]});
                    siz[i]+=4;
                }
                else if(typ=="long"){
                    mx[i]=max(mx[i],8ll);
                    siz[i]=(siz[i]+7)/8*8;
                    mem[i][sub]=((node){typ,sub,siz[i]});
                    mem2[i].insert((node){typ,sub,siz[i]});
                    siz[i]+=8;
                }
                else{
                    int p=id[typ];
                    mx[i]=max(mx[i],mx[p]);
                    siz[i]=(siz[i]+mx[p]-1)/mx[p]*mx[p];
                    mem[i][sub]=((node){typ,sub,siz[i]});
                    mem2[i].insert((node){typ,sub,siz[i]});
                    siz[i]+=siz[p];
                }
            }
            // cout<<siz[i]<<' ';
            siz[i]=(siz[i]+mx[i]-1)/mx[i]*mx[i];
            cout<<siz[i]<<' '<<mx[i]<<'\n';
        }
        else if(t==2){
            string typ,nam;cin>>typ>>nam;
            id[nam]=++tot;
            name[tot]=nam;
            type[tot]=typ;
            if(typ=="byte"){
                pos[tot]=now;
                cout<<now<<'\n';
                now++;
            }
            else if(typ=="short"){
                now=(now+1)/2*2;
                pos[tot]=now;
                cout<<now<<'\n';
                now+=2;
            }
            else if(typ=="int"){
                now=(now+3)/4*4;
                pos[tot]=now;
                cout<<now<<'\n';
                now+=4;
            }
            else if(typ=="long"){
                now=(now+7)/8*8;
                pos[tot]=now;
                cout<<now<<'\n';
                now+=8;
            }
            else{
                int p=id[typ];
                now=(now+mx[p]-1)/mx[p]*mx[p];
                pos[tot]=now;
                cout<<now<<'\n';
                now+=siz[p];
            }
        }
        else if(t==3){
            string loc;cin>>loc;
            cout<<get_pos(loc)<<'\n';
        }
        else {
            int k;cin>>k;
            cout<<get_nam(k)<<'\n';
        }
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
