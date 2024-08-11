#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=10005;
int N;
struct Ele
{
    int ty;
    string s;
    LL l,r;
    int fa;
}e[MAXN];
struct Stru
{
    int K;
    LL m;
    int md;
    string s;
    vector<Ele>v;
}st[MAXN];
struct Struc
{
    int ty;
    string s;
    vector<int>ve;
    LL l,r;
}str[MAXN];
int etot=0,stot=0,srot=0;
LL mem=0;
LL m;
map<string,int>mp;
map<string,int>emp;
map<string,int>smp;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&N);
    while(N--)
    {
        int opt;
        scanf("%d",&opt);
       // puts("------");
        if(opt==1)
        {
            LL m=0;
            int md=1;
            stot++;
            string str;
            cin>>str;
            st[stot].s=str;
            scanf("%d",&st[stot].K);
           // cout<<str<<st[stot].K<<endl;
            for(int i=1;i<=st[stot].K;i++)
            {
                char ch[15];
                string n;
                cin>>ch;
                cin>>n;
                if(ch[0]=='b')
                {
                    if(m) m++;
                   // m++;
                    st[stot].v.push_back({1,n,0,0,0});
                }
                if(ch[0]=='s')
                {
                    if(m) m+=(2-(m%2));
                    md=max(md,2);
                    st[stot].v.push_back({2,n,0,1,0});
                    m++;
                }
                if(ch[0]=='i')
                {
                    if(m) m+=(4-(m%4));
                    md=max(md,4);
                    st[stot].v.push_back({4,n,0,3,0});
                    m+=3;
                }
                if(ch[0]=='l')
                {
                    if(m) m+=(8-(m%8));
                    md=max(md,8);
                    st[stot].v.push_back({8,n,0,7,0});
                    m+=7;
                }
            }
            mp[str]=stot;
            st[stot].m=m,st[stot].md=md;
            printf("%lld %d\n",m-1,md);
        }
        if(opt==2)
        {
            string s;
            string t;
            cin>>s>>t;
            if(mp.count(s))
            {
               // puts("!!!");
                srot++;
                Stru j=st[mp[s]];
                if(mem) mem+=(j.md-(mem%j.md));
                str[srot].l=mem;
                printf("%lld\n",mem);
                bool fir=1;
                for(Ele k:j.v)
                {
                    if(!fir) mem+=(k.ty-(mem%k.ty));
                    fir=0;
                    e[++etot]={k.ty,k.s,k.l+mem,k.r+mem,srot};
                    mem+=k.r;
                    str[srot].ve.push_back(etot);
                }
                mem+=j.m;
                str[srot].s=t;
                str[srot].r=mem;
                smp[t]=srot;
                continue;
            }
          //  puts("Get");
            emp[t]=etot+1;
            if(s[0]=='b')
            {
                if(mem) mem++;
                printf("%lld\n",mem);
                e[++etot]={1,t,mem,mem,0};
            }
            if(s[0]=='s')
            {
                if(mem) mem+=(2-(m%2));
                printf("%lld\n",mem);
                e[++etot]={2,t,mem,mem+1,0};
                mem++;
            }
            if(s[0]=='i')
            {
                if(mem) mem+=(4-(m%4));
                printf("%lld\n",mem);
                e[++etot]={4,t,mem,mem+3,0};
                mem+=3;
            }
            if(s[0]=='l')
            {
                if(mem) mem+=(8-(m%8));
                printf("%lld\n",mem);
                e[++etot]={8,t,mem,mem+7,0};
                mem+=7;
            }
           // printf("MEM%lld\n",mem);
        }
        if(opt==3)
        {
            string s;
            cin>>s;
            int dot=0;
            for(int i=0;i<s.length();i++) if(s[i]=='.') dot=i;
            if(!dot)
            {
                if(smp.count(s))
                {
                    printf("%lld\n",str[smp[s]].l);
                    continue;
                }
                int i=emp[s];
                printf("%lld\n",e[i].l);
                continue;
            }
            string s1,s2;
            s1.resize(dot);
            for(int i=0;i<dot;i++) s1[i]=s[i];
            s2.resize(s.length()-dot-1);
            for(int i=0;i<s.length()-dot-1;i++) s2[i]=s[i+dot+1];
       //     cout<<dot<<' '<<s1<<' '<<s2<<endl;
            Struc i=str[smp[s1]];
            for(int k:i.ve)
            {
                Ele j=e[k];
                if(j.s==s2)
                {
                    printf("%lld\n",j.l);
                    break;
                }
            }
        }
        if(opt==4)
        {
            LL m;
            scanf("%lld",&m);
         //   printf("!!!%d\n",m);
            bool flag=0;
            for(int i=1;i<=etot;i++)
            {
                if(e[i].l<=m&&e[i].r>=m)
                {
                    if(e[i].fa) cout<<str[e[i].fa].s<<'.';
                    cout<<e[i].s<<endl;
                    flag=1;
                    break;
                }
            }
            if(!flag) cout<<"ERR"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}