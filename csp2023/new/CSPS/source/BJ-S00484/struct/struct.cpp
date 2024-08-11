#include<bits/stdc++.h>
using namespace std;
const int N=105;
int id;
int n,k,cnt,cnt2;
map <string,int> mp;
long long siz[N],emp[N];
vector <int> g[N];
vector <long long> beg[N];
vector <string> son[N];
map <string,int> mp2;
string name[N];
long long typ[N],st[N];
long long now;
void work1()
{
    string s;
    cin>>s;
    mp[s]=++cnt;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        string x,y;
        cin>>x>>y;
        g[cnt].push_back(mp[x]);
        son[cnt].push_back(y);
    }
    siz[cnt]=emp[cnt]=0;
    long long now=0;
    for(int i=0;i<g[cnt].size();i++)
    {
        int t=g[cnt][i];
        now=(now+emp[t]-1)/emp[t]*emp[t];
        beg[cnt].push_back(now);
        now+=siz[t];
        emp[cnt]=max(emp[cnt],emp[t]);
    }
    siz[cnt]=(now+emp[cnt]-1)/emp[cnt]*emp[cnt];
    printf("%lld %lld\n",siz[cnt],emp[cnt]);
}
void work2()
{
    string x,y;
    cin>>x>>y;
    mp2[y]=++cnt2;
    name[cnt2]=y;
    typ[cnt2]=mp[x];
    int t=typ[cnt2];
    now=(now+emp[t]-1)/emp[t]*emp[t];
    printf("%lld\n",now);
    st[cnt2]=now;
    now+=siz[typ[cnt2]];
}
string cut(string s,int l,int r)
{
    string res="";
    for(int i=l;i<=r;i++) res+=s[i];
    return res;
}
void work3()
{
    string s;
    cin>>s;
    s+=".";
    int pre=0;
    int x=0;
    long long ans=-1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='.') continue;
        string t=cut(s,pre,i-1);
        pre=i+1;
        if(x==0)
        {
            x=typ[mp2[t]];
            ans=st[mp2[t]];
            continue;
        }
        //printf("%d %lld\n",x,ans);
        for(int j=0;j<g[x].size();j++)
        {
            int v=g[x][j];
            if(son[x][j]==t){ans+=beg[x][j];x=v;break;}
        }
        //printf("%d %lld\n",x,ans);
    }
    printf("%lld\n",ans);
}
bool check(int x,long long addr)
{
    if(x<=4)
    {
        if(addr<siz[x]) return true;
        return false;
    }
    //printf("%d:%lld\n",x,addr);
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        //if(id==22) printf("%d %d:%lld\n",x,v,beg[x][i]);
        if(addr<beg[x][i]) return false;
        if(addr<beg[x][i]+siz[v]) return check(v,addr-beg[x][i]);
    }
    return false;
}
void solve(int x,long long addr,string name)
{
    if(x<=4)
    {
        cout<<name;
        return;
    }
    //printf("%d:%lld\n",x,addr);
    cout<<name<<".";
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(addr<beg[x][i]+siz[v]){solve(v,addr-beg[x][i],son[x][i]);break;}
    }
}
void work4()
{
    long long addr;
    scanf("%lld",&addr);
    //if(id==22) printf("%lld\n",addr);
    if(addr>=now){printf("ERR\n");return;}
    int x=0;
    for(int i=1;i<=cnt2;i++)
    {
        //if(id==22) printf("%d:%lld %lld\n",i,st[i],siz[typ[i]]);
        if(addr<st[i]){printf("ERR\n");return;}
        if(addr<st[i]+siz[typ[i]]){x=i;break;}
    }
    addr-=st[x];
    if(!check(typ[x],addr)){printf("ERR\n");return;}
    solve(typ[x],addr,name[x]);
    printf("\n");
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"]=1;siz[1]=emp[1]=1;
    mp["short"]=2;siz[2]=emp[2]=2;
    mp["int"]=3;siz[3]=emp[3]=4;
    mp["long"]=4;siz[4]=emp[4]=8;
    cnt=4;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        id=i;
        int op;
        scanf("%d",&op);
        //if(i==27) printf("%d:::",op);
        if(op==1) work1();
        if(op==2) work2();
        if(op==3) work3();
        if(op==4) work4();
    }
    return 0;
}
