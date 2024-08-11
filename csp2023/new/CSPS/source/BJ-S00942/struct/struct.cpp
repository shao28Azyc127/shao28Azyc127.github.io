#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mem//a member of a structure
{
    int type;
    int id;
    string name;
};
struct v//a val in stak
{
    string name;
    string typname;
    ll llast;//sum ll before
}stak[110];
map<string,int> mv;

struct s//structs
{
    string typname;
    string child2[110];
    map<string,mem> child;//the mem
    ll l=0;//max len of its mem
    ll len=0;//len of this structure
}structs[110];
map<string,int> ms;

int cntv,cnts;

string str,strn;//input

void set()//set basic types
{
    cnts=4;
    structs[0].typname="byte";
    structs[0].l=1;
    structs[0].len=1;
    ms[structs[0].typname]=0;
    structs[1].typname="short";
    structs[1].l=2;
    structs[1].len=2;
    ms[structs[1].typname]=1;
    structs[2].typname="int";
    structs[2].l=4;
    structs[2].len=4;
    ms[structs[2].typname]=2;
    structs[3].typname="long";
    structs[3].l=8;
    structs[3].len=8;
    ms[structs[3].typname]=3;
}

void att()//add a structure
{
    int k;
    cin>>str;
    scanf("%d",&k);
    s tmp;
    tmp.typname=str;
    for(int i=0;i<k;i++)
    {
    	cin>>str>>strn;
    	mem tmpm;
    	tmpm.type=ms[str];
    	tmpm.id=i;
    	tmpm.name=strn;
    	tmp.child2[tmpm.id]=tmpm.
    	tmp.l=max(tmp.l,structs[tmpm.type].l);
    	tmp.child[strn]=ms[tmpm.type];
    }
    tmp.len=k*tmp.l;
    ms[tmp.typname]=cnts;
    structs[cnts++]=tmp;
}
void mak()//make a val
{
    cin>>str>>strn;
    stak[cntv].typname=str;
    stak[cntv].name=strn;
    switch(cntv)
    {
        case 0: stak[cntv].llast=0;break;
        case 1: stak[cntv].llast=structs[ms[stak[cntv-1].typname]].len;break;
        default: stak[cntv].llast=structs[ms[stak[cntv-1].typname]].len+stak[cntv-1].llast;break;
    }
    mv[stak[cntv].name]=cntv;
    cntv++;
}
ll vis()
{
    getline(cin,str);
    ll nowl=0;
    s typ;
    for(ll i=0,j=str.find('.',0);j<str.length();i=j+1,j=str.find('.',j+1))
    {
        if(i==0)
        {
            nowl+=stak[mv[str.substr(i,j)]].llast;
            typ=structs[ms[stak[mv[str.substr(i,j)]].typname]];
        }
        else
        {
            nowl+=typ.child[str.substr(i,j)].id*typ.l;
            typ=structs[typ.child[str.substr(i,j)].type];
        }
    }
    return nowl+1;
}
int serwithl(ll len)
{
    int l=0,r=cnts,mid=(l+r)/2;
    while(r-l>1)
    {
        if(stak[mid].llast<len) l=mid;
        else r=mid;
        mid=(l+r)/2;
    }
    return l;
}
int serwithlins(int stru,ll len)
{
    len/=structs[stru].l;
    int l=0,r=structs[stru].len/structs[stru].l.mid=(l+r)/2;
    while(r-l>1)
    {
        if(structs[stru].child[mid].id<len) l=mid;
        else r=mid;
    }
    return l;
}
string ser()
{
    ll serl;
    scanf("%lld",&serl);
    int stru=serwithl(serl);
    string a=stak[stru].name;
    serl-=stak[stru].llast;
    stru=ms[stak[stru].typname];
    while(structs[stru].len>=serl)
    {
        if(stru<4)
        {
            return a;
        }
        int strut=serwithlins(stru,serl);
        serl-=structs[stru].child[strut].id*structs[stru].l;
        a=a+"."+structs[stru].child[strut].name;
        stru=strut;
    }
    return "ERR";
}
void opera(int op)
{
    if(op==1) att();
    if(op==2) mak();
    if(op==3) printf("%lld\n",vis());
    if(op==4) printf("%s\n",ser().c_str());
    return;
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int opt;
        scanf("%d",&opt);
        opera(opt);
    }
    return 0;
}