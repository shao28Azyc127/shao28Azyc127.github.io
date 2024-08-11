#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define maxq 100
int q,cnt=4,vc=0,apos=0;
struct Struct
{
    #define maxk 100
    int k,size,msize;
    int t[maxk+100];
    string s;
    string n[maxk+100];
}str[maxq+100];
struct Var
{
    int spos,type;
    string name;
}var[maxq+100];
int find(string x)
{
    for(int i=0;i<cnt;i++)
        if(x==str[i].s)return i;
    return -1;
}
vector<string>split(string x)
{
    vector<string>res;
    string p="";
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='.')
        {
            res.push_back(p);
            p="";
        }
        else p=p+x[i];
    }
    res.push_back(p);
    return res;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    str[0].s="byte";
    str[0].size=1;
    str[1].s="short";
    str[1].size=2;
    str[2].s="int";
    str[2].size=4;
    str[3].s="long";
    str[3].size=8;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int op;
        string x;
        cin>>op;
        if(op==1)
        {
            cin>>str[cnt].s>>str[cnt].k;
            for(int i=0;i<str[cnt].k;i++)
            {
                cin>>x>>str[cnt].n[i];
                str[cnt].t[i]=find(x);
                str[cnt].msize=max(str[cnt].msize,str[str[cnt].t[i]].size);
            }
            str[cnt].size=str[cnt].k*str[cnt].msize;
            cout<<str[cnt].size<<" "<<str[cnt].msize<<"\n";
            cnt++;
        }
        else if(op==2)
        {
            cin>>x>>var[vc].name;
            var[vc].spos=apos;
            var[vc].type=find(x);
            apos+=str[var[vc].type].size;
            cout<<var[vc].spos<<"\n";
            vc++;
        }
        else if(op==3)
        {
            cin>>x;
            vector<string>res=split(x);
            int strp=-1,ansp=-1;
            for(int i=0;i<vc;i++)
                if(var[i].name==res[0])
                {
                    strp=var[i].type;
                    ansp=var[i].spos;
                    break;
                }
            for(int i=1;i<res.size();i++)
            {
                for(int j=0;j<str[strp].k;j++)
                    if(res[i]==str[strp].n[j])
                    {
                        ansp+=str[strp].msize*j;
                        strp=str[strp].t[j];
                        break;
                    }
            }
            cout<<ansp<<"\n";
        }
        else if(op==4)
        {
            string ans="";
            int p,vp=-1;
            cin>>p;
            for(int i=0;i<vc;i++)
                if(p>=var[i].spos&&p<var[i].spos+str[var[i].type].size)
                {
                    ans+=var[i].name+'.';
                    vp=var[i].type;
                    p-=var[i].spos;
                    break;
                }
            if(vp<0)cout<<"ERR\n";
            else
            {
                while(vp>3)
                {
                    for(int i=0;i<str[vp].k;i++)
                        if(p>=str[vp].msize*i&&p<str[vp].msize*(i+1))
                        {
                            p-=str[vp].msize*i;
                            ans+=str[vp].n[i]+'.';
                            vp=str[vp].t[i];
                            break;
                        }
                }
                cout<<ans.substr(0,ans.length()-1)<<"\n";
            }
        }
    }
    return 0;
}