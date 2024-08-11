#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct Str
{
    string strname;
    string name[110];
    string lx[110];
    int lxn[110];
    int lth;
    int k;
    int dq;
};
Str str[100010];
string f[2000010];
string f2[2000010];
int sz=0;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int mainpos=-1;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int k;
            sz++;
            cin>>str[sz].strname>>k;
            for(int i=1;i<=k;i++)
            {
                char c;
                cin>>str[sz].lx[i]>>str[sz].name[i];
                if(str[sz].lx[i]=="byte")
                {
                    str[sz].dq=max(str[sz].dq,1);
                    str[sz].lxn[i]=1;
                }
                if(str[sz].lx[i]=="long")
                {
                    str[sz].dq=max(str[sz].dq,8);
                    str[sz].lxn[i]=8;
                }
                if(str[sz].lx[i]=="short")
                {
                    str[sz].dq=max(str[sz].dq,2);
                    str[sz].lxn[i]=2;
                }
                if(str[sz].lx[i]=="int")
                {
                    str[sz].dq=max(str[sz].dq,4);
                    str[sz].lxn[i]=4;
                }
                str[sz].lth++;
            }
        }
        if(op==2)
        {
            string newname,lxname;
            cin>>lxname>>newname;
            if(lxname=="long")
            {
                for(int i=mainpos+1;i<=mainpos+8;i++)
                {
                    f2[i]=lxname;
                    f[i]=newname;
                }
                mainpos+=8;
                cout<<mainpos<<endl;
                continue;
            }
            if(lxname=="short")
            {
                for(int i=mainpos+1;i<=mainpos+2;i++)
                {
                    f2[i]=lxname;
                    f[i]=newname;
                }
                mainpos+=2;
                cout<<mainpos<<endl;
                continue;
            }
            if(lxname=="byte")
            {
                for(int i=mainpos+1;i<=mainpos+1;i++)
                {
                    f2[i]=lxname;
                    f[i]=newname;
                }
                mainpos+=1;
                cout<<mainpos<<endl;
                continue;
            }
            if(lxname=="int")
            {
                for(int i=mainpos+1;i<=mainpos+4;i++)
                {
                    f2[i]=lxname;
                    f[i]=newname;
                }
                mainpos+=4;
                cout<<mainpos<<endl;
                continue;
            }
            int pos=0;
            for(int i=1;i<=sz;i++)
            {

                if(str[i].strname==lxname)
                {
                    pos=i;
                    break;
                }
            }
            int sx=0,spos=mainpos;
            for(int i=mainpos+1;i<=mainpos+str[pos].lth*str[pos].dq;i++)
            {
                f2[i]=lxname;
                if(spos<i)
                {
                    sx++;
                    spos+=str[pos].dq;
                }
                if(spos-str[pos].dq+str[pos].lxn[sx]<=i)
                {
                    f[i]=newname;
                    f[i]+='.';
                    f[i]+=str[pos].name[sx];
                }
                else
                {
                    f[i]=="###";
                }
            }
            mainpos+=str[pos].lth*str[pos].dq;
            cout<<mainpos<<endl;
        }
        if(op==3)
        {
            string nname;
            cin>>nname;
            for(int i=0;i<=mainpos;i++)
            {
                if(f[i]==nname)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(op==4)
        {
            int add;
            cin>>add;
            if(f[add]!="###"&&add<=mainpos)cout<<f[add]<<endl;
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}