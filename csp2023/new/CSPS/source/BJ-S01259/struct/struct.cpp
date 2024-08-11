#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
struct Type
{
    long long siz,sta;
    vector<string> ctyp,cname;
}typ[MAXN];
struct Class
{
    string name;
    long long l,r;
    vector<int> member;
}a[MAXN];
map<string,int> ty,ad;
int T,tcnt,acnt;
long long last;
vector<string> name;
void init()
{
    vector<string> e;
    e.empty();
    typ[++tcnt]=(Type){1,1,e,e},typ[++tcnt]=(Type){2,2,e,e},typ[++tcnt]=(Type){4,4,e,e},typ[++tcnt]=(Type){8,8,e,e};
    ty.insert(make_pair("byte",1)),ty.insert(make_pair("short",2)),ty.insert(make_pair("int",3)),ty.insert(make_pair("long",4));
}
void build(string t,string n,long long add)
{
    ad.insert(make_pair(n,++acnt));
    a[acnt].name=n,a[acnt].l=add,a[acnt].r=a[acnt].l+typ[ty[t]].siz;
    int cur=acnt;
    long long p=add;
    for(int i=0;i<typ[ty[t]].ctyp.size();i++)
    {
        p=ceil((double)p/typ[ty[typ[ty[t]].ctyp[i]]].sta)*typ[ty[typ[ty[t]].ctyp[i]]].sta;
        build(typ[ty[t]].ctyp[i],n+"."+typ[ty[t]].cname[i],p);
        p+=typ[ty[typ[ty[t]].ctyp[i]]].siz;
        a[cur].member.push_back(acnt);
    }
    return;
}
void query(int cur,long long add)
{
    if(a[cur].member.empty())
    {
        cout << a[cur].name << endl;
        return;
    }
    for(auto i=a[cur].member.begin();i!=a[cur].member.end();i++)
    {
        int nxt=*i;
        if(a[nxt].l<=add&&add<=a[nxt].r)
        {
            query(nxt,add);
            return;
        }
    }
    printf("ERR\n");
    return;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    init();
    scanf("%d",&T);
    for(int zyx=1;zyx<=T;zyx++)
    {
        int opt;
        cin >> opt;
        if(opt==1)
        {
            int k;
            string s,t,n;
            cin >> s >> k;
            ty.insert(make_pair(s,++tcnt));
            for(int i=1;i<=k;i++)
            {
                cin >> t >> n;
                typ[tcnt].sta=max(typ[tcnt].sta,typ[ty[t]].sta);
                typ[tcnt].ctyp.push_back(t),typ[tcnt].cname.push_back(n);
            }
            int o=0;
            for(int i=1;i<typ[tcnt].ctyp.size();i++)
            {
                o=ceil((double)(o+typ[ty[typ[tcnt].ctyp[i]]].siz)/typ[ty[typ[tcnt].ctyp[i]]].sta)*typ[ty[typ[tcnt].ctyp[i]]].sta;
            }
            typ[tcnt].siz=ceil((double)(o+typ[ty[typ[tcnt].ctyp[typ[tcnt].ctyp.size()-1]]].siz)/typ[tcnt].sta)*typ[tcnt].sta;
            printf("%lld %lld\n",typ[tcnt].siz,typ[tcnt].sta);
        }
        if(opt==2)
        {
            string t,n;
            cin >> t >> n;
            name.push_back(n);
            last=ceil((double)last/typ[ty[t]].sta)*typ[ty[t]].sta;
            printf("%lld\n",last);
            build(t,n,last);
            last+=typ[ty[t]].siz;
        }
        if(opt==3)
        {
            string n;
            cin >> n;
            printf("%lld\n",a[ad[n]].l);
        }
        if(opt==4)
        {
            long long addr;
            cin >> addr;
            bool flag=false;
            for(auto i=name.begin();i!=name.end();i++)
            {
                string p=*i;
                if(a[ad[p]].l<=addr&&addr<=a[ad[p]].r)
                {
                    query(ad[p],addr);
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                printf("ERR\n");
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
