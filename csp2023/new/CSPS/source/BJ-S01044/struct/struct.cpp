#include<bits/stdc++.h>
using namespace std;
int n,op;
long long now;
struct typadd
{
    long long pl,pr;
};
struct typnme
{
    int lth,a;
    long long siz;
    string type[105];
    string name[105];
};
map<string,bool>ist;
map<string,typnme>str;
map<string,typadd>mp;
struct typ
{
    long long pl,pr;
    string name;
}ad[10005];
int cnt;
void find(long long add)
{
    int l=0,r=cnt+1;
    while(r-l>1)
    {
        int mid=l+r>>1;
        if(ad[mid].pl<=add)l=mid;
        else r=mid;
    }
    if(ad[l].pr<add)
    {
        printf("ERR");
    }else{
        cout<<ad[l].name;
    }
}
template<typename T>
inline void cal(T &res,int a)
{
    if(res%a!=0)res+=a-res%a;
}
void insert(string typ,string nme)
{
    int a=str[typ].a;
    cal(now,a);
    if(ist[typ]==0)
    {
        int lenth=str[typ].lth;
        for(int i=1;i<=lenth;i++)
        {
            insert(str[typ].type[i],nme+"."+str[typ].name[i]);
        }
    }
    else
    {
        int siz=str[typ].a;
        mp[nme].pl=now;
        mp[nme].pr=now+siz-1;
        cnt++;
        ad[cnt].pl=now;
        ad[cnt].pr=now+siz-1;
        ad[cnt].name=nme;
        now+=siz;
    }
    cal(now,a);
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    ist["byte"]=1;
    ist["short"]=1;
    ist["int"]=1;
    ist["long"]=1;
    str["byte"].a=1;
    str["short"].a=2;
    str["int"].a=4;
    str["long"].a=8;
    str["byte"].siz=1;
    str["short"].siz=2;
    str["int"].siz=4;
    str["long"].siz=8;
    str["byte"].lth=1;
    str["short"].lth=1;
    str["int"].lth=1;
    str["long"].lth=1;
    while(n--)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                {
                    string name,tp[105],na[105];
                    int k,ad=0;
                    long long sze=0;
                    cin>>name;
                    scanf("%d",&k);
                    for(int i=1;i<=k;i++)
                    {
                        cin>>tp[i]>>na[i];
                        str[name].name[i]=na[i];
                        str[name].type[i]=tp[i];
                        ad=max(ad,str[tp[i]].a);
                        long long sz=str[tp[i]].siz;
                        cal(sze,str[tp[i]].a);
                        sze+=sz;
                    }
                    str[name].lth=k;
                    str[name].a=ad;
                    cal(sze,ad);
                    str[name].siz=sze;
                    printf("%lld %d\n",str[name].siz,str[name].a);
                    break;
                }
            case 2:
                {
                    string tp,na;
                    cin>>tp>>na;
                    cal(now,str[tp].a);
                    printf("%lld\n",now);
                    insert(tp,na);
                    break;
                }
            case 3:
                {
                    string s;
                    cin>>s;
                    printf("%lld\n",mp[s].pl);
                    break;
                }
            case 4:
                {
                    long long addr;
                    scanf("%lld",&addr);
                    find(addr);
                    putchar('\n');
                    break;
                }
            break;
        }
    }
    return 0;
}
