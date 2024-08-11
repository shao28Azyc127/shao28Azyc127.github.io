#include<bits/stdc++.h>
using namespace std;
#define N 110
#define int long long
int n,V=1e18,ndt,tot;
struct node{int len,mx,rt;map<string,int> st;map<int,string> ss;} o[N];
struct tnode{int l,r,id;string nm;} a[N*5000];
string tp,nm,now;
char c[15];
map<string,int> mp;
void ins(int &p,int l,int r,int ql,int qr,int id){
    if(!p) p=++tot;
    if(ql<=l&&qr>=r){a[p].id=id,a[p].nm=nm;return;}
    int mid=(l+r)>>1;
    if(ql<=mid) ins(a[p].l,l,mid,ql,qr,id);
    if(qr>mid) ins(a[p].r,mid+1,r,ql,qr,id);
}
void def(int x,int y){
    o[x].mx=max(o[x].mx,o[y].mx);
    if(o[x].len%o[y].mx) o[x].len=o[x].len-o[x].len%o[y].mx+o[y].mx;
    ins(o[x].rt,0,V,o[x].len,o[x].len+o[y].len-1,y);
    o[x].st[nm]=o[x].len;
    o[x].ss[o[x].len]=nm;
    o[x].len+=o[y].len;
}
int qpos(int p,int l,int r,int x){
    if(!p) return -1;
    if(a[p].id) return a[p].id;
    int mid=(l+r)>>1;
    if(x<=mid) return qpos(a[p].l,l,mid,x);
    else return qpos(a[p].r,mid+1,r,x);
}
vector<string> out;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    o[1].len=o[1].mx=1,o[2].len=o[2].mx=2,o[3].len=o[3].mx=4,o[4].len=o[4].mx=8;
    mp["byte"]=1,mp["short"]=2,mp["int"]=3,mp["long"]=4;
    ndt=4;
    for(int op,k,id,ans,pos,nid;n--;){
        cin>>op;
        if(op==1){
            ndt++;
            cin>>nm>>k;
            mp[nm]=ndt;
            for(int i=1;i<=k;++i){
                cin>>tp>>nm;
                def(ndt,mp[tp]);
            }
            ans=o[ndt].len;
            if(ans%o[ndt].mx) ans=ans-ans%o[ndt].mx+o[ndt].mx;
            cout<<(o[ndt].len=ans)<<' '<<o[ndt].mx<<'\n';
        }else if(op==2){
            cin>>tp>>nm;
            def(0,mp[tp]);
            cout<<(--o[0].ss.end())->first<<'\n';
        }else if(op==3){
            cin>>nm;id=ans=pos=0;
            for(int i=0;i<nm.size();++i){
                if(nm[i]=='.'||i==nm.size()-1){
                    memset(c,0,sizeof c);
                    if(nm[i]=='.') for(int j=pos;j<i;++j) c[j-pos]=nm[j];
                    else for(int j=pos;j<=i;++j) c[j-pos]=nm[j];
                    now=c;
                    k=o[id].st[now];
                    ans+=k;
                    id=qpos(o[id].rt,0,V,k);
                    pos=i+1;
                }
            }
            cout<<ans<<'\n';
        }else{
            cin>>k;
            id=0;
            out.clear();
            while(id<1||id>4){
                nid=qpos(o[id].rt,0,V,k);
                if(nid==-1) break;
                auto it=o[id].ss.upper_bound(k);
                it--;
                k-=it->first;
                out.push_back(it->second);
                id=nid;
            }
            if(nid==-1) cout<<"ERR\n";
            else{
                for(int i=0;i<out.size();++i){
                    cout<<out[i];
                    if(i!=out.size()-1) cout<<".";
                } cout<<'\n';
            }
        }
    }
}
