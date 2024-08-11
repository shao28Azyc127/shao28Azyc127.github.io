#include <bits/stdc++.h>
using namespace std;
struct k{
    string ty;
    string na;
};
int s[105];
vector<k>v[105];
string namee[105];
int id=1;
int g(int kk)
{
    int m=-1;
    for(int i=0;i<v[kk].size();i++)
    {
        if(v[kk][i].ty=="byte")
            m=max(m,1);
        else if(v[kk][i].ty=="short")
            m=max(m,2);
        else if(v[kk][i].ty=="int")
            m=max(m,4);
        else if(v[kk][i].ty=="long")
            m=max(m,8);
    }
    return m;
}
unsigned long long now=0;
struct o{
    unsigned long long st,l;
    string e;
};
vector<o>b;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string x;
            cin>>x;
            namee[id]=x;
            int n;
            cin>>n;
            for(int i=1;i<=n;i++)
            {
                string tmp1,tmp2;
                cin>>tmp1>>tmp2;
                v[id].push_back((k){tmp1,tmp2});
            }
            //cout<<v[id].size();
            cout<<n*g(id)<<" "<<g(id)<<endl;
            id++;

        }
        else if(op==2)
        {
            string noww,se;
            cin>>noww>>se;
            cout<<now<<endl;
            int f=0;
            for(int ii=1;ii<=id-1;ii++)
                if(namee[ii]==noww)
            {
                f=1;
                int u=g(ii);
                //cout<<")))"<<v[ii].size()<<endl;
                for(int i=0;i<v[ii].size();i++)
                {
                    //cout<<v[ii][i]<<endl;
                    if(v[ii][i].ty=="byte")
                        b.push_back((o){now,1,se+"."+v[ii][i].na});
                    if(v[ii][i].ty=="short")
                        b.push_back((o){now,2,se+"."+v[ii][i].na});
                    if(v[ii][i].ty=="int")
                        b.push_back((o){now,4,se+"."+v[ii][i].na});
                    if(v[ii][i].ty=="long")
                        b.push_back((o){now,8,se+"."+v[ii][i].na});
                    now+=u;

                }
            }
            if(f==0)
            {
                if(noww=="byte")
                {
                    b.push_back((o){now,1,se});
                    now+=1;
                }

                if(noww=="short")
                {
                    b.push_back((o){now,2,se});
                    now+=2;
                }

                if(noww=="int")
                {
                    b.push_back((o){now,4,se});
                    now+=4;
                }

                if(noww=="long")
                {
                    b.push_back((o){now,8,se});
                    now+=8;
                }

            }
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            if(s.find('.')!=string::npos)
            {
                for(int i=0;i<b.size();i++)
                {
                    //cout<<b[i].e<<endl;
                    if(b[i].e==s)
                {
                    cout<<b[i].st<<endl;
                    break;
                }
                }

            }
            else
            {
                for(int i=0;i<b.size();i++)
                if(b[i].e==s||b[i].e.find(s)!=string::npos)
                {
                    //cout<<b[i].e<<' '<<s;
                    cout<<b[i].st<<endl;
                    break;
                }
            }
        }
        else
        {
            unsigned long long addr;
            cin>>addr;
            int f=0;
            for(int i=0;i<b.size();i++)
                if(b[i].st<=addr&&b[i].st+b[i].l-1>=addr)
                {
                    cout<<b[i].e<<endl;
                    f=1;
                }
            if(f==0)cout<<"ERR"<<endl;
        }
    }
    return 0;
}


