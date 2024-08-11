#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=200+5,vt_MAX=2000+5,s_MAX=1000000+5;
const char basic_name[5][100]={"","byte","short","int","long"};
char s[s_MAX],t[s_MAX],h[s_MAX];
int n=4,q,cnt[n_MAX];
struct Trie
{
    signed ch[vt_MAX][26],vt,id[vt_MAX];
    void Insert(const char s[],const int ID)
    {
        int u=0;
        const int len=strlen(s);
        For(i,0,len-1)
        {
            const int c=(s[i]-'a');
            if(!ch[u][c]) ch[u][c]=(++vt);
            u=ch[u][c];
        }
        id[u]=ID;
    }
    int Query(const char s[])
    {
        int u=0;
        const int len=strlen(s);
        For(i,0,len-1)
        {
            const int c=(s[i]-'a');
            if(!ch[u][c]) return (-1);
            u=ch[u][c];
        }
        return id[u];
    }
};
Trie MP,T[n_MAX];
vector<int> a[n_MAX];
char b[n_MAX][n_MAX][20];
vector<int> L[n_MAX],R[n_MAX];
int sz[n_MAX]={0,1,2,4,8},glob;
int dq[n_MAX]={0,1,2,4,8};
pair<int,int> Find(const int u,char s[])
{
    int cut=0;
    while(s[cut]!='.') ++cut;
    const char mem=s[cut];
    s[cut]='\0';
    const int rs=T[u].Query(s);
    s[cut]=mem;
    return make_pair(rs,cut);
}
pair<int,int> path[n_MAX]; int tp;
long long Locate(const int u,const int loc)
{
    if(loc>=sz[u]) return (-1);
    if(!cnt[u])
    {
        return 0;
    }
    For(i,0,cnt[u]-1)
    {
        if(L[u][i]<=loc&&loc<=R[u][i])
        {
            const long long x=Locate(a[u][i],loc-L[u][i]);
            if(x==(-1)) return (-1);
            else
            {
                path[++tp]={u,i};
                return (L[u][i]+x);
            }
        }
    }
    return (-1);
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>q;
    For(i,1,4) MP.Insert(basic_name[i],i);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int k;
            cin>>s>>k,++n,MP.Insert(s,n),cnt[n]=k;
            For(i,0,k-1)
            {
                cin>>t>>h;
                const int len=strlen(h);
                For(j,0,len-1) b[n][i][j]=h[j];
                const int u=MP.Query(t);
                a[n].push_back(u);
                T[n].Insert(h,i);
            }
            For(i,0,k-1) dq[n]=max(dq[n],dq[a[n][i]]);
            L[n].resize(k),R[n].resize(k);
            int cur=0;
            For(i,0,k-1)
            {
                while(cur%dq[a[n][i]]) ++cur;
                L[n][i]=cur,R[n][i]=(cur+sz[a[n][i]]-1);
                cur+=sz[a[n][i]];
            }
            sz[n]=cur;
            while(sz[n]%dq[n]) ++sz[n];
            cout<<sz[n]<<' '<<dq[n]<<'\n';
        }
        else if(op==2)
        {
            cin>>t>>h;
            const int u=MP.Query(t);
            a[0].push_back(u),++cnt[0],T[0].Insert(h,cnt[0]-1);
            const int len=strlen(h);
            For(j,0,len-1) b[0][cnt[0]-1][j]=h[j];
            while(glob%dq[u]) ++glob;
            cout<<glob<<'\n';
            L[0].push_back(glob),R[0].push_back(glob+sz[u]-1),glob+=sz[u];
            sz[0]=glob;
        }
        else if(op==3)
        {
            cin>>s;
            const int len=strlen(s);
            s[len]='.',s[len+1]='\0';
            int u=0,cut=0,ans=0;
            while(s[cut])
            {
                const pair<int,int> P=Find(u,s+cut);
                const int i=P.first,plus=P.second;
                ans+=L[u][i],u=a[u][i];
                cut+=(plus+1);
            }
            cout<<ans<<'\n';
        }
        else
        {
            long long add=0;
            cin>>add,tp=0;
            const long long P=Locate(0,add);
            if(P==(-1)) cout<<"ERR\n";
            else
            {
                For_down(i,tp,1)
                {
                    cout<<b[path[i].first][path[i].second];
                    if(i>=2) cout<<'.';
                    else cout<<'\n';
                }
            }
        }
    }
    return 0;
}