#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long int
using namespace std;
int typebasesiz[105]={0,1,2,4,8};
int typesiz[105]={0,1,2,4,8};
string typenames[105]={"","byte","short","int","long"};
int typid=4;
int n;
string belongs[10005];
int belong[10005];
struct strtype
{
    int typ,startpos;
    string name;
    strtype() {typ=startpos=0,name="";}
};
struct str
{
    int k,siz,basesiz,id;
    string name;
    strtype ks[105];
    str() {k=siz=basesiz=id=0,name="";}
    void calcsiz()
    {
        int maxx=0;
        for(int i=1;i<=k;i++)
            if(typebasesiz[ks[i].typ]>typebasesiz[maxx])
                maxx=ks[i].typ;
        basesiz=typebasesiz[maxx];
        //*
        siz=0;
        for(int i=1;i<=k;i++)
        {
            int nowbase=typebasesiz[ks[i].typ];
            if(siz%nowbase>0)
                siz=(siz/nowbase+1)*nowbase;
            siz+=typesiz[ks[i].typ];
        }
        if(siz%basesiz>0)
            siz=(siz/basesiz+1)*basesiz;
        /*/
        siz=k*basesiz;
        //*/
        for(int i=1;i<=k;i++)
        {
            ks[i].startpos=(i-1)*basesiz;
        }
        return;
    }
    int findvaria(string name)
    {
        for(int i=1;i<=k;i++)
            if(ks[i].name==name)
                return i;
        return 0;
    }
};
str types[105];
void calcbelong(int startpos,int typ)
{
    for(int i=1;i<=types[typ].k;i++)
    {
        for(int j=startpos+types[typ].ks[i].startpos;
            j<startpos+types[typ].ks[i].startpos+typesiz[types[typ].ks[i].typ];j++)
        {
            belongs[j]+='.';
            belongs[j]+=types[typ].ks[i].name;
            if(types[typ].ks[i].typ<=4)
                belong[j]=1;
        }
        if(types[typ].ks[i].typ>4)
            calcbelong(startpos+types[typ].ks[i].startpos,
                types[typ].ks[i].typ);
    }
    return;
}
struct varia
{
    int typ,startpos;
    string name;
    varia() {typ=startpos=0,name="";}
    void calcbelongs()
    {
        for(int i=startpos;i<startpos+typesiz[typ];i++)
        {
            belongs[i]+=name;
            if(typ<=4)
                belong[i]=1;
        }
        if(typ>4)
            calcbelong(startpos,typ);
    }
};
varia varias[105];
int vs;
int used;
int findvaria(string name)
{
    for(int i=1;i<=vs;i++)
        if(varias[i].name==name)
            return i;
    return 0;
}
void printtype(int x)
{
    cout << "type " << typenames[x] << ":\n";
    for(int i=1;i<=types[x].k;i++)
    {
        cout << "  " << typenames[types[x].ks[i].typ] << ' '
            << types[x].ks[i].name << ", startpos="
            << types[x].ks[i].startpos << endl;
    }
}
void printvaria(int x)
{
    cout << "varia " << typenames[varias[x].typ] <<
    ' ' << varias[x].name << ":\n";

}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int opt;
        cin >> opt;
        if(opt==1)
        {
            typid++;
            cin >> types[typid].name >> types[typid].k;
            typenames[typid]=types[typid].name;
            for(int j=1;j<=types[typid].k;j++)
            {
                string typ;
                cin >> typ >> types[typid].ks[j].name;
                for(int i=1;i<=typid;i++)
                    if(typenames[i]==typ)
                    {
                        types[typid].ks[j].typ=i;
                        break;
                    }
            }
            types[typid].calcsiz();
            typebasesiz[typid]=types[typid].basesiz;
            typesiz[typid]=types[typid].siz;
            cout << typesiz[typid] << ' ' << typebasesiz[typid] << endl;
        }
        if(opt==2)
        {
            vs++;
            string typ;
            cin >> typ >> varias[vs].name;
            for(int i=1;i<=typid;i++)
                if(typenames[i]==typ)
                {
                    varias[vs].typ=i;
                    break;
                }
            varias[vs].startpos=used;
            used+=typesiz[varias[vs].typ];
            varias[vs].calcbelongs();
            cout << varias[vs].startpos << endl;
        }
        if(opt==3)
        {
            string s;
            cin >> s;
            int ans=0;
            for(int i=0;i<used;i++)
                if(belongs[i]==s)
                {
                    ans=i;
                    break;
                }
            cout << ans << endl;
        }
        if(opt==4)
        {
            int x;
            cin >> x;
            cout << (belong[x]?belongs[x]:"ERR") << endl;
        }
    }
    /*
    for(int i=0;i<used;i++)
        cout << belong[i] << ' ' << belongs[i] << endl;
    //*/
    return 0;
}
