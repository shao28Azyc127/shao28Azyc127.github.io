#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> Stoi;
unordered_map<int,string> Itos;

int allcnt=0;

int geti(string s)
{
    if(Stoi[s]==0){Stoi[s]=++allcnt,Itos[allcnt]=s;return allcnt;}
    else return Stoi[s];
}

string gets(int i)
{
    return Itos[i];
}

string neicun[1000000];
int kj[114];
int dq[114];
int fp=0;
vector<pair<int,int> > lx[114];

void getnc(int leixin,int duiqi,string p)
{
    string nowlx=gets(leixin);
    if(nowlx=="byte"||nowlx=="short"||nowlx=="int"||nowlx=="long")
    {
        fp=(int)((ceil(fp*1.0/dq[leixin]))*dq[leixin]);
        for(int i=fp;i<fp+dq[leixin];i++)
        {
            neicun[i]=p;
        }
        fp+=dq[leixin];
        return;
    }
    string t;
    int l=lx[leixin].size();
    for(int i=0;i<l;i++)
    {
        auto v=lx[leixin][i];
        fp=(int)((ceil(fp*1.0/dq[v.first]))*dq[v.first]);
        t=p+('.'+gets(v.second));
        int ti=dq[v.first];
        if(v.first<5)ti=duiqi;
        getnc(v.first,ti,t);
        fp=(int)((ceil(fp*1.0/dq[v.first]))*dq[v.first]);
    }
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    dq[geti("byte")]=1;
    dq[geti("short")]=2;
    dq[geti("int")]=4;
    dq[geti("long")]=8;
    kj[geti("byte")]=1;
    kj[geti("short")]=2;
    kj[geti("int")]=4;
    kj[geti("long")]=8;
    for(int i=0;i<n;i++)
    {
        int px;
        cin>>px;
        if(px==1)
        {
            string s;
            cin>>s;
            int k;
            cin>>k;
            
            int si=geti(s);
            int cnt=0;
            int tfp=fp;
            for(int i=0;i<k;i++)
            {
                string x,y;
                cin>>x>>y;
                int xi=geti(x),yi=geti(y);
                tfp=(int)((ceil(tfp*1.0/dq[xi]))*dq[xi]);
                lx[si].push_back(make_pair(xi,yi));
                dq[si]=max(dq[si],dq[xi]);
                if(xi<5)tfp+=dq[xi];else tfp+=kj[xi];
            }
            tfp=(int)((ceil(tfp*1.0/dq[si]))*dq[si]);
            kj[si]+=tfp-fp;
            cout<<tfp-fp<<' '<<dq[si]<<'\n';
        }
        else if(px==2)
        {
            string x,y;
            cin>>x>>y;
            int xi=geti(x),yi=geti(y);
            string p=y;
            fp=(int)((ceil(fp*1.0/dq[xi]))*dq[xi]);
            cout<<fp<<'\n';
            getnc(xi,dq[xi],p);
            fp=(int)((ceil(fp*1.0/dq[xi]))*dq[xi]);
        }
        else if(px==3)
        {
            string s;
            cin>>s;
            bool b=1;
            for(int i=0;i<fp;i++)
                if(s==neicun[i])
                {
                    cout<<i<<'\n';
                    b=0;
                    break;
                }
            if(b)cout<<"0\n";
        }
        else if(px==4)
        {
            int x;
            cin>>x;
            if(neicun[x]=="")cout<<"ERR\n";
            else cout<<neicun[x]+'\n';
        }

        
    }
    /*cout<<"print neicun:\n";
        for(int i=0;i<fp;i++)cout<<neicun[i]<<'\n';
        cout<<"over\n";
    cout<<dq[geti("a")];*/
}