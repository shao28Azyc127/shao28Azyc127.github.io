#include<bits/stdc++.h>
using namespace std;
struct tp
{
    string name;
    string type;
    tp(){name=type="";}
    tp(string s,string t)
    {type=s;name=t;}
};
long long addr=0;
map<long long,string>memo;
map<string,long long>omem;
map<string,vector<tp> >mem;
map<string,long long>siz;
map<string,string>var;
long long read()
{
    long long x=0;
    char ch=' ';
    while(!isdigit(ch))
        ch=getchar();
    while(isdigit(ch))
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x;
}
string reas()
{
    char ch=' ';
    while(!isalnum(ch))
        ch=getchar();
    string s="";
    while(isalnum(ch))
    {s+=ch;ch=getchar();}
    return s;
}
void write(string s)
{
    for(int i=0;i<s.length();++i)
        putchar(s[i]);
}
void alocat(vector<tp>s,string Tp,string path)
{
    for(int i=0;i<s.size();++i)
    {
        if(s[i].type=="byte" or s[i].type=="int" or s[i].type=="short" or s[i].type=="long")
        {
            memo[addr]=path+"."+s[i].name;
            omem[path+"."+s[i].name]=addr;
            //cout<<path+"."+s[i].name<<';'<<addr<<endl;
            addr+=siz[Tp]/mem[Tp].size();
        }
        else alocat(mem[s[i].type],s[i].type,path+"."+s[i].name);
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    siz["byte"]=1;siz["short"]=2;
    siz["int"]=4;siz["long"]=8;
    int t;cin>>t;while(t--)
    {
        int op=read();
        if(op==1)
        {
            string nd;cin>>nd;
            long long sz=-1;
            int am=read();
            for(int i=0;i<am;++i)
            {
                string nm,tt;cin>>tt>>nm;
                mem[nd].push_back(tp(tt,nm));
                sz=max(sz,siz[tt]);
            }
            siz[nd]=sz*am;
            printf("%lld %lld",siz[nd],sz);
        }
        else if(op==2)
        {
            printf("%lld",addr);
            string tt=reas(),nn=reas();
            var[nn]=tt;alocat(mem[tt],tt,nn);
        }
        else if(op==3)
        {
            string ss;cin>>ss;
            printf("%lld",omem[ss]);
        }
        else
        {
            long long ad=read();
            write(memo[ad]);
        }
        putchar('\n');
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
