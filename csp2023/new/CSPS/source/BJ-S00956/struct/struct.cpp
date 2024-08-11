#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node
{
    int v;
    string s;
    ll l,r,sz;
};
int n,cnt=5;
vector<node> g[maxn];
int get_id(int u,string str)//in->u,out->e
{
    for(int i=0;i<g[u].size();i++) if(g[u][i].s==str) return i;
    return -1;
}
int get_pid(int u,ll pos)
{
    for(int i=0;i<g[u].size();i++)
        if(pos>=g[u][i].l && pos<=g[u][i].r) return i;
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    string s,ty,nm;
    int k,op,e;
    ll sz,dq,l,r,now,pos;
    //0.r->sz-1
    g[0].push_back((node){2,"byte",0,0,1});
    g[0].push_back((node){3,"short",0,1,2});
    g[0].push_back((node){4,"int",0,3,4});
    g[0].push_back((node){5,"long",0,7,8});
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        //cout<<i<<endl;
        if(op==1)
        {
            cnt++;
            cin>>s>>k;
            now=sz=dq=0;
            for(int j=1;j<=k;j++)
            {
                cin>>ty>>nm;
                e=get_id(0,ty);
                l=((now+g[0][e].sz-1)/g[0][e].sz)*g[0][e].sz;
                g[cnt].push_back((node){g[0][e].v,nm,l,l+g[0][e].r,g[0][e].sz});
                now=l+g[0][e].r+1,dq=max(dq,g[0][e].sz);
            }
            sz=((now+dq-1)/dq)*dq-1;
            g[0].push_back((node){cnt,s,0,sz,dq});
            cout<<sz+1<<' '<<dq<<'\n';
        }
        if(op==2)
        {
            cin>>ty>>nm;
            e=get_id(0,ty);
            sz=g[0][e].sz;
            if(g[1].size()==0) l=0;
            else l=g[1][g[1].size()-1].r+1;
            l=((l+sz-1)/sz)*sz;
            r=l+g[0][e].r;
            r=((r+1+sz-1)/sz)*sz-1;
            g[1].push_back((node){g[0][e].v,nm,l,r,sz});
            cout<<l<<'\n';
        }
        if(op==3)
        {
            cin>>s;
            now=1,pos=0;
            s=s+".";
            nm.clear();
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='.')
                {
                    e=get_id(now,nm);
                    //if(e==-1) cout<<s<<' '<<nm<<' '<<j<<endl;
                    pos=pos+g[now][e].l;
                    now=g[now][e].v;
                    nm.clear();
                }
                else nm.push_back(s[j]);
            }
            cout<<pos<<'\n';
        }
        if(op==4)
        {
            cin>>pos;
            now=1;
            s.clear();
            while(1)
            {
                e=get_pid(now,pos);
                if(e==-1)
                {
                    cout<<"ERR\n";
                    break;
                }
                pos=pos-g[now][e].l;
                nm=g[now][e].s;
                if(s.size()>0) s.push_back('.');
                for(int j=0;j<nm.size();j++) s.push_back(nm[j]);
                if(g[g[now][e].v].size()==0)
                {
                    cout<<s<<'\n';
                    break;
                }
                now=g[now][e].v;
            }
        }
    }
    return 0;
}
