#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=101,MAXL=2000;
int n;
struct node{
    int k;
    ll tp[MAXN],nm[MAXN];
    ll sz[MAXN];
    int mx[MAXN];
    ll ad[MAXN];
}t[MAXN];
int tot;
char ch[MAXL];
int len;
ll H(int l,int r){
    ll v=0;
    for(int i=l;i<=r;i++)v=v*27+ch[i]-'a'+1;
    return v;
}
ll cal(ll o,int a){
    return ((o+a-1)/a)*a;
}
int getid(ll v){
    if(v==58136)return -1;
    if(v==10266284)return -2;
    if(v==6959)return -4;
    if(v==247516)return -8;
    for(int i=1;i<=tot;i++)if(t[i].nm[0]==v)return i;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            tot++;
            cin>>ch+1;
            len=strlen(ch+1);
            t[tot].nm[0]=H(1,len);
            int k;
            cin>>k;
            t[tot].k=k;
            for(int i=1;i<=k;i++){
                cin>>ch+1;
                len=strlen(ch+1);
                int id=getid(t[tot].tp[i]=H(1,len));
                cin>>ch+1;
                len=strlen(ch+1);
                t[tot].nm[i]=H(1,len);
                if(id<0)t[tot].sz[i]=t[tot].mx[i]=-id;
                else t[tot].sz[i]=t[id].sz[0],t[tot].mx[i]=t[id].mx[0];
                t[tot].ad[i]=cal(t[tot].ad[i-1]+t[tot].sz[i-1],t[tot].mx[i]);
                t[tot].mx[0]=max(t[tot].mx[0],t[tot].mx[i]);
            }
            t[tot].sz[0]=cal(t[tot].ad[k]+t[tot].sz[k],t[tot].mx[0]);
            cout<<t[tot].sz[0]<<' '<<t[tot].mx[0]<<'\n';
        }
        if(op==2){
            int k=++t[0].k;
            cin>>ch+1;
            len=strlen(ch+1);
            int id=getid(t[0].tp[k]=H(1,len));
            cin>>ch+1;
            len=strlen(ch+1);
            t[0].nm[k]=H(1,len);
            if(id<0)t[0].sz[k]=t[0].mx[k]=-id;
            else t[0].sz[k]=t[id].sz[0],t[0].mx[k]=t[id].mx[0];
            t[0].ad[k]=cal(t[0].ad[k-1]+t[0].sz[k-1],t[0].mx[k]);
            cout<<t[0].ad[k]<<'\n';
        }
        if(op==3){
            cin>>ch+1;
            len=strlen(ch+1);
            int now=0,lst=1,pos=1;
            ll ans=0;
            while(pos<=len){
                while(pos<=len&&ch[pos]!='.')pos++;
                ll v=H(lst,pos-1);
                for(int i=1;i<=t[now].k;i++)
                    if(t[now].nm[i]==v){
                        ans+=t[now].ad[i];
                        now=getid(t[now].tp[i]);
                        break;
                    }
                lst=++pos;
            }
            cout<<ans<<'\n';
        }
        if(op==4){
            ll res;
            cin>>res;
            len=0;
            int now=0;
            while(now>=0){
                int pos;
                for(pos=1;pos<=t[now].k;pos++)
                    if(t[now].ad[pos]>res)break;
                pos--;
                res-=t[now].ad[pos];
                if(t[now].sz[pos]<=res)break;
                ll nm=t[now].nm[pos];
                int lnm=0;
                while(nm)lnm++,nm/=27;
                len+=lnm;
                nm=t[now].nm[pos];
                for(int i=0;i<lnm;i++){
                    ch[len-i]=nm%27-1+'a';
                    nm/=27;
                }
                ch[++len]='.';
                now=getid(t[now].tp[pos]);
            }
            ch[len]='\0';
            if(now<0)cout<<ch+1<<'\n';
            else cout<<"ERR\n";
        }
    }
    return 0;
}
