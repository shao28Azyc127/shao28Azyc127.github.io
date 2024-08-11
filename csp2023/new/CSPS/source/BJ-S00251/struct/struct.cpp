#include<bits/stdc++.h>
#define mp make_pair
//#define o1 first
//#define o2 second
typedef long long ll;
using namespace std;
ll mod=1011451403,base=131;
string aa;
/*inline Hash(string a){
    ll ans=0,b=1;
    for(int i=a.length()-1;i>=1;i--){
        ans+=b*(a[i]-'a');ans%=mod;
        b*=base;
        b%=mod;
    }return ans;
}*/
struct nd{
    ll siz,asiz,len=0;string t[120],v[120];ll a[120];
    //pair<int,int> [120];
};
map<string,nd> q;
string dl[120],dl2[120];
ll asz=0;
ll lenn=0;
//map<string,pair<int,int>[120]> d;
int dfs(string ps,ll p){
    ll id=p/q[ps].asiz;
    p%=q[ps].asiz;
    //cout<<q[ps].t[id]<<' '<<q[q[ps].t[id]].len<<' '<<q[q[ps].t[id]].siz<<' '<<p+1<<endl;
    if(q[q[ps].t[id]].len==0*1ll){aa+='.';aa+=q[ps].v[id];return 1;}
    if(q[q[ps].t[id]].siz>p+1){
        aa+='.';
        aa+=q[ps].v[id];
        return dfs(q[ps].t[id],p);
    }else{
        return -1;
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    int llen;
    scanf("%d",&n);
    q["short"].siz=2;q["short"].asiz=2;
    q["int"].siz=4;q["int"].asiz=4;
    q["byte"].siz=1;q["byte"].asiz=1;
    q["long"].siz=8;q["long"].asiz=8;
    for(int i=0;i<n;i++){
        int op;scanf("%d",&op);
        if(op==1){
            string k;cin>>k;int m;cin>>m;
            for(int i=0;i<m;i++){
                string tp,vb;
                cin>>tp>>vb;
                q[k].t[q[k].len]=tp;q[k].v[q[k].len]=vb;
                if(q[k].len==0) q[k].a[q[k].len++]=q[tp].siz;
                else q[k].a[q[k].len++]=max(q[k].a[q[k].len-1],q[tp].siz);
                q[k].asiz=max(q[tp].asiz,q[k].asiz);
                q[k].siz+=max(q[k].asiz,q[tp].siz)/**q[k].len*/;
                q[k].siz=q[k].len*q[k].asiz;
                //cout<<q[k].siz<<endl;
            }
            printf("%d %d\n",q[k].siz,q[k].asiz);
        }if(op==2){
            string tp,vb;
            cin>>tp>>vb;
            dl[lenn]=tp;dl2[lenn++]=vb;
            asz=max(asz,q[tp].siz);
            printf("%d\n",(lenn-1)*asz);
        }if(op==3){
            string tt;
            cin>>tt;
            tt+='.';
            int llen=tt.length();
            int s=0,l=0,ans=0;
            string ps="";
            for(int i=0;i<llen;i++){
                if(tt[i]!='.') l++;
                if(tt[i]=='.') {
                    string dd=tt.substr(s,l);
                    if(ps==""){
                        for(int i=0;i<lenn;i++){
                            if(dd==dl2[i]) ans+=i*asz,ps=dl[i];
                        }
                    }else{
                        for(int i=0;i<q[ps].len;i++){
                            if(dd==q[ps].v[i]) ans+=i*q[ps].asiz,ps=q[ps].t[i];
                        }
                    }
                    s=i+1;l=0;
                }
            }
            printf("%lld\n",ans);
        }
        if(op==4){
            ll addr;cin>>addr;
            aa="";
            ll iid=addr/asz;
            //cout<<q[dl[iid]].siz<<' '<<(addr%asz)+1<<endl;
            ll res=-1;if(q[dl[iid]].siz>(addr%asz)+1){aa+=dl2[iid];res=dfs(dl[iid],addr%asz);}
            if(res==-1) cout<<"ERR"<<'\n';
            else cout<<aa<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//A,B;
